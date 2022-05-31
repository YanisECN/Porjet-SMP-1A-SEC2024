#include "bateau.h"
#define acteur_h
#include "carte.h"
#include "carte_acteur.h"
#include <iostream>

using namespace std;

class acteur
{
private:
    /* data */
    Carte_acteur * CarteActeur; 
public:
    // Constructeur
    Acteur(Carte * Carte);
    // Méthodes
    virtual void Attaquer();
    virtual void Placerbateaux( type_bateau bateau);

};
