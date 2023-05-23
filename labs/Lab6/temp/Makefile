CC = g++ -std=c++11 -g
exe_file = application
$(exe_file): application.o shape.o circle.o rectangle.o square.o
	$(CC) application.o shape.o circle.o rectangle.o square.o -o $(exe_file)
application.o: application.cpp
	$(CC) -c application.cpp
shape.o: shape.cpp
	$(CC) -c shape.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
square.o: square.cpp
	$(CC) -c square.cpp
