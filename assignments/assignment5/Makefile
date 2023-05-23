CC = g++ -std=c++11 -g
exe_file = execution
$(exe_file): linkedlist.o driver.o 
	$(CC) linkedlist.o driver.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
linkedlist.o: linkedlist.cpp
	$(CC) -c linkedlist.cpp
clean:
	rm -f *.out *.o $(exe_file)