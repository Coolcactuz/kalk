CC=g++
CFLAGS=-Wall -std=c++11

kalk_model: Numero.o Raz.o Complesso.o C_cartesiano.o C_polare.o Componente.o Resistore.o Induttore.o Condensatore.o tupla.o Hierarchy_Handler.o Circuit_Hierarchy.o Numerical_Hierarchy.o Database_Hierarchy.o main.o
	$(CC) $(CFLAGS) -o kalk_model Numero.o Raz.o Complesso.o C_cartesiano.o C_polare.o Componente.o Resistore.o Induttore.o Condensatore.o tupla.o Hierarchy_Handler.o Circuit_Hierarchy.o Numerical_Hierarchy.o Database_Hierarchy.o main.o

Numero.o: Numero.cpp
	$(CC) $(CFLAGS) -c Numero.cpp

Raz.o: Raz.cpp
	$(CC) $(CFLAGS) -c Raz.cpp

Complesso.o: Complesso.cpp
	$(CC) $(CFLAGS) -c Complesso.cpp

C_cartesiano.o: C_cartesiano.cpp
	$(CC) $(CFLAGS) -c C_cartesiano.cpp

C_polare.o: C_polare.cpp
	$(CC) $(CFLAGS) -c C_polare.cpp

Componente.o: Componente.cpp
	$(CC) $(CFLAGS) -c Componente.cpp

Resistore.o: Resistore.cpp
	$(CC) $(CFLAGS) -c Resistore.cpp

Induttore.o: Induttore.cpp
	$(CC) $(CFLAGS) -c Induttore.cpp

Condensatore.o: Condensatore.cpp
	$(CC) $(CFLAGS) -c Condensatore.cpp

tupla.o: tupla.cpp
	$(CC) $(CFLAGS) -c tupla.cpp

Hierarchy_Handler.o: Hierarchy_Handler.cpp
	$(CC) $(CFLAGS) -c Hierarchy_Handler.cpp

Circuit_Hierarchy.o: Circuit_Hierarchy.cpp
	$(CC) $(CFLAGS) -c Circuit_Hierarchy.cpp

Numerical_Hierarchy.o: Numerical_Hierarchy.cpp
	$(CC) $(CFLAGS) -c Numerical_Hierarchy.cpp

Database_Hierarchy.o: Database_Hierarchy.cpp
	$(CC) $(CFLAGS) -c Database_Hierarchy.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o
