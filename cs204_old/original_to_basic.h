#ifndef ORIGINAL_TO_BASIC_H
#define ORIGINAL_TO_BASIC_H
#include "make_map.h"
#include "machine_conv.h"
#include "memoryclass.h"
#include <bits/stdc++.h>
using namespace std;

class original:public make_map,memoryclass
{
	map < string ,int > mlabel ;
public:
	int stalls=0;
	original();
	void compatible_original(make_map obj);
	void calc_label(make_map obj,int);
	int STALLS();
	~original();

};
#endif
