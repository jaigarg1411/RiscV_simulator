all: final

final: phase1.o memoryclass.o machine_conv.o make_map.o original_to_basic.o phase2.o phase3.o interface.o
	g++ memoryclass.o phase1.o machine_conv.o make_map.o original_to_basic.o phase2.o phase3.o interface.o -o final

memoryclass.o: memoryclass.cpp
	g++ -c memoryclass.cpp

machine_conv.o: machine_conv.cpp
	g++ -c machine_conv.cpp

make_map.o: make_map.cpp
	g++ -c make_map.cpp

original_to_basic.o: original_to_basic.cpp
	g++ -c original_to_basic.cpp

phase1.o: phase1.cpp
	g++ -c phase1.cpp

phase2.o: phase2.cpp
	g++ -c phase2.cpp

phase3.o: phase3.cpp
	g++ -c phase3.cpp

interface.o: interface.cpp
	g++ -c interface.cpp


clean:
	rm *.o final
