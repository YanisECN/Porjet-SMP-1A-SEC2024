#ifndef carte_acteur_H
#define carte_acteur_H

#include "carte.h"
#include "bateau.h"
#include "orientation.h"

class Carte_acteur{

    public:
    Carte * carte;

    //Constructeur
    Carte_acteur(Carte * carte_principale);

    //Fonctions
    void Attaquer(int coordx, int coordy);
    void PlacerBateau(int coordx, int coordy, type_bateau bateau, orientation orientation);

    bool isColliding(int coordx, int coordy, orientation orientation, int longueur);

    void AfficherTypeCase(type_case type, char caractere);
    void AffichierCarte();
};

#endif