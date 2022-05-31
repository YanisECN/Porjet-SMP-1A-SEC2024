#include "../lib/joueur.h"

void acteur::Attaquer(){
  int attx, atty;
  std::cout << "C'est l'heure de l'attaque" << endl;
  std::cout << "Attaque x" << endl;
  std::cin >> attx; 
  std::cout << "Attaque y" << endl;
  std::cin >> atty; 
  this ->  CarteActeur->Attaquer(attx, atty);
}

void acteur::Placerbateaux( type_bateau bateau){
  int x,y;
  orientation orientation;

  
  
  this -> CarteActeur -> PlacerBateau(x, y, bateau, orientation);
}

