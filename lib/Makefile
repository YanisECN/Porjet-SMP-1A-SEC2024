all : prgm

clean :
	del *.o

rebuild : clean all

prgm : main.o carte.o carte_acteur.o
	g++ -o prgm.exe main.o carte.o carte_acteur.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

carte.o : carte.cpp
	g++ -o carte.o -c carte.cpp

carte_acteur.o : carte_acteur.cpp
	g++ -o carte_acteur.o -c carte_acteur.cpp