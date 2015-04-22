all: 7Ws

7Ws: CardDeck.o player.o GameController.o SevenWonders.o wonder.o Card.o Deck.o Hand.o
	g++ -O0 -g3 player.o GameController.o SevenWonders.o wonder.o Card.o Hand.o Deck.o -o 7Ws

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

#interpreter: interpreter.o Card.o Hand.o Deck.o
#	g++ interpreter.cpp Card.h Hand.h Deck.h -o interpreter

interpreter.o: interpreter.cpp
	g++ -c interpreter.cpp

Card.o: Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.cpp
	g++ -c Deck.cpp

Hand.o: Hand.cpp
	g++ -c Hand.cpp

clean:
	rm *.o 7Ws interpreter
