CC = g++ -std=c++11
exe_file = card_deck
$(exe_file): driver.o deck.o card.o
	$(CC) driver.o deck.o card.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
card.o: card.cpp
	$(CC) -c card.cpp
