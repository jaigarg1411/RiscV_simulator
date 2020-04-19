#include "machine_conv.h"
#include "make_map.h"
#include "original_to_basic.h"
#include "memoryclass.h"

#include<bits/stdc++.h>
using namespace std;

memoryclass :: memoryclass (){
    mem_row=0;
    mem_column=0;
}

void memoryclass::memory_handling()
{
    for(int i_row=0;i_row<2000;i_row++)
        for(int j_column=0;j_column<8;j_column++)
            memory[i_row][j_column]='0';
	ifstream fp("original_code.txt",ios::out);
	string s;
	int i1,x;
	
	fp>>s;	
	if(s==".data")											//starting of .data
	while(fp>>s)
	{
		if(s==".text")										//starting of .text
			break;
		x= s.length();
		if(s[x-1]==':')										//starting of new variable
		{
			data_row.insert(pair<string, int>(s,mem_row));
			data_column.insert(pair<string, int>(s,mem_column));
			
			continue;
		}
		if(s[0]=='.')										// stores information about .word or .byte
		{
			i1=len_word(s);
			continue;
		}
		write_mem(s,i1);
	}


	for(int i3=0;i3<mem_row;i3++)
	{
		for(int i4=0;i4<8;i4++)
			cout<<memory[i3][i4];
		cout<<endl;
	}
	cout<<endl<<endl;

}
int memoryclass::len_word(string s)
{
	if(s==".word")
		return 8;
	else if(s==".byte")
		return 2;
	return 0;
}
void memoryclass::dectohex(string s)
{
	string s1;
	int j=s.length();
	int u=1,d=0,x,i1=0;
	while(i1<j)
	{
		x=(int)s[i1]-48;
		d=d*u+x;
		i1++;
		u=10;
	}
	s1="";
	s="";
	j=0;
	while(d!=0)
	{
		x=d%16;
		if(x<10)
		x=x+48;
		else
		x=x+55;
		s1[j++]=x;
		d=d/16;
	}
	u=0;
	len=j;
	while(j>0)
	{
		res[u++]=s1[j-1];
		j--;
	}
}

void memoryclass::write_mem(string s,int i1)
{
	int x;
	int i2=0,t;
	string s1=s;
	if(s[1]!='x')
	{
		dectohex(s);
		if(len%2!=0)
		{
			len=len+1;
			res[len-1]=res[len-2];
			res[len-2]='0';
		}
		x=len;
		int y=len;
		while(y>1)
		{
			 t=res[y-1];
			 int t1=res[y-2];
			 memory[mem_row][mem_column++]=t1;
			 if(mem_column==8)
			 {
				mem_row++;
				mem_column=0;
			 }
			 memory[mem_row][mem_column++]=t;
			 if(mem_column==8)
			 {
				mem_row++;
				mem_column=0;
			}
			 i2++;
			 y=y-2;
			 i1=i1-2;
		}		
		while(i1>0)
		{ 
		    memory[mem_row][mem_column]='0';
			mem_column=mem_column+1;
			i1--;
			if(mem_column>=8)
			{
				mem_row=mem_row+1;
				mem_column=mem_column%8;
			}
		}
	}
	else
	{
		s1[1]='0';
	 	int y=s1.length();
	 	x=2;
	 	if(mem_column==8)
	 	{
			mem_row++;
			mem_column=0;
	 	}
		while(x<y)
		{
			res[x-2]=s1[x];
			x++;
		}
		y=y-2;
		while(y>1)
		{
			t=res[y-1];
			int t1=res[y-2];
			memory[mem_row][mem_column++]=t1;
			if(mem_column==8)
			{
				mem_row++;
				mem_column=0;
			}
			memory[mem_row][mem_column++]=t;
			if(mem_column==8)
			{
				mem_row++;
				mem_column=0;
			}
			i2++;
			y=y-2;
			i1=i1-2;
		}		
	 	while(i1>0)
		{
			memory[mem_row][mem_column]='0';
		    mem_column=mem_column+1;
		    i1--;
			if(mem_column>=8)
			{
				mem_row=mem_row+1;
				mem_column=mem_column%8;
			}
	    }
	}	
	
}
memoryclass::~memoryclass(){}
