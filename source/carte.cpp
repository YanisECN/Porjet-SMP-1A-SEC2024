#include "carte.h"
#include <iostream>

Carte::Carte(){
}

const type_case Carte::GetCase(int map_id, int coordx, int coordy){
    if(coordx <= CARTE_X && coordy <= CARTE_Y){
        return cartes.at(map_id).at(coordy).at(coordx);
    }
    return CASE_NULL;
}

int Carte::SetCase(int map_id, int coordx, int coordy, type_case new_type){
    
    if(coordx <= CARTE_X && coordy <= CARTE_Y){
        cartes.at(map_id).at(coordy).at(coordx) = new_type;
        return 0;
    }
    return -1;
}

void Carte::AddActeur(int * map_id){
    *map_id = cartes.size() + 1;
    vector<vector<type_case>> cases(CARTE_Y, vector<type_case>(CARTE_X, MER));
    this -> cartes.insert({*map_id, cases});
}

int Carte::GetCarteEnemyId(int map_id) {
    std::map<int, vector<vector<type_case>>>::iterator iterator;
    for(iterator = this -> cartes.begin(); iterator != this -> cartes.end(); iterator++){
        if(iterator->first != map_id){
            return iterator->first;
        }
    }
}

vector<vector<type_case>> Carte::GetCarte(int map_id) const{
    return cartes.at(map_id);
}