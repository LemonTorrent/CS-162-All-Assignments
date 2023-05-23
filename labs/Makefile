CC = g++
exe_file = lab1part2
$(exe_file): lab1part2.o  prog.o
	$(CC) lab1part2.o  prog.o -o $(exe_file)
lab1part2.o: lab1part2.cpp
	$(CC) -c lab1part2.cpp
prog.o:prog.cpp
	$(CC) -c prog.cpp
