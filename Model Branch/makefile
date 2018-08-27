CC=g++
CFLAGS=-Wall -std=c++11.

kalk_model: Numero.o Raz.o Complesso.o C_cartesiano.o C_polare.o Componente.o Resistore.o Induttore.o Condensatore.o tupla.o Hierarchy_Handler.o Circuit_Hierarchy.o Numerical_Hierarchy.o Database_Hierarchy.o main.o
	$(CC) -o kalk_model Numero.o Raz.o Complesso.o C_cartesiano.o C_polare.o Componente.o Resistore.o Induttore.o Condensatore.o tupla.o Hierarchy_Handler.o Circuit_Hierarchy.o Numerical_Hierarchy.o Database_Hierarchy.o main.o

Numero.o: Numero.cpp
	$(CC) -c Numero.cpp

Raz.o: Raz.cpp
	$(CC) -c Raz.cpp

Complesso.o: Complesso.cpp
	$(CC) -c Complesso.cpp

C_cartesiano.o: C_cartesiano.cpp
	$(CC) -c C_cartesiano.cpp

C_polare.o: C_polare.cpp
	$(CC) -c C_polare.cpp

Componente.o: Componente.cpp
	$(CC) -c Componente.cpp

Resistore.o: Resistore.cpp
	$(CC) -c Resistore.cpp

Induttore.o: Induttore.cpp
	$(CC) -c Induttore.cpp

Condensatore.o: Condensatore.cpp
	$(CC) -c Condensatore.cpp

tupla.o: tupla.cpp
	$(CC) -c tupla.cpp

Hierarchy_Handler.o: Hierarchy_Handler.cpp
	$(CC) -c Hierarchy_Handler.cpp

Circuit_Hierarchy.o: Circuit_Hierarchy.cpp
	$(CC) -c Circuit_Hierarchy.cpp

Numerical_Hierarchy.o: Numerical_Hierarchy.cpp
	$(CC) -c Numerical_Hierarchy.cpp

Database_Hierarchy.o: Database_Hierarchy.cpp
	$(CC) -c Database_Hierarchy.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o
