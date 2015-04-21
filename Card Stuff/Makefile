all: interpreter

interpreter: interpreter.o Card.o Hand.o Deck.o 
	g++ interpreter.cpp Card.h Hand.h Deck.h -o interpreter

interpreter.o: interpreter.cpp
	g++ -c interpreter.cpp

Card.o: Card.h
	g++ -c Card.h

Deck.o: Deck.h
	g++ -c Deck.h

Hand.o: Hand.h
	g++ -c Hand.h

clean:
	rm *.o interpreter
