#ifndef carte_acteur_h
#define carte_acteur_h

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
    const type_case Getcase(int x, int y)  {return carte->GetCase(x,y);}
      
      };


#endif