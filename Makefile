all: 7Ws

7Ws: CardDeck.o player.o GameController.o SevenWonders.o wonder.o
	g++ CardDeck.o player.o GameController.o SevenWonders.o wonder.o -o 7Ws

GameController.o: GameController.cpp
	g++ -c GameController.cpp

player.o: player.cpp
	g++ -c player.cpp

SevenWonders.o: SevenWonders.cpp
	g++ -c SevenWonders.cpp

CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

wonder.o: wonder.cpp
	g++ -c wonder.cpp

clean:
	rm *.o 7Ws
