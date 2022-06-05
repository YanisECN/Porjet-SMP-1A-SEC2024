#ifndef ACTEUR_H
#define ACTEUR_H

#include "carte.h"
#include "carte_acteur.h"
#include "bateau.h"
#include <iostream>

using namespace std;

//test
class acteur
{
protected :
    /* data */
    Carte_acteur * CarteActeur; 
public :
    // Constructeur
    acteur(Carte * carte);
    // Méthodes
    virtual void Attaquer();
    virtual void Placerbateaux(type_bateau bateau);
    
    Carte_acteur * Getcarte()  {return  CarteActeur;}
};

#endif