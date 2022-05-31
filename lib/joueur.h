#ifndef joueur_h
#define joueur_h

#include <iostream>
#include "acteur.h"
#include "orientation.h"

class joueur : public acteur{
private:
  Carte_acteur * CarteActeur; 
public :
//constructeur
    joueur();
    joueur(Carte * Carte);
    void Attaquer();
    void Placerbateaux(type_bateau bateau);

};

#endif