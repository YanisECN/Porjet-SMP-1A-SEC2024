#include "carte.h"

Carte::Carte(){
    //Do nothing
}

const type_case Carte::GetCase(int coordx, int coordy){

}

int Carte::SetCase(int coordx, int coordy, type_case new_type){
    
    if(coordx <= CARTE_X && coordy <= CARTE_Y){
        cases[coordx][coordy] = new_type;
        return 0;
    }
    return -1;
}