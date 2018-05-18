CC = g++

CFLAGS = -std=c++11 -Wall

all: kalk

kalk: main.o C_cartesiano.o C_polare.o Circuito.o Complesso.o Componente.o Condensatore.o Induttore.o Melodia.o Nota.o Numero.o parser.o Raz.o Resistore.o
	$(CC) $(CFLAGS) -o kalk main.o C_cartesiano.o C_polare.o Circuito.o Complesso.o Componente.o Condensatore.o Induttore.o Melodia.o Nota.o Numero.o parser.o Raz.o Resistore.o


main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

C_cartesiano.o: C_cartesiano.cpp
	$(CC) $(CFLAGS) -c C_cartesiano.cpp

C_polare.o: C_polare.cpp
	$(CC) $(CFLAGS) -c C_polare.cpp

Circuito.o: Circuito.cpp
	$(CC) $(CFLAGS) -c Circuito.cpp

Complesso.o: Complesso.cpp
	$(CC) $(CFLAGS) -c Complesso.cpp

Componente.o: Componente.cpp
	$(CC) $(CFLAGS) -c Componente.cpp

Condensatore.o: Condensatore.cpp
	$(CC) $(CFLAGS) -c Condensatore.cpp

Induttore.o: Induttore.cpp
	$(CC) $(CFLAGS) -c Induttore.cpp

Melodia.o: Melodia.cpp
	$(CC) $(CFLAGS) -c Melodia.cpp

Nota.o: Nota.cpp
	$(CC) $(CFLAGS) -c Nota.cpp

Numero.o: Numero.cpp
	$(CC) $(CFLAGS) -c Numero.cpp

parser.o: parser.cpp
	$(CC) $(CFLAGS) -c parser.cpp

Raz.o: Raz.cpp
	$(CC) $(CFLAGS) -c Raz.cpp

Resistore.o: Resistore.cpp
	$(CC) $(CFLAGS) -c Resistore.cpp
