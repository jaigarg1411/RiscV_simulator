/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

The project is developed as part of Computer Architecture class
Project Name: Functional Simulator for subset of RISCV Processor => Phase2 (5 stages)

Developers' Name: 	Kamal Sharma (2017csb1084)
					Nitin (2017csb1093)
					Piyush Lodhi (2017csb1097)
					Jai Garg (2017csb1081)
					Kapil Dev (2017csb1085)

Date: 27 March, 2019

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <bits/stdc++.h>
#include "memoryclass.h"
#include "phase2.h"
using namespace std;


string phase2::to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}


int phase2::bintodec(string s)
{
	int val=0,index=0,i;
	for(i=s.length()-1;i>=0;i--)
	{
		if(s[i] == '1')
			val += pow(2,index);
		index++;
	}
	return val;
}


// 2s compliment for negative immidiates
string phase2::findTwoscomplement(string str) 
{ 
    int n = str.length(); 
    int i; 
    for (i = n-1 ; i >= 0 ; i--) 
        if (str[i] == '1') 
            break; 
    if (i == -1) 
        return '1' + str; 
    for (int k = i-1 ; k >= 0; k--) 
    { 
        if (str[k] == '1') 
            str[k] = '0'; 
        else
            str[k] = '1'; 
    } 
    return str;; 
} 

int phase2::bintodec_negative(string s)
{
	string str = findTwoscomplement(s);
	int res = bintodec(str);
	res = 0-res;
	return res;
}


string phase2::hextobin(string inst)
{
     stringstream ss;
     ss << hex << inst;
     unsigned n;
     ss >> n;
     bitset<32> b(n);
     string s = b.to_string();
     return s;
}



//Part of control unit => generators all ALU,  MUXes and Memory signals

int phase2::set_signal(int opcode,int funct3,int funct7)
{
	if(opcode == 51 || opcode == 59)
	{
		signal_memoryaccess = 0;
		if(funct7 == 0)
		{
			if(funct3 == 0)
				return 1;
			else if(funct3 == 1)
				return 7;
			else if(funct3 == 2)
				return 5;
			else if(funct3 == 3)
				return 12;
			else if(funct3 == 4)
				return 10;
			else if(funct3 == 5)
				return 6;
			else if(funct3 == 6)
				return 9;
			else if(funct3 == 7)
				return 8;
		}
		else if(funct7 == 32)
		{
			if(funct3 == 0)
				return 2;
			else if(funct3 == 5)
				return 13;
		}
		else if(funct7==1)
		{
			if(funct3==0)
				return 4;
			else if(funct3==4)
				return 3;
		}
	}
	else if(opcode == 3)
	{
		signal_memoryaccess = 1;
		if(funct3==0)
			word_byte=0;
		else
		{
			word_byte=1;
		}
		
		mem_wr=0;
		return 1;
	}
	else if(opcode == 19 || opcode == 27)
	{
        signal_memoryaccess = 0;
		if(funct3 == 0)
			return 1;
		else if(funct3 == 1)
			return 7;
		else if(funct3 == 2)
			return 5;
		else if(funct3 == 3)
			return 12;
		else if(funct3 == 4)
			return 10;
		else if(funct3 == 6)
			return 9;
		else if(funct3 == 7)
			return 8;
		else if(funct3 == 5 && funct7 == 0)
			return 6;
		else if(funct3 == 5 && funct7 == 32)
			return 13;
	}
	else if(opcode == 35)
	{
		signal_memoryaccess = 1;
		mem_wr=1;
		return 1;
	}
	else if(opcode == 99)
	{
        signal_memoryaccess = 0;
		if(funct3 == 0 || funct3 == 1 || funct3 == 4 || funct3 == 5)
			return 5;
		else if(funct3 == 6 || funct3 == 7)
			return 12;
	}
	else if(opcode == 103)
	{
		signal_memoryaccess = 0;
		return 1;
	}
	else if(opcode == 0)
	{
		signal_memoryaccess = 0;
		return 1;

	}
	return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Fetch stage /////////////////////////////////////////////////////////////

void phase2::fetch()
{
	//cout<<"pc --------------> "<<pc<<endl;
	int k=pc/4;
	IR = instructions_bin[k]; // instruction is stored in vector in driver code
	pc=pc+4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Decode stage ////////////////////////////////////////////////////////////

// decode function is also responsible for MUXB implimentation
void phase2::decode()
{
	string op_str,rd_str,funct3_str,rs1_str,rs2_str,funct7_str,ImmiSubstring;
	op_str = IR.substr(25,31); // last 7 bits are dedicated for opcode
	int rs1,rs2;
	int opcode,funct3,funct7;
	opcode = bintodec(op_str);		//opcode in decimal form

	int RA=0,RB=0,immidiate=0;
	is_jump=0;
	if(opcode==17) // exit in case of swi 0x11 instruction
	{
		exit_signal=1;
		return;
	}

	else if(opcode == 51 || opcode == 59) // for R format
	{
		rd_str = IR.substr(20,5);
		rs1_str = IR.substr(12,5);
		rs2_str = IR.substr(7,5);
		funct7_str = IR.substr(0,7);
		funct3_str = IR.substr(17,3);
		rd = bintodec(rd_str);
		funct3 = bintodec(funct3_str);
		rs1 = bintodec(rs1_str);
		rs2 = bintodec(rs2_str);
		funct7 = bintodec(funct7_str);
		RA = register_file[rs1];
		RB = register_file[rs2];
		signal_ALU = set_signal(opcode,funct3,funct7);		//arithmetic operator
        regw_signal=1;
	}
	else if(opcode == 3 || opcode == 15 || opcode == 19 || opcode == 27 || opcode == 103) // for I format
	{
		int temp1,temp2,p=0;
		rd_str = IR.substr(20,5);
		funct3_str = IR.substr(17,3);
		rs1_str = IR.substr(12,5);
		ImmiSubstring = IR.substr(0,12);
		rd = bintodec(rd_str);
		funct3 = bintodec(funct3_str);
		rs1 = bintodec(rs1_str);
		if(ImmiSubstring[0]=='0')
			immidiate = bintodec(ImmiSubstring);
		else
			immidiate = bintodec_negative(ImmiSubstring);
		RA = register_file[rs1];
		signal_ALU = set_signal(opcode,funct3,funct7);		//arithmetic operator
        regw_signal=1;
        if(opcode==103)
        	is_jump=3;
	}
	else if(opcode == 35)//S
	{
		//cout<<"insw\n";
		funct3_str = IR.substr(17,3);
		rs1_str = IR.substr(12,5);
		rs2_str = IR.substr(7,5);
		string temp,temp1;
		temp = IR.substr(20,5);
		temp1 = IR.substr(0,7);
		ImmiSubstring = temp1 + temp;
		funct3 = bintodec(funct3_str);
		rs1 = bintodec(rs1_str);
		rs2 = bintodec(rs2_str);
		if(ImmiSubstring[0]=='0')
			immidiate = bintodec(ImmiSubstring);
		else
			immidiate = bintodec_negative(ImmiSubstring);
		RA = register_file[rs1];
		RB = register_file[rs2];
		RM = RB;
		signal_ALU = set_signal(opcode,funct3,funct7);	//arithmetic operator
        regw_signal=0;
	}
	else if(opcode == 99) // for conditional branching i.e. SB format
	{
		funct3_str = IR.substr(17,3);
		rs1_str = IR.substr(12,5);
		rs2_str = IR.substr(7,5);
		string temp,temp1,temp2,temp3;
		temp = IR.substr(0,1);
		temp1 = IR.substr(24,1);
		temp2 = IR.substr(1,6);
		temp3 = IR.substr(20,4);
		ImmiSubstring = temp + temp1 + temp2 + temp3; // rearranging immidiates bits
		ImmiSubstring.append("0");
		funct3 = bintodec(funct3_str);
		rs1 = bintodec(rs1_str);
		rs2 = bintodec(rs2_str);
		if(ImmiSubstring[0]=='0')
			immidiate = bintodec(ImmiSubstring);
		else
			immidiate = bintodec_negative(ImmiSubstring);
		RA = register_file[rs1];
		RB = register_file[rs2];
		signal_ALU = set_signal(opcode,funct3,funct7);		//arithmetic operator
		b_offset=immidiate;
		//cout<<"offset "<<b_offset<<endl;
        regw_signal=0;
        is_jump=1;
        cond_branch_type=funct3;
	}
	else if(opcode == 55)	// U format
	{
		rd_str = IR.substr(20,5);
		ImmiSubstring = IR.substr(0,20);
		rd = bintodec(rd_str);
		immidiate = bintodec(ImmiSubstring);
		immidiate *= 4096;
		signal_memoryaccess = 1;		// access to memory
	}
	else if(opcode == 111) // for unconditional jumps i.e UJ format
	{
		rd_str = IR.substr(20,5);
		string temp,temp1,temp2,temp3;
		temp = IR.substr(0,1);
		temp1 = IR.substr(1,10);
		temp2 = IR.substr(11,1);
		temp3 = IR.substr(12,8);
		ImmiSubstring = temp + temp3 + temp2 + temp1 + "0";
		rd = bintodec(rd_str);
		if(ImmiSubstring[0]=='0')
			immidiate = bintodec(ImmiSubstring);
		else
			immidiate = bintodec_negative(ImmiSubstring);
		signal_ALU = set_signal(opcode,funct3,funct7);	
		b_offset=immidiate;
		RZ=pc;
        regw_signal=1;
		signal_memoryaccess = 0;
		is_jump=2;
	}
	else if(opcode==0) // la instruction (pseudo instruction)
	{
		rd_str=IR.substr(20,5);
		ImmiSubstring=IR.substr(0,20);
	    if(ImmiSubstring[0]=='0')
			immidiate = bintodec(ImmiSubstring);
		else
			immidiate = bintodec_negative(ImmiSubstring);
		rd=bintodec(rd_str);
		signal_ALU = set_signal(opcode,funct3,funct7);
		regw_signal=1;
	}

	ALU_input1 = RA;
	if(opcode==0)
		ALU_input1=0;

///////////////////////////////////////////////// MUXB ////////////////////////////////////////////////////////
	if(opcode==99 || opcode == 51 || opcode == 59)
		ALU_input2=RB;
	else
		ALU_input2=immidiate;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Execute stage ////////////////////////////////////////////////////////////

	/*
		0. Default nothing to do.
		1. Add
		2. Subtract
		3. Divide
		4. Multiply
		5. Compare (Set result compare:- -1 for input1 < input2; 1 for input1 > input2; 0 for input1 = input2)
		6. Shift bits right
		7. Shift bits left
		8. AND
		9. OR
		10. XOR
		11. NOT
		12. Unsigned comparison
		13. Arithmetic Shift Right
	*/

void phase2::execute()
{
	int compare=-2;

	switch(signal_ALU)
	{
		case 0:break;
		case 1:
			RZ = ALU_input1 + ALU_input2;
			break;
		case 2:
			RZ = ALU_input1 - ALU_input2;
			break;
		case 3:
			RZ = ALU_input1/ALU_input2;
			break;
		case 4:
			RZ = ALU_input1*ALU_input2;
			break;
		case 5:
			if(ALU_input1<ALU_input2)
				compare = -1;
			else if(ALU_input1>ALU_input2)
				compare = 1;
			else
				compare = 0;
			break;
		case 6:
			RZ = ALU_input1/pow(2,ALU_input2);
			break;
		case 7:
			RZ = ALU_input1*pow(2,ALU_input2);
			break;
		case 8:
			RZ = ALU_input1 & ALU_input2;
			break;
		case 9:
			RZ = ALU_input1 | ALU_input2;
			break;
		case 10:
			RZ = ALU_input1 ^ ALU_input2;
			break;
		case 11:
			RZ = ~ ALU_input1;
			break;
		case 12:
			if(ALU_input1<ALU_input2)
				compare = -1;
			else if(ALU_input1>ALU_input2)
				compare = 1;
			else
				compare = 0;
			break;
			break;
		case 13:
			RZ = ALU_input1>>ALU_input2;
			break;
	}
	if(is_jump==2)   // enter in case of uncondition branch only
		pc=pc+b_offset-4;
	else if(is_jump==1)// for conditional branch
	{
		/*
			0. beq
			1. bne
			4. blt
			5. bge
			6. bltu
			7. bgeu
		*/
		switch(cond_branch_type)
		{
			case 0:
				if(compare==0)
				    pc=pc+b_offset-4;
				break;
			case 1:
				if(compare!=0)
				    pc=pc+b_offset-4;
				break;
			case 4:
				if(compare==-1)
				    pc=pc+b_offset-4;
				break;
			case 5:
				if(compare==1 || compare==0)
				    pc=pc+b_offset-4;
				break;
			case 6:
				if(compare==-1)
				    pc=pc+b_offset-4;
				break;
			case 7:
				if(compare==1 || compare==0)
					pc=pc+b_offset-4;
				break;
            default:
                b_offset=0;
		}
	}
    else if(is_jump==3)  //  for "jalr" assing pc+4 in register_file  (103 is opcode of"jalr")
	{
        if(rd)
			register_file[rd]=pc+4;
        pc=RZ;
	}
	b_offset=0;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Memory stage /////////////////////////////////////////////////////////////

void phase2::mem(memoryclass *ob)    			// ".data" part and memory write is handled in memoryclass.cpp file
{
	int rowi,colj,i1,loop_exit=0,b;
	int MUXY_signal=0;

	if(word_byte == 0)
	     i1 = 2;
    else 
	    i1 = 8;
	
	rowi=RZ/4;
	char a[i1+1];
    string as="0x";
	int j=1;
	colj=(RZ%4)*2;
	if(signal_memoryaccess==1)
	{
		//cout<<"is_jump="<<is_jump<<endl;
		if(mem_wr==1) // write in memory
		{
            ob->mem_row=rowi;
            ob->mem_column=colj;
			string rm=to_string(RM);
			ob->write_mem(rm,i1);   // write in memory is done in "write_mem(string,int)" function in memoryclass.cpp 
		}
		else if(mem_wr==0) // read from memory
		{
			while(1)
			{
				while(colj<=7)
				{
					a[i1-j-1]=ob->memory[rowi][colj];
					colj++;
					a[i1-j]=ob->memory[rowi][colj];
					j=j+2;
                    colj++;
					if(j>=i1+1)
					{
						loop_exit=1;
						break;
					}
				}
				colj=0;
				if(loop_exit==1)
					break;
				rowi++;
			}
            a[i1]='\0';
            string as_full=as+a;
            string s=hextobin(as_full);
            b = bintodec(s);

            if(is_jump==3) // for "jalr"
                pc=b;
            else 
                MUXY_signal=1;	
		}
	}

	/////////////////////////////// MUXY ////////////////////////////////////
	if(MUXY_signal==0)
		RY=RZ;
	else if(MUXY_signal==1)
		RY=b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// Write back stage ///////////////////////////////////////////////////////////
void phase2::write()
{
	if( regw_signal==1 && rd!=0 )  // x0 is always zero
	{
		register_file[rd]=RY;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Driver code //////////////////////////////////////////////////////////////

phase2::phase2()
{
	memoryclass obj_mem_class1;
	obj_mem_class1.memory_handling();
	register_file[0]=0;			// x0 = 0
	register_file[2]=sp*4;		// x2 as stack pointer
	vector<string> program_counter;
	vector<string> instructions_hexa;
	string s1,s2;
	ifstream input("machine_code.txt");      // generated in phase1 as output
	while(input>>s1>>s2)
	{
	    if( (s1[0] == '\0') || (s2[0] == '\0') )
	    	break;
	    program_counter.push_back(s1);
	    instructions_hexa.push_back(s2);
	}
	for(int i=0;i<program_counter.size();i++)
	{
		string s = hextobin(instructions_hexa[i]);
		instructions_bin.push_back(s);			//array of instruction  in binary string form
		string s1 = hextobin(program_counter[i]);
		int a = bintodec(s1);
		program_counter_deci.push_back(a);		//array of program counter in decimal form
	}

	while(1)
	{
		fetch();
		decode();
	   	if(exit_signal==1) 		// "0xEF000011" case => swi 0x11 => exit case
	   		break;
		execute();
		mem(&obj_mem_class1);
		write();
		totalcycles++;
	}

	// Print all registers
	cout<<"\nRegisters : \n\n";
    for( int itertor=0 ; itertor<32 ; itertor++ )
		cout << "x" << itertor << " :\t" << register_file[itertor] << endl;
	

	for(int i=0;i<50;i++)
	{
		for(int j=0;j<8;j++)
			cout<<obj_mem_class1.memory[i][j];
		cout<<endl;
	}


}

int phase2:: TOTALCYCLES()
{
	return totalcycles;
}
