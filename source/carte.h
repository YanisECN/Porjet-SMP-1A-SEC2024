#ifndef carte_H
#define carte_H

#include "case.h"
#include <vector>
#include <map>

using namespace std;

#define CARTE_X 10
#define CARTE_Y 10

class Carte{
    private : 
        std::map<int, vector<vector<type_case>>> cartes;

    public :
        //Constructeur
        Carte();

        //Accesseurs
        const type_case GetCase(int map_id, int coordx, int coordy);
        int SetCase(int map_id, int coordx, int coordy, type_case new_type);

        void AddActeur(int * map_id);
        int GetCarteEnemyId(int map_id);

        vector<vector<type_case>> GetCarte(int map_id) const;
};

#endif