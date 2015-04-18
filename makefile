all: 7Ws

7Ws: CardDeck.o player.o GameController.o SevenWonders.o
	g++ CardDeck.o player.o GameController.o SevenWonders.o -o 7Ws

GameController.o: GameController.cpp
	g++ -c GameController.cpp

SevenWonders.o: SevenWonders.cpp
	g++ -c SevenWonders.cpp

player.o: player.cpp
	g++ -c player.cpp

CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

clean:
	rm -f *.o 7Ws
