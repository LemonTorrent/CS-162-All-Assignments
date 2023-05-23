CC = g++ -std=c++11
exe_file = lab2
$(exe_file): driver.o student_db.o
	$(CC) driver.o student_db.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp
