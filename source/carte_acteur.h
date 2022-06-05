#ifndef carte_acteur_H
#define carte_acteur_H

#include "carte.h"
#include "bateau.h"
#include "orientation.h"
#include "particles.h"
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

class Carte_acteur{

    private :
    int map_id = -1;
    Carte * carte;
    Particle_grid * particles;

    public :

    //Constructeur
    Carte_acteur(Carte * carte);

    //Fonctions
    int Attaquer(int coordx, int coordy);
    void PlacerBateau(int coordx, int coordy, type_bateau bateau, orientation orientation);

    bool isColliding(int coordx, int coordy, orientation orientation, int longueur);

    void AfficherTypeCase(type_case type, char caractere, int id_map = -1);
    void AffichierCarte();

    Particle_grid * GetParticleSystem();

    vector<vector<type_case>> GetCarte();
    void Clear_console();
    void sleep_anim(float seconds);
};

#endif