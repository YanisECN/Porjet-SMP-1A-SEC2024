#include "carte_acteur.h"

Carte_acteur::Carte_acteur(Carte * carte){
    this->carte = carte;
    carte->AddActeur(&map_id);   
    this->particles = new Particle_grid();
}

int Carte_acteur::Attaquer(int coordx, int coordy){
    int rslt = 0;   // 0 : miss, 1 : success, 
    if(coordx <= CARTE_X && coordy <= CARTE_Y && coordx >= 0 && coordy >= 0){
        switch (carte -> GetCase(carte->GetCarteEnemyId(map_id), coordx, coordy))
        {
        case PARTIE_BATEAU:
            //std::cout << "Bateau touché !" << std::endl;
            carte -> SetCase(carte->GetCarteEnemyId(map_id),coordx, coordy, PARTIE_BATEAU_DETRUITE);
            rslt = 1;
            break;
        
        case MER:
            //std::cout << "Tir raté !" << std::endl;
            carte -> SetCase(carte->GetCarteEnemyId(map_id), coordx, coordy, TIR_RATE);
            break;

        case TIR_RATE:
            //std::cout << "Vous aviez déja tirer dans l'eau ici !" << std::endl;
            break;

        case PARTIE_BATEAU_DETRUITE:
            //std::cout << "Vous avez déja touché cette partie du bateau ennemi !" << std::endl;
            break;

        default:
            break;
        }
    }
    return rslt;
}

bool Carte_acteur::isColliding( int coordx, int coordy, orientation orientation, int longueur){
    for(int i = 0; i < longueur; i++){
        switch (orientation)
        {
        case SUD:
            //std::cout << "Longueur : " << longueur << ", case type : " << carte -> GetCase(map_id, coordx, coordy + i) << ", " << (coordy + i) <<std::endl;
            if(CARTE_Y <= (coordy + i) || carte -> GetCase(map_id,coordx, coordy + i) != MER){
                return true;
            }
            break;
        case OUEST:
            if(0 > (coordx - i) || carte -> GetCase(map_id, coordx - i, coordy) != MER){
                return true;
            }
            break;
        case NORD:
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
            case SUD:
                carte -> SetCase(map_id, coordx, coordy + i, PARTIE_BATEAU);
                break;
            case OUEST:
                carte -> SetCase(map_id, coordx - i, coordy, PARTIE_BATEAU);
                break;
            case NORD:
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

void Carte_acteur :: AfficherTypeCase(type_case type, char caractere, int id_map){
    int target_id;
    if(id_map != -1){
        target_id = id_map;
    } else {
        target_id = this->map_id;
    }

    std::cout << "\t";
    for(int x = 0; x < CARTE_X; x++){
        std::cout << char('A' + x) << " ";
    }
    std::cout << std::endl;

    for(int y = 0; y < CARTE_Y; y++){
        std::cout << y << "\t";
        for(int x = 0; x < CARTE_X; x++){
            if((particles->isAnimationRunning()) && particles->GetParticleAtLocation(x, y).alive && type == TIR_RATE){
                std::cout << particles->GetParticleAtLocation(x, y).ASCII_frames[particles->GetParticleAtLocation(x, y).current_frame];
            }else if(type == TIR_RATE){
                if((carte -> GetCase(target_id, x, y)) == TIR_RATE){
                    std::cout << "X";
                } else if((carte -> GetCase(target_id, x, y)) == PARTIE_BATEAU_DETRUITE){
                    std::cout << "@";
                } else {
                    std::cout << ".";
                }
            } else if(type == PARTIE_BATEAU){
                if((carte -> GetCase(target_id, x, y)) == PARTIE_BATEAU){
                    std::cout << "#";
                } else if((carte -> GetCase(target_id, x, y)) == PARTIE_BATEAU_DETRUITE){
                    std::cout << "@";
                } else if((carte -> GetCase(target_id, x, y)) == TIR_RATE) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            } else {
                if((carte -> GetCase(target_id, x, y)) == type){
                    std::cout << caractere;
                } else {
                    std::cout << ".";
                }
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Carte_acteur :: AffichierCarte(){
    std::cout << "Carte des tirs : " << std::endl;
    AfficherTypeCase(TIR_RATE,'X', carte->GetCarteEnemyId(map_id));
    std::cout << "Carte de la flotte : " << std::endl;
    AfficherTypeCase(PARTIE_BATEAU, 'X');
}

vector<vector<type_case>> Carte_acteur::GetCarte(){
    return carte->GetCarte(map_id);
}

Particle_grid * Carte_acteur::GetParticleSystem(){
    return this->particles;
}

void Carte_acteur::Clear_console()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Carte_acteur::sleep_anim(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}