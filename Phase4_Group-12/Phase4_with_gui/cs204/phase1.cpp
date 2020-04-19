

#include<bits/stdc++.h>
#include "phase1.h"

using namespace std;

phase1::phase1(int control_phase)
{
	control_phase1 = control_phase;
	make_map objmakemap;
	machinecode objmachinecode;
	original objoriginal;
	objoriginal.compatible_original();
	objmakemap.create_map();
	objoriginal.calc_label(objmakemap);
	objmachinecode.conv_to_mac_code(objmakemap, control_phase1);

}
