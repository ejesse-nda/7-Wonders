all: 7Ws GUI

7Ws: CardDeck.o player.o GameController.o SevenWonders.o wonder.o Card.o Deck.o Hand.o
	g++ player.o GameController.o SevenWonders.o wonder.o Card.o Hand.o Deck.o -o 7Ws

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

Card.o: Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.cpp
	g++ -c Deck.cpp

Hand.o: Hand.cpp
	g++ -c Hand.cpp

GUI: Controller2.cpp
	g++ Controller2.cpp -o GUI -lSDL2 -lSDL2_image

clean:
	rm *.o 7Ws GUI
