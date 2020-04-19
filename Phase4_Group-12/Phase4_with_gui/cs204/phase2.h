#ifndef PHASE2_H
#define PHASE2_H
#include <bits/stdc++.h>
#include "memoryclass.h"
using namespace std;

class phase2
{
    public:
  /*/////////////////////////////////////////////////////////////////////

   RA,RB,RZ,RY,RM  =>  buffer registers b/w stages
   pc => current program counter
   signal_memoryaccess = 0 if memmory is not to be accessed else 1
   signal_ALU => control for ALU
   is_jump=1 for cond.branch , 2 for uncond. branch , 3 for "jalr"
   b_offest => branch offset
   IR => Instruction register

	//////////////////////////////////////////////////////////////////////*/

	vector<string> instructions_bin;
	vector<int> program_counter_deci;

	string IR; // stores current instruction
	int RZ,RY,RM,sp=1000,rd,pc=0,b_offset=0;

	int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1 , exit_signal=0 , is_jump=0; // flag signals

	int register_file[32]={0};

	//ALU inputs
	int ALU_input1,ALU_input2;
	int  signal_ALU = 0;
	int word_byte=1;
	int cond_branch_type=0;



// convert binary string to decimal
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    phase2();
	int bintodec(string s);
	string findTwoscomplement(string str);
	int bintodec_negative(string s);
	string hextobin(string inst);
	string to_string(int i);
	int set_signal(int opcode,int funct3,int funct7);
	void fetch();
	void decode();
	void execute();
	void mem(memoryclass *ob);
	void write();
      //~phase3();


};


#endif
