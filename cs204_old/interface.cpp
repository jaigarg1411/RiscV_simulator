#include<bits/stdc++.h>
#include "phase3.h"
#include "phase2.h"
#include "phase1.h"
using namespace std;

int main()
{
	int knob,enable;
	cout<<"Enter 1 For knob1."<<endl;
	cout<<"Enter 2 For knob2."<<endl;
	cout<<"Enter 3 For knob3."<<endl;
	cout<<"Enter 4 For knob4."<<endl;
	cout<<"Enter 5 For knob5."<<endl;
	cin>>knob;
	cout<<"Enter 1 for Enable."<<endl;
	cout<<"Enter 0 for Disable."<<endl;
	cin>>enable;
	if(knob == 1)
	{
		if(enable == 1)//pipelining
		{
			phase1 obj_ph1(1); ///M_to_E stalling
			phase3 obj;
			cout<<"no. of E -> E forarding : "<<obj.ETOE()<<endl;
			cout<<"no. of M -> E forarding : "<<obj.MTOE()<<endl;
			cout<<"no. of M -> M forarding : "<<obj.MTOM()<<endl;
			cout<<"no. of M -> E stalling : "<<obj_ph1.Stalls()<<endl;
			cout<<"Total cycles : "<<obj.TOTALCYCLES()+obj_ph1.Stalls()<<endl;
			cout<<"Branch Mispredictions : "<<obj.MISPREDICTIONS()<<endl;
			return 0;
		}
		else
		{
			phase1 obj_ph1(0);///basic code
			phase2 obj;
			cout<<"Total cycles : "<<obj.TOTALCYCLES() * 5<<endl;
			return 0;
		}
	}
	if(knob == 2)
	{
		if(enable == 1)// pipeline with forwarding 
		{
			phase1 obj_ph1(1); ///M_to_E stalling
			phase3 obj;
			cout<<"no. of E -> E forarding : "<<obj.ETOE()<<endl;
			cout<<"no. of M -> E forarding : "<<obj.MTOE()<<endl;
			cout<<"no. of M -> M forarding : "<<obj.MTOM()<<endl;
			cout<<"no. of M -> E stalling : "<<obj_ph1.Stalls()<<endl;
			cout<<"Total cycles : "<<obj.TOTALCYCLES()+obj_ph1.Stalls()<<endl;
			cout<<"Branch Mispredictions : "<<obj.MISPREDICTIONS()<<endl;
			return 0;
		}	
		else //only stalling
		{
			phase1 obj_ph1(2);		///only  stalling
			phase3 obj;
			cout<<"no. of E -> E forarding : "<<obj.ETOE()<<endl;
			cout<<"no. of M -> E forarding : "<<obj.MTOE()<<endl;
			cout<<"no. of M -> M forarding : "<<obj.MTOM()<<endl;
			//cout<<"no. of M -> E stalling : "<<obj_ph1.Stalls()<<endl;
			cout<<"Total cycles : "<<obj.TOTALCYCLES()+obj_ph1.Stalls()<<endl;
			cout<<"Branch Mispredictions : "<<obj.MISPREDICTIONS()<<endl;
			return 0;
		}
	}	
	if(knob == 3)
	{
		if(enable == 1)
			return 0;
		else
			return 0;
	}
	if(knob == 4)
	{
		if(enable == 1)
			return 0;
		else
			return 0;
	}
	if(knob == 5)
	{
		if(enable == 1)
			return 0;
		else
			return 0;
	}

}
	
	
