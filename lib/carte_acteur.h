#ifndef carte_acteur_H
#define carte_acteur_H

#include "carte.h"
#include "bateau.h"
#include "orientation.h"
#include <vector>
#include <iostream>

class Carte_acteur{

    private :
    int map_id = -1;
    Carte * carte;

    public :
    //Constructeur
    Carte_acteur(Carte * carte);

    //Fonctions
    void Attaquer(int coordx, int coordy);
    void PlacerBateau(int coordx, int coordy, type_bateau bateau, orientation orientation);

    bool isColliding(int coordx, int coordy, orientation orientation, int longueur);

    void AfficherTypeCase(type_case type, char caractere);
    void AffichierCarte();
};

#endif