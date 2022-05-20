#include "carte_acteur.h"
#include <iostream>

Carte_acteur::Carte_acteur(Carte * carte_principale){
    this->carte =  carte_principale;
}

void Carte_acteur::Attaquer(int coordx, int coordy){
    if(coordx <= CARTE_X && coordy <= CARTE_Y){
        switch (carte -> GetCase(coordx, coordy))
        {
        case PARTIE_BATEAU:
            std::cout << "Bateau touché !" << std::endl;
            carte -> SetCase(coordx, coordy, PARTIE_BATEAU_DETRUITE);
            break;
        
        case MER:
            std::cout << "Tir raté !" << std::endl;
            carte -> SetCase(coordx, coordy, TIR_RATE);
            break;

        case TIR_RATE:
            std::cout << "Vous aviez déja tirer dans l'eau ici !" << std::endl;
            break;

        case PARTIE_BATEAU_DETRUITE:
            std::cout << "Vous avez déja touché cette partie du bateau ennemi !" << std::endl;
            break;

        default:
            break;
        }
    }
}

bool Carte_acteur::isColliding(int coordx, int coordy, orientation orientation, int longueur){

    for(int i = 0; i < longueur; i++){
        switch (orientation)
        {
        case NORD:
            if(CARTE_Y <= (coordy + i) || carte -> GetCase(coordx, coordy + i) != MER){
                return true;
            }
            break;
        case EST:
            if(0 > (coordx - i) || carte -> GetCase(coordx - i, coordy) != MER){
                return true;
            }
            break;
        case SUD:
            if(0 > (coordy - i) || carte -> GetCase(coordx, coordy - i) != MER){
                return true;
            }
            break;
        default:    // Ouest (default)
            if(CARTE_X <= (coordx + i) || carte -> GetCase(coordx + i, coordy) != MER){
                return true;
            }
            break;
        }
    }
}

void Carte_acteur::PlacerBateau(int coordx, int coordy, type_bateau bateau, orientation orientation){

    int longueur = longueurs_bateau[bateau];

    if(!isColliding(coordx, coordy, orientation, longueur)){
        for(int i = 0; i < longueur; i++){
            switch (orientation)
            {
            case NORD:
                carte -> SetCase(coordx, coordy + 1, PARTIE_BATEAU);
                break;
            case EST:
                carte -> SetCase(coordx - 1, coordy, PARTIE_BATEAU);
                break;
            case SUD:
                carte -> SetCase(coordx, coordy - 1, PARTIE_BATEAU);
                break;
            default:    // Ouest (default)
                carte -> SetCase(coordx + 1, coordy, PARTIE_BATEAU);
                break;
            }
        }
    }
}