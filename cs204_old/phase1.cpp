

#include<bits/stdc++.h>
#include "phase1.h"

using namespace std;

phase1::phase1(int control_phase)
{
	control_phase1 = control_phase;
	make_map objmakemap;
	machinecode objmachinecode;
	original objoriginal;
	objmakemap.create_map();
	objoriginal.compatible_original(objmakemap);
	objoriginal.calc_label(objmakemap,control_phase1);
	objmachinecode.conv_to_mac_code(objmakemap);
	stalls = objoriginal.STALLS();
}

int phase1:: Stalls()
{
	return stalls;
}