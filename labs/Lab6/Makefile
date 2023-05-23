CC = g++

app: driver.o fruit.o apple.o orange.o
	$(CC) driver.o fruit.o apple.o orange.o -o app

driver.o: driver.cpp
	$(CC) -c driver.cpp

fruit.o: fruit.cpp
	$(CC) -c fruit.cpp

apple.o: apple.cpp
	$(CC) -c apple.cpp

orange.o: orange.cpp
	$(CC) -c orange.cpp

clean:
	rm -f *.o app
