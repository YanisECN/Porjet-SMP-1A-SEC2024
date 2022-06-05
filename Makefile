main.out : main.o acteur.o carte_acteur.o carte.o joueur.o
	g++ -o main.out main.o carte_acteur.o acteur.o carte.o joueur.o

main.o: source/main.cpp
	g++ -c  source/main.cpp

carte_acteur.o : source/carte_acteur.cpp
	g++ -c source/carte_acteur.cpp

carte.o: source/carte.cpp
	g++ -c source/carte.cpp

acteur.o: source/acteur.cpp
	g++ -c source/acteur.cpp

joueur.o : source/joueur.cpp
	g++ -c source/joueur.cpp
