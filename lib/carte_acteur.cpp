#include "carte_acteur.h"

Carte_acteur::Carte_acteur(Carte * carte){
    this->carte = carte;
    carte->AddActeur(&map_id);
}

void Carte_acteur::Attaquer(int coordx, int coordy){
    if(coordx <= CARTE_X && coordy <= CARTE_Y){
        switch (carte -> GetCase(carte->GetCarteEnemyId(map_id), coordx, coordy))
        {
        case PARTIE_BATEAU:
            std::cout << "Bateau touché !" << std::endl;
            carte -> SetCase(carte->GetCarteEnemyId(map_id),coordx, coordy, PARTIE_BATEAU_DETRUITE);
            carte -> SetCase(map_id, coordx, coordy, TIR_REUSSI);
            break;
        
        case MER:
            std::cout << "Tir raté !" << std::endl;
            carte -> SetCase(map_id, coordx, coordy, TIR_RATE);
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

bool Carte_acteur::isColliding( int coordx, int coordy, orientation orientation, int longueur){
    for(int i = 0; i < longueur; i++){
        switch (orientation)
        {
        case NORD:
            std::cout << "Longueur : " << longueur << ", case type : " << carte -> GetCase(map_id, coordx, coordy + i) << ", " << (coordy + i) <<std::endl;
            if(CARTE_Y <= (coordy + i) || carte -> GetCase(map_id,coordx, coordy + i) != MER){
                return true;
            }
            break;
        case EST:
            if(0 > (coordx - i) || carte -> GetCase(map_id, coordx - i, coordy) != MER){
                return true;
            }
            break;
        case SUD:
            if(0 > (coordy - i) || carte -> GetCase(map_id, coordx, coordy - i) != MER){
                return true;
            }
            break;
        default:    // Ouest (default)
            if(CARTE_X <= (coordx + i) || carte -> GetCase(map_id, coordx + i, coordy) != MER){
                return true;
            }
            break;
        }
    }

    return false;
}

void Carte_acteur::PlacerBateau(int coordx, int coordy, type_bateau bateau, orientation orientation){
    int longueur = longueurs_bateau.at(bateau);

    if(!isColliding(coordx, coordy, orientation, longueur)){
        for(int i = 0; i < longueur; i++){
            switch (orientation)
            {
            case NORD:
                carte -> SetCase(map_id, coordx, coordy + i, PARTIE_BATEAU);
                break;
            case EST:
                carte -> SetCase(map_id, coordx - i, coordy, PARTIE_BATEAU);
                break;
            case SUD:
                carte -> SetCase(map_id, coordx, coordy - i, PARTIE_BATEAU);
                break;
            default:    // Ouest (default)
                carte -> SetCase(map_id, coordx + i, coordy, PARTIE_BATEAU);
                break;
            }
        }
    } else {
        std::cout << "ERROR! Collision!" << std::endl;
    }
}

void Carte_acteur :: AfficherTypeCase(type_case type, char caractere){
    std::cout << "\t";
    for(int x = 0; x < CARTE_X; x++){
        std::cout << x << "\t";
    }
    std::cout << std::endl;

    for(int y = 0; y < CARTE_Y; y++){
        std::cout << y << "\t";
        for(int x = 0; x < CARTE_X; x++){
            if(type == TIR_RATE){
                if((carte -> GetCase(map_id, x, y)) == type){
                    std::cout << caractere << "\t";
                } else if((carte -> GetCase(map_id, x, y)) == TIR_REUSSI){
                    std::cout << "O" << "\t";
                } else {
                    std::cout << "\t";
                }
            } else if(type == PARTIE_BATEAU){
                if((carte -> GetCase(map_id, x, y)) == type){
                    std::cout << caractere << "\t";
                } else if((carte -> GetCase(map_id, x, y)) == PARTIE_BATEAU_DETRUITE){
                    std::cout << "O" << "\t";
                } else {
                    std::cout << "\t";
                }
            } else {
                if((carte -> GetCase(map_id, x, y)) == type){
                    std::cout << caractere << "\t";
                } else {
                    std::cout << "\t";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Carte_acteur :: AffichierCarte(){
    std::cout << "Carte des tirs : " << std::endl;
    AfficherTypeCase(TIR_RATE,'X');
    std::cout << "Carte de la flotte : " << std::endl;
    AfficherTypeCase(PARTIE_BATEAU,'X');
}

vector<vector<type_case>> Carte_acteur::GetCarte(){
    return carte->GetCarte(map_id);
}