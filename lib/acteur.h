#ifndef ACTEUR_H
#define ACTEUR_H

#include <iostream>
#include "carte_acteur.h"
using namespace std;

class acteur
{
private:
    /* data */
    Carte_acteur * CarteActeur; 
public:
    // Constructeur
    acteur(Carte * Carte);
    // Méthodes
    virtual void Attaquer();
    virtual void Placerbateaux(type_bateau bateau);
    Carte_acteur* Getcarte()  {return  CarteActeur;}
};

#endif