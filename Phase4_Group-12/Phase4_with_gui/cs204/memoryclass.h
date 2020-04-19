#ifndef MEMORYCLASS_H
#define MEMORYCLASS_H
#include <bits/stdc++.h>
using namespace std;

class memoryclass
{
    public:
    char memory[2000][8];
    char res[20];
    int len,mem_row=0,mem_column=0;
    map <string,int> data_row;
	map <string,int> data_column;
    memoryclass();
    void memory_handling();
    int len_word(string s);
    void dectohex(string s);
    void write_mem(string s,int i1);
    ~memoryclass();


};


#endif

