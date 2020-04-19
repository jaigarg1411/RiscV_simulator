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
	original();
	void compatible_original();
	void calc_label(make_map obj);
	~original();

};
#endif