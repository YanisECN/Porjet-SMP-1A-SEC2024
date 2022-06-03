#include "../lib/joueur.h"
#include "../lib/orientation.h"

#include <iostream>

joueur::joueur(Carte * Carte) : acteur(Carte){
  this -> CarteActeur  = new Carte_acteur(Carte);
}

void acteur::Attaquer(){
  int attx, atty;
  std::cout << "C'est l'heure de l'attaque" << endl;
  std::cout << "Attaque x" << endl;
  std::cin >> attx; 
  std::cout << "Attaque y" << endl;
  std::cin >> atty; 
  this ->  CarteActeur->Attaquer(attx, atty);
}

void acteur::Placerbateaux(type_bateau bateau){
  int x,y;
  int orient;
  orientation ation;
  
  std::cout << "Coordonnée du bateau en x :" << endl;
  std::cin >> x;
  std::cout << "Coordonnée du bateau en y :" << endl;
  std::cin >> y;

  std::cout << "Saisir l'orientation du bateau" << endl << "NORD : 0 | EST : 1 | SUD : 2 | OUEST : 3" << endl;
  std::cin >> orient;
  switch (orient)
  {
    case 0:
      ation = orientation::NORD;
      break;
    case 1:
      ation = orientation::EST;
      break;
    case 2:
      ation = orientation::SUD;
      break;
    default:    // Ouest (default)
      ation = orientation::OUEST;
      break;
  }
  this -> CarteActeur -> PlacerBateau(x, y, bateau, ation);
}
