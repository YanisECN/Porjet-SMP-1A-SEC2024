all : prgm

clean :
	del *.o

rebuild : clean all

prgm : main.o carte.o carte_acteur.o acteur.o joueur.o
	g++ -o prgm.exe main.o carte.o carte_acteur.o acteur.o joueur.o

main.o : main.cpp
	g++ -o main.o -c main.cpp

carte_acteur.o : carte_acteur.cpp
	g++ -o carte_acteur.o -c carte_acteur.cpp

carte.o : carte.cpp
	g++ -o carte.o -c carte.cpp

acteur.o : acteur.cpp 
	g++ -o acteur.o -c acteur.cpp

joueur.o : joueur.cpp 
	g++ -o joueur.o -c joueur.cpp 