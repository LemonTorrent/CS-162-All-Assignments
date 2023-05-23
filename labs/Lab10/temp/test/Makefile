CC = g++
exe_file = dog_animal
$(exe_file): pet.o dog.o driver.o
	$(CC) pet.o dog.o driver.o -o $(exe_file)
animal.o: pet.cpp
	$(CC) -c pet.cpp
dog.o: dog.cpp
	$(CC) -c dog.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
