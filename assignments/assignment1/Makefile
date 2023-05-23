CC = g++ -std=c++11
exe_file = hogwarts
$(exe_file): hogwarts.o driver.o
	$(CC) hogwarts.o driver.o -o $(exe_file)
hogwarts.o: hogwarts.cpp
	$(CC) -c hogwarts.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

