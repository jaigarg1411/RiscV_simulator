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
#include "phase3.h"
using namespace std;


string phase3::to_string(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

char phase3::search_in_queue(int regis)
{
	if(regis==0 || regis == -1)
		return 'N';
	int len = hazard_rd.size();
	char initial_forward = 'N'; // if no dependency
	cycle_diff=2;
	save_cycle_diff=-1;
	while(len--)
	{
		if(hazard_rd.front().first==regis)
		{
			save_cycle_diff=cycle_diff;
			initial_forward = hazard_rd.front().second;
		}
		hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
		hazard_rd.pop();
		cycle_diff--;
	}

	//cout<<" ("<<save_cycle_diff<<") ";
	return initial_forward;
}



// convert binary string to decimal
int phase3::bintodec(string s)
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
string phase3::findTwoscomplement(string str) 
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

int phase3::bintodec_negative(string s)
{
	string str = findTwoscomplement(s);
	int res = bintodec(str);
	res = 0-res;
	return res;
}


string phase3::hextobin(string inst)
{
     stringstream ss;
     ss << hex << inst;
     unsigned n;
     ss >> n;
     bitset<32> b(n);
     string s = b.to_string();
     return s;
}

bool phase3::checkPrediction(int funct3 , int RA , int RB ,bool isTaken)
{
    if(funct3 == 0)
    {
        if(RA == RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 1)
    {
        if(RA != RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 4)
    {
        if(RA < RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    if(funct3 == 5)
    {
        if(RA >= RB)
        {
            if(isTaken == true)
                return true;
            else return false;
        }
        else
        {
            if(isTaken == true)
                return false;
            else return true;
        }
        
    }
    return isTaken;
}


//Part of control unit => generators all ALU,  MUXes and Memory signals

int phase3::set_signal(int opcode,int funct3,int funct7, int *signal_memoryaccess,int *mem_wr,int *word_byte )
{
	if(opcode == 51 || opcode == 59)
	{
		*signal_memoryaccess = 0;
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
		*signal_memoryaccess = 1;
		if(funct3==0)
			*word_byte=0;
		else
		{
			*word_byte=1;
		}
		
		*mem_wr=0;
		return 1;
	}
	else if(opcode == 19 || opcode == 27)
	{
        *signal_memoryaccess = 0;
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
		*signal_memoryaccess = 1;
		*mem_wr=1;
		return 1;
	}
	else if(opcode == 99)
	{
        *signal_memoryaccess = 0;
		if(funct3 == 0 || funct3 == 1 || funct3 == 4 || funct3 == 5)
			return 5;
		else if(funct3 == 6 || funct3 == 7)
			return 12;
	}
	else if(opcode == 103)
	{
		*signal_memoryaccess = 0;
		return 1;
	}
	else if(opcode == 0)
	{
		*signal_memoryaccess = 0;
		return 1;

	}
	return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Fetch stage /////////////////////////////////////////////////////////////

void phase3::fetch()
{
	//cout<<"pc --------------> "<<pc<<endl;
	old_pc=pc;
	int k=pc/4;
	IR = instructions_bin[k]; // instruction is stored in vector in driver code
	pc=pc+4;
	
	if(branch_map.count(old_pc)!=0)
	{
		if(branch_map.find(old_pc)->second<0)
		{
			isTaken = true;
		}
		else
		{
			isTaken = false;
		}
	}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////// Decode stage ////////////////////////////////////////////////////////////

// decode function is also responsible for MUXB implimentation
int phase3::decode()
{
	int save_cycle_diff1=0,save_cycle_diff2=0;

	char initial_forward1='N',initial_forward2='N',dest_forward1='N',dest_forward2='N';

	all_sig obj_struct;

	int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1, word_byte=1; // flag signals

	string op_str,rd_str,funct3_str,rs1_str,rs2_str,funct7_str,ImmiSubstring;
	op_str = IR.substr(25,31); // last 7 bits are dedicated for opcode
	int rs1,rs2,rd=0;
	int opcode,funct3,funct7;
	opcode = bintodec(op_str);		//opcode in decimal form

	int RA=0,RB=0,immidiate=0;
	is_jump=0;
	sig_sw=0;
	if(opcode==17) // exit in case of swi 0x11 instruction
	{
		exit_signal=1;
		obj_struct.signal_memoryaccess = signal_memoryaccess;
		obj_struct.mem_wr = mem_wr;
		obj_struct.regw_signal = regw_signal;
		obj_struct.word_byte = word_byte;
		buffer_signals.push(obj_struct);
		return 0;
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
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);		//arithmetic operator
        regw_signal=1;
        initial_forward1 = search_in_queue(rs1);
        save_cycle_diff1 = save_cycle_diff;
        initial_forward2 = search_in_queue(rs2);
        save_cycle_diff2 = save_cycle_diff;
        dest_forward1 = 'E';
        dest_forward2 = 'E';
        //cout<<initial_forward1<<" -> "<<dest_forward1<<" and "<<initial_forward2<<" -> "<<dest_forward2<<endl;
        int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
        hazard_rd.push(make_pair(rd,'E'));
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
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);		//arithmetic operator
        regw_signal=1;
        if(opcode==103)
        	is_jump=3;
        initial_forward1 = search_in_queue(rs1);
        save_cycle_diff1 = save_cycle_diff;
        dest_forward1 = 'E';
        dest_forward2 = 'E';
        //cout<<initial_forward1<<" -> "<<dest_forward1<<" and "<<initial_forward2<<" -> "<<dest_forward2<<endl;
        int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
        if(opcode==3)
        {
        	hazard_rd.push(make_pair(rd,'M'));
        }
        else
        {
	        hazard_rd.push(make_pair(rd,'E'));
        }
        if(opcode==103)
        {
        	branch_set.insert(pc);
        	if(branch_map.count(pc)==0)
        		branch_map.insert( pair<int,int>(pc,-1) );
        	
        	
        }
        
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
		sw_con=RB;//////change
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);	//arithmetic operator
        regw_signal=0;
        initial_forward1 = search_in_queue(rs1);
        save_cycle_diff1 = save_cycle_diff;
        initial_forward2 = search_in_queue(rs2);
        save_cycle_diff2 = save_cycle_diff;
        if(initial_forward1=='E' || initial_forward1=='M')
        	dest_forward1='E';
        if(initial_forward2=='E' || initial_forward2=='M')
        	dest_forward2='M';
        //if(initial_forward2=='E')
        	//initial_forward2='M';
        //cout<<initial_forward1<<" -> "<<dest_forward1<<" and "<<initial_forward2<<" -> "<<dest_forward2<<" "<<save_cycle_diff<<endl;
        int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
		hazard_rd.push(make_pair(-1,'E'));
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
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);		//arithmetic operator
		b_offset=immidiate;
        regw_signal=0;
        is_jump=1;
        cond_branch_type=funct3;
        
        initial_forward1 = search_in_queue(rs1);
        save_cycle_diff1 = save_cycle_diff;
        initial_forward2 = search_in_queue(rs2);
        save_cycle_diff2 = save_cycle_diff;
        dest_forward1 = 'E';
        dest_forward2 = 'E';
        //cout<<initial_forward1<<" -> "<<dest_forward1<<" and "<<initial_forward2<<" -> "<<dest_forward2<<endl;
        int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
		hazard_rd.push(make_pair(-1,'E'));
		if(opcode==99)
        {
        	branch_set.insert(pc);
        	if(branch_map.count(pc)==0)
        		branch_map.insert( pair<int,int>(pc,b_offset) );
        }
        
	}
	else if(opcode == 55)	// U format
	{
		rd_str = IR.substr(20,5);
		ImmiSubstring = IR.substr(0,20);
		rd = bintodec(rd_str);
		immidiate = bintodec(ImmiSubstring);
		immidiate *= 4096;
		signal_memoryaccess = 1;		// access to memory
		initial_forward1 = search_in_queue(rs1);
		save_cycle_diff1 = save_cycle_diff;
        initial_forward2 = search_in_queue(rs2);
        save_cycle_diff2 = save_cycle_diff;
        dest_forward1 = 'E';
        dest_forward2 = 'E';
        //cout<<initial_forward1<<" -> "<<dest_forward1<<" and "<<initial_forward2<<" -> "<<dest_forward2<<endl;
		int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
        hazard_rd.push(make_pair(rd,'E'));
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
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);	
		b_offset=immidiate;
		temp_RZ=pc;
        regw_signal=1;
		signal_memoryaccess = 0;
		is_jump=2;
		int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
		hazard_rd.push(make_pair(rd,'E'));
		if(opcode==111)
        {
        	branch_set.insert(pc);
        	if(branch_map.count(pc)==0)
        		branch_map.insert( pair<int,int>(pc,-1) );
        }
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
		signal_ALU = set_signal(opcode,funct3,funct7,&signal_memoryaccess,&mem_wr,&word_byte);
		regw_signal=1;
		int len = hazard_rd.size();
		while(len--)
		{
			hazard_rd.front().second='M';
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
		hazard_rd.push(make_pair(rd,'M'));
	}



/////////////////////////////////////////////////////MuxA/////////////////////////////////////////////
	if(initial_forward1=='N')
		ALU_input1 = RA;
	else
	{
		if(initial_forward1=='M')
		{
			ALU_input1=RY;
		}
		else
		{
			ALU_input1=RZ;
		}
	}

	if(opcode==0)
		ALU_input1=0;

///////////////////////////////////////////////// MUXB ////////////////////////////////////////////////////////
	if(initial_forward2=='N')
	{
		if(opcode == 99 || opcode == 51 || opcode == 59)
			ALU_input2=RB;
		else
			ALU_input2=immidiate;
	}
	else
	{
		if(initial_forward2=='M')
		{
			ALU_input2=RY;
		}
		else
		{
			ALU_input2=RZ;
		}
		if(opcode==35) // S format
		{
			ALU_input2=immidiate;
		}
	}



	/***********************************************************************************/
        
        
        if(is_jump==1) // for conditional branch
		{
		
			int compare =-2;
		    if(ALU_input1<ALU_input2)
				compare = -1;
			else if(ALU_input1>ALU_input2)
				compare = 1;
			else
				compare = 0;
				
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
					//cout<<"inbge\n";
					//cout<<ALU_input1<<" "<<ALU_input2<<endl;
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
		else if(is_jump==2)   // enter in case of uncondition branch only
			pc=pc+b_offset-4;
	
		else if(is_jump==3) 
		{
			//RZ = ALU_input1+ALU_input2;
			//cout<<"================================================================"<<pc<<endl;
		    pc=ALU_input1+ALU_input2;
		   // cout<<"================================================================"<<pc<<endl;
		}
		b_offset=0;
        
        
        
        /*************************************************************************************/	
	
////////////////////////////////////////////// MUX M///////////////////////////////////////////////////////////
	if(opcode==35)
	{
		//RM = RB;
		sig_sw =1;
	}
	if(dest_forward2=='M'&& initial_forward2=='E')
	{
		is_jump = 4; 
		sig_sw =0;
	}
	if(initial_forward2 == 'M'&&is_jump!= 4)
	{
			RM=RY;
			sig_sw =0;
	}
	//cout<<RZ<<" "<<RY<<" "<<RM<<endl;
	obj_struct.signal_memoryaccess = signal_memoryaccess;
	obj_struct.mem_wr = mem_wr;
	obj_struct.regw_signal = regw_signal;
	obj_struct.word_byte = word_byte;
	buffer_signals.push(obj_struct);
	//cout<<"RZ------------"<<RZ<<endl;
	
	if(opcode==99)
	{
		CorrectPrediction = checkPrediction(funct3,ALU_input1,ALU_input2,isTaken);
        if(!CorrectPrediction)
            BranchPenality++;
	}
	my_sw=0;
	if(save_cycle_diff==1 && initial_forward2=='M' && dest_forward2=='M')
		my_sw=1;
	
	CALC_FORWARDING(initial_forward1,dest_forward1,initial_forward2,dest_forward2);
	return rd;

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

void phase3::execute()
{
	int compare=-2;
	if(my_sw==1)
	{
		RM=RY;
	}
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
	if(is_jump==2)
	{
		RZ=temp_RZ;
	}
	if(sig_sw == 1)
	{
		RM = sw_con;
	}
	b_offset=0;
	if(is_jump==4)
	{
		RM=RY;
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Memory stage /////////////////////////////////////////////////////////////

void phase3::mem(memoryclass *ob)    			// ".data" part and memory write is handled in memoryclass.cpp file
{
	stack<all_sig> stk;
	int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1, word_byte=1; // flag signals
	int len = buffer_signals.size();
	while(len--)
	{
		stk.push(buffer_signals.front());
		buffer_signals.push(buffer_signals.front());
		buffer_signals.pop();	
	}
	if(stk.size()>=2)
		stk.pop();
	if(stk.size())
	{
		signal_memoryaccess = stk.top().signal_memoryaccess;
			mem_wr = stk.top().mem_wr;
			regw_signal = stk.top().regw_signal;
			word_byte = stk.top().word_byte;
	}
	while(stk.size())
		stk.pop();
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

		if(mem_wr==1) // write in memory
		{
            ob->mem_row=rowi;
            ob->mem_column=colj;
          //  cout<<"RM****************************************************************"<<RM<<endl;
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
            MUXY_signal=1;	
		}
	}

	/////////////////////////////// MUXY ////////////////////////////////////
	if(MUXY_signal==0)
	{
		RY=RZ;
	}
	else if(MUXY_signal==1)
		RY=b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// Write back stage ///////////////////////////////////////////////////////////
void phase3::write(int rd)
{
	stack<all_sig> stk;
	int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1, word_byte=1; // flag signals
	int len = buffer_signals.size();
	while(len--)
	{
		stk.push(buffer_signals.front());
		buffer_signals.push(buffer_signals.front());
		buffer_signals.pop();	
	}
	if(stk.size())
	{
		if(stk.size()>=3)
		{
			stk.pop();
			stk.pop();
		}
		else if(stk.size()>=2)
		{
			stk.pop();
		}
		if(stk.size())
		{
			signal_memoryaccess = stk.top().signal_memoryaccess;
			mem_wr = stk.top().mem_wr;
			regw_signal = stk.top().regw_signal;
			word_byte = stk.top().word_byte;
		}
		while(stk.size())
			stk.pop();
	}
	if( regw_signal==1 && rd!=0 )  // x0 is always zero
	{
		register_file[rd]=RY;
	}
	if(hazard_rd.size())
		hazard_rd.pop();
	if(buffer_signals.size())
		buffer_signals.pop();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// Driver code //////////////////////////////////////////////////////////////

phase3::phase3()
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
	int cycle_no=1;// for pipelineling
	int rd;
	queue<int> q_for_rd;
	int j=4;// for last instruction
	string nop_IR="11101111000000000000000000010001"; //li x0 0
	while(j>1)
	{
		//cout<<cycle_no<<"=====> ";
		if(cycle_no>4 && j>1)
		{
			write(q_for_rd.front());
			if(q_for_rd.size())
				q_for_rd.pop();
		}
		if(cycle_no>3 && j>2)
		{
			mem(&obj_mem_class1);
		}
		if(cycle_no>2 && j>3)
		{
			execute();
		}
		if(cycle_no>1 && j>3)
		{
			rd=decode();
			q_for_rd.push(rd);
		}
	   	if(exit_signal==1) 		// "0xEF000011" case => swi 0x11 => exit case
	   		j--;
	   	if(j>3)
	   	{
	   		fetch();
	   	}
		cycle_no++;
		/*cout<<"\nRegisters : \n\n";
		for( int itertor=0 ; itertor<8 ; itertor++ )
			cout << "x" << itertor << " :\t" << register_file[itertor] << endl;
		cout<<"total cycles: "<<cycle_no-1<<endl;*/
		int len = hazard_rd.size();
		while(len--)
		{
			//cout<<hazard_rd.front().first<<" "<<hazard_rd.front().second<<" <- ";
			hazard_rd.push(make_pair(hazard_rd.front().first,hazard_rd.front().second));
			hazard_rd.pop();
		}
		//cout<<endl;
		len = q_for_rd.size();
		while(len--)
		{
			//cout<<q_for_rd.front()<<" ";
			q_for_rd.push(q_for_rd.front());
			q_for_rd.pop();
		}
		//cout<<endl;
			
	}
    cout<<"Branch Penalities : "<<BranchPenality<<endl;
	// Print all registers
	cout<<"\nRegisters : \n\n";
    for( int itertor=0 ; itertor<32 ; itertor++ )
		cout << "x" << itertor << " :\t" << register_file[itertor] << endl;
	//cout<<"total cycles: "<<cycle_no-1<<endl;
	totalcycles = cycle_no-1+BranchPenality;


	for(int i=0;i<50;i++)
	{
		for(int j=0;j<8;j++)
			cout<<obj_mem_class1.memory[i][j];
		cout<<endl;
	}


	//return 0;
}


int phase3::ETOE()
{
	return etoe;
}

int phase3::MTOE()
{
	return mtoe;
}

int phase3::MTOM()
{
	return mtom;
}

int phase3::MISPREDICTIONS()
{
	return BranchPenality;
}

int phase3::TOTALCYCLES()
{
	return totalcycles;
}

int phase3::MTOESTALL()
{
	return mtoestall;
}
void phase3::CALC_FORWARDING(char I1, char D1, char I2, char D2)
{
	if( (I1=='E' && D1=='E') || (I2=='E' && D2=='E') ) 
		etoe++;
	if( (I1=='M' && D1=='E') || (I2=='M' && D2=='E') ) 
		mtoe++;
	if(I2=='M' && D2=='M')
		mtom++;
}