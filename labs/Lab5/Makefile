CC = g++
exe_file = dates
$(exe_file): driver.o date.o
	$(CC) driver.o date.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
date.o:date.cpp
	$(CC) -c date.cpp
