#include<bits/stdc++.h>
#include "machine_conv.h"
#include "make_map.h"
#include "original_to_basic.h"
using namespace std;
#define maxbitset 64
machinecode:: machinecode()
{
	rs1='\0';
	rs2='\0';
	rd='\0';
	imm=0;
}

string machinecode:: discard_zeroes(int cnt){
	bitset<maxbitset> objbit(cnt);
	string sobjbit = objbit.to_string();
	int j=0;
	for(j=0;j<sobjbit.length();j=j+4)
	{
		string tmp = sobjbit.substr(j,4);
		if (tmp.compare("0000"))
			break;
	}
	string sobjbit_1;
	if(j==sobjbit.length())
		sobjbit_1="0000";
	else
		sobjbit_1 =sobjbit.substr(j,sobjbit.length()-j);
	return sobjbit_1;
}

void machinecode:: conv_to_mac_code(make_map obj, int conrtol_phase1)
{
	string ins_name;
	if(conrtol_phase1 ==0)
	{
		ifstream basic_codefp("basic_code.txt",ios::in);  // reading assembly code
		ofstream machine_codefp("machine_code.txt",ios::out);  //write
		if(!basic_codefp)
			cout<<"basic_code.txt not readed"<<endl;
		else
		{
			int countpc=0;
			while(basic_codefp>>ins_name)
			{

				if(ins_name[0]=='#')
					continue;
				// checking whether this is instructionor label bcz all instruction are mapped with type
				else
				{
					if(obj.mtype.count(ins_name)==0)
					{	
						basic_codefp>>ins_name;
					}
					string rs1,rs2,rd;
					int imm;
					string type;
					if(obj.mtype.count(ins_name)==0)
						type="A";
					else
						type = obj.mtype.find(ins_name)->second;
					if(type=="R")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rd>>rs1>>rs2;
						string rs_2;
						int i=0;
						for(i=0;i<rs2.length();i++)
						{
							if(rs2[i]=='#')
								break;
						}
						rs_2=rs2.substr(0,i);
						machine_codefp<<obj.funcR(ins_name,rd,rs1,rs_2)<<endl;
					}
					else if(type=="I")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rd>>rs1>>imm;
						machine_codefp<<obj.funcI(ins_name,rd,rs1,imm)<<endl;
					}
					else if(type=="S")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rs2>>rs1>>imm;
						machine_codefp<<obj.funcS(ins_name,rs2,rs1,imm)<<endl;
					}
					else if(type=="SB")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rs1>>rs2>>imm;
						machine_codefp<<obj.funcSB(ins_name,rs1,rs2,imm)<<endl;
					}
					else if(type=="U")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rd>>imm;
						machine_codefp<<obj.funcU(ins_name,rd,imm)<<endl;
					}
					else if(type=="UJ")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rd>>imm;
						machine_codefp<<obj.funcUJ(ins_name,rd,imm)<<endl;
					}
					else if(type=="P")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>rd>>imm;
						machine_codefp<<obj.funcP(ins_name,rd,imm)<<endl;
					}
					else if(type=="exit")
					{
						string readexit;
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_codefp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_codefp>>readexit;
						machine_codefp<<"0xEF000011";
					}
				}
			}
		}
		basic_codefp.close();
		machine_codefp.close();

	}
	else if(conrtol_phase1 ==1)
	{
		ifstream basic_code1fp("basic_for_M_to_E_stalling.txt",ios::in);  // reading assembly code
		ofstream machine_code1fp("machine_code.txt",ios::out);  //write
		if(!basic_code1fp)
			cout<<"basic_code1.txt not readed"<<endl;
		else
		{
			int countpc=0;
			while(basic_code1fp>>ins_name)
			{

				if(ins_name[0]=='#')
					continue;
				// checking whether this is instructionor label bcz all instruction are mapped with type
				else
				{
					if(obj.mtype.count(ins_name)==0)
					{	
						basic_code1fp>>ins_name;
					}
					string rs1,rs2,rd;
					int imm;
					string type;
					if(obj.mtype.count(ins_name)==0)
						type="A";
					else
						type = obj.mtype.find(ins_name)->second;
					if(type=="R")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rd>>rs1>>rs2;
						string rs_2;
						int i=0;
						for(i=0;i<rs2.length();i++)
						{
							if(rs2[i]=='#')
								break;
						}
						rs_2=rs2.substr(0,i);
						machine_code1fp<<obj.funcR(ins_name,rd,rs1,rs_2)<<endl;
					}
					else if(type=="I")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rd>>rs1>>imm;
						machine_code1fp<<obj.funcI(ins_name,rd,rs1,imm)<<endl;
					}
					else if(type=="S")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rs2>>rs1>>imm;
						machine_code1fp<<obj.funcS(ins_name,rs2,rs1,imm)<<endl;
					}
					else if(type=="SB")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rs1>>rs2>>imm;
						machine_code1fp<<obj.funcSB(ins_name,rs1,rs2,imm)<<endl;
					}
					else if(type=="U")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rd>>imm;
						machine_code1fp<<obj.funcU(ins_name,rd,imm)<<endl;
					}
					else if(type=="UJ")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rd>>imm;
						machine_code1fp<<obj.funcUJ(ins_name,rd,imm)<<endl;
					}
					else if(type=="P")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>rd>>imm;
						machine_code1fp<<obj.funcP(ins_name,rd,imm)<<endl;
					}
					else if(type=="exit")
					{
						string readexit;
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code1fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code1fp>>readexit;
						machine_code1fp<<"0xEF000011";
					}
				}
			}
		}
		basic_code1fp.close();
		machine_code1fp.close();

	}
	else if(conrtol_phase1 ==2)
	{
		ifstream basic_code2fp("basic_only_stalling.txt",ios::in);  // reading assembly code
		ofstream machine_code2fp("machine_code.txt",ios::out);  //write
		if(!basic_code2fp)
			cout<<"basic_code2.txt not readed"<<endl;
		else
		{
			int countpc=0;
			while(basic_code2fp>>ins_name)
			{

				if(ins_name[0]=='#')
					continue;
				// checking whether this is instructionor label bcz all instruction are mapped with type
				else
				{
					if(obj.mtype.count(ins_name)==0)
					{	
						basic_code2fp>>ins_name;
					}
					string rs1,rs2,rd;
					int imm;
					string type;
					if(obj.mtype.count(ins_name)==0)
						type="A";
					else
						type = obj.mtype.find(ins_name)->second;
					if(type=="R")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rd>>rs1>>rs2;
						string rs_2;
						int i=0;
						for(i=0;i<rs2.length();i++)
						{
							if(rs2[i]=='#')
								break;
						}
						rs_2=rs2.substr(0,i);
						machine_code2fp<<obj.funcR(ins_name,rd,rs1,rs_2)<<endl;
					}
					else if(type=="I")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rd>>rs1>>imm;
						machine_code2fp<<obj.funcI(ins_name,rd,rs1,imm)<<endl;
					}
					else if(type=="S")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rs2>>rs1>>imm;
						machine_code2fp<<obj.funcS(ins_name,rs2,rs1,imm)<<endl;
					}
					else if(type=="SB")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rs1>>rs2>>imm;
						machine_code2fp<<obj.funcSB(ins_name,rs1,rs2,imm)<<endl;
					}
					else if(type=="U")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rd>>imm;
						machine_code2fp<<obj.funcU(ins_name,rd,imm)<<endl;
					}
					else if(type=="UJ")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rd>>imm;
						machine_code2fp<<obj.funcUJ(ins_name,rd,imm)<<endl;
					}
					else if(type=="P")
					{
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>rd>>imm;
						machine_code2fp<<obj.funcP(ins_name,rd,imm)<<endl;
					}
					else if(type=="exit")
					{
						string readexit;
						string sobjbit_1=discard_zeroes(countpc*4);
						machine_code2fp<<obj.bin_to_hex(sobjbit_1)<<" ";countpc++;
						basic_code2fp>>readexit;
						machine_code2fp<<"0xEF000011";
					}
				}
			}
		}
		basic_code2fp.close();
		machine_code2fp.close();

	}
	
}



machinecode::~machinecode(){}
