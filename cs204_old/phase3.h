#ifndef PHASE3_H
#define PHASE3_H
#include <bits/stdc++.h>
#include "memoryclass.h"
using namespace std;

class phase3
{
    public:
    /*/////////////////////////////////////////////////////////////////////

	   RA,RB,RZ,RY,RM  =>  buffer registers b/w stages
	   pc => current program counter
	   signal_memoryaccess = 0 if memmory is not to be accessed else 1
	   signal_ALU => control for ALU
	   is_jump=1 for cond. branch , 2 for uncond. branch , 3 for "jalr"
	   b_offest => branch offset
	   IR => Instruction register

	//////////////////////////////////////////////////////////////////////*/

	vector<string> instructions_bin;
	vector<int> program_counter_deci;
	queue<pair<int,char> > hazard_rd;

	string IR; // stores current instruction
	int RZ,RY,RM,sp=1000,pc=0,b_offset=0,temp_RZ,old_pc=0;
	bool isTaken=false,CorrectPrediction = false;
	int BranchPenality=0;

	//int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1 , exit_signal=0 , is_jump=0; // flag signals
	int exit_signal=0,is_jump=0,sw_con,sig_sw=0,my_sw=0;

	int register_file[32]={0};

	//ALU inputs
	int ALU_input1,ALU_input2;


	int  signal_ALU = 0;
	//int word_byte=1;
	int cond_branch_type=0;

	int cycle_diff=2,save_cycle_diff=-1;
	
	map<int,int> branch_map;
	set<int> branch_set;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef struct all_signals
	{
		int  signal_memoryaccess=0 , mem_wr=-1 , regw_signal=1, word_byte=1; // flag signals
	}all_sig;

	queue<all_sig> buffer_signals;
	int etoe=0,mtoe=0,mtom=0,totalcycles=0,mtoestall=0;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    	phase3();
	char search_in_queue(int regis);
	int bintodec(string s);
	string findTwoscomplement(string str);
	int bintodec_negative(string s);
	string hextobin(string inst);
	string to_string(int i);
	int set_signal(int opcode,int funct3,int funct7, int *signal_memoryaccess,int *mem_wr,int *word_byte );
	void fetch();
	int decode();
	void execute();
	void mem(memoryclass *ob);
	void write(int rd);
	bool checkPrediction(int funct3 , int RA , int RB ,bool isTaken);
	int ETOE();
	int MTOM();
	int MTOE();
	int TOTALCYCLES();
	int MISPREDICTIONS();
	int MTOESTALL();
	void CALC_FORWARDING(char,char,char,char);
      //~phase3();


};


#endif
