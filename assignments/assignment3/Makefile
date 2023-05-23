CC = g++ -std=c++11 -g
exe_file = zoo
$(exe_file): driver.o zoo.o animal.o tiger.o blackbear.o sealion.o
	$(CC) driver.o zoo.o animal.o tiger.o blackbear.o sealion.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
blackbear.o: blackbear.cpp
	$(CC) -c blackbear.cpp
sealion.o: sealion.cpp
	$(CC) -c sealion.cpp