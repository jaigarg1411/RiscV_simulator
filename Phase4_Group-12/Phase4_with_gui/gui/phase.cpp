#include "machine_conv.h"
#include "make_map.h"
#include "original_to_basic.h"
#include "memoryclass.h"
#include"phase.h"

#include<bits/stdc++.h>
using namespace std;

phase1::phase1()
{
    make_map objmakemap;
	machinecode objmachinecode;
	original objoriginal;
	objoriginal.compatible_original();
	objmakemap.create_map();
	objoriginal.calc_label(objmakemap);
    objmachinecode.conv_to_mac_code(objmakemap);

}
