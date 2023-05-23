CC = g++ -std=c++11
exe_file = crazy8
$(exe_file): card.o deck.o hand.o player.o game.o driver.o
	$(CC) card.o deck.o hand.o player.o game.o driver.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
game.o: game.cpp
	$(CC) -c game.cpp
player.o: player.cpp
	$(CC) -c player.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
card.o: card.cpp
	$(CC) -c card.cpp