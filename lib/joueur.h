#include <iostream>
#include "acteur.h"

class joueur : public acteur{
private:
  Carte_acteur * CarteActeur; 
public :
//constructeur
    void Attaquer();
    void Placerbateaux(int x, int y, type_bateau bateau, orientation orientation);

};