#include "bateau.h"
#define acteur_h
#include "carte.h"
#include "carte_acteur.h"
#include <iostream>

using namespace std;

class Acteur
{
private:
    /* data */
    Carte_acteur CarteActeur; 
public:
    // Constructeur
    Acteur(Carte* Carte);
    // Méthodes
    void Attaquer(int attx, int atty);
    void Placerbateaux(int x, int y, type_bateau bateau, orientation orientation);

    //Getters/Setters
    int GetCarte(Carte* Carte);

};
