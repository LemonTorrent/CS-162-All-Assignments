CC = g++ -std=c++11 -g
exe_file = lab8
$(exe_file): test_vector.o
	$(CC) test_vector.o -o $(exe_file)
test_vector.o: test_vector.cpp
	$(CC) -c test_vector.cpp
clean:
	rm -f *.out *.o $(exe_file)