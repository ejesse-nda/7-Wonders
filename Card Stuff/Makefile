all: Card

Card: Card.o Hand.o Deck.o 
	g++ Card.o Hand.o Deck.o -o Card

Card.o: Card.h
	g++ -c Card.h

Deck.o: Deck.h
	g++ -c Deck.h

Hand.o: Hand.h
	g++ -c Hand.h

clean:
	rm *.o Card
