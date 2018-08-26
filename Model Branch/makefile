CC=g++
CFLAGS=-Wall -std=c++11.

kalk_model: C_cartesiano.o Circuit_Hierarchy.o Circuito.o Complesso.o Componente.o Condensatore.o C_polare.o Database_Hierarchy.o Hierarchy_Handler.o Induttore.o main.o Numerical_Hierarchy.o Numero.o Raz.o Resistore.o tupla.o
	$(CC) -o kalk_model C_cartesiano.o Circuit_Hierarchy.o Circuito.o Complesso.o Componente.o Condensatore.o C_polare.o Database_Hierarchy.o Hierarchy_Handler.o Induttore.o main.o Numerical_Hierarchy.o Numero.o Raz.o Resistore.o tupla.o

C_cartesiano.o: C_cartesiano.cpp
	$(CC) -c C_cartesiano.cpp

Circuit_Hierarchy.o: Circuit_Hierarchy.cpp
	$(CC) -c Circuit_Hierarchy.cpp

Circuito.o: Circuito.cpp
	$(CC) -c Circuito.cpp

Complesso.o: Complesso.cpp
	$(CC) -c Complesso.cpp

Componente.o: Componente.cpp
	$(CC) -c Componente.cpp

Condensatore.o: Condensatore.cpp
	$(CC) -c Condensatore.cpp

C_polare.o: C_polare.cpp
	$(CC) -c C_polare.cpp

Database_Hierarchy.o: Database_Hierarchy.cpp
	$(CC) -c Database_Hierarchy.cpp

Hierarchy_Handler.o: Hierarchy_Handler.cpp
	$(CC) -c Hierarchy_Handler.cpp

Induttore.o: Induttore.cpp
	$(CC) -c Induttore.cpp

main.o: main.cpp
	$(CC) -c main.cpp

Numerical_Hierarchy.o: Numerical_Hierarchy.cpp
	$(CC) -c Numerical_Hierarchy.cpp

Numero.o: Numero.cpp
	$(CC) -c Numero.cpp

Raz.o: Raz.cpp
	$(CC) -c Raz.cpp

Resistore.o: Resistore.cpp
	$(CC) -c Resistore.cpp

tupla.o: tupla.cpp
	$(CC) -c tupla.cpp


clean:
	rm *.o
