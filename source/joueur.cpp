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

void acteur::Placerbateaux(type_bateau bateau){
  int x,y;
  int orient;
  orientation orientation;
  
  std::cout << "Coordonnée du bateau en x :" << endl;
  std::cin >> x;
  std::cout << "Coordonnée du bateau en y :" << endl;
  std::cin >> y;

  std::cout << "Saisir l'orientation du bateau" << endl << "NORD : 0 | EST : 1 | SUD : 2 | OUEST : 3" << endl;
  std::cin >> orient;
  switch (orient)
  {
    case 0:
      orientation = NORD;
      break;
    case 1:
      orientation = EST;
      break;
    case 2:
      orientation = SUD;
      break;
    default:    // Ouest (default)
      orientation = OUEST;
      break;
  }
  this -> CarteActeur -> PlacerBateau(x, y, bateau, orientation);
}
