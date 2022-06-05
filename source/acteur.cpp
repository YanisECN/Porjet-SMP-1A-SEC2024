#include "acteur.h"

acteur::acteur(Carte * carte){
  this -> CarteActeur = new Carte_acteur(carte);
}

void acteur::Attaquer(){
  cout << "Attaque non définie !" << endl;
}

void acteur::Placerbateaux(type_bateau bateau){
  cout << "Placement des bateaux non défini !" << endl;
}
