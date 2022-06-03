#ifndef carte_h
#define carte_h

#include "case.h"

#define CARTE_X 10
#define CARTE_Y 10

class Carte{
    private : 
        type_case cases[CARTE_X][CARTE_Y] = {MER};

    public :
        //Constructeur
        Carte();

        //Accesseurs
        const type_case GetCase(int coordx, int coordy);
        int SetCase(int coordx, int coordy, type_case new_type);
        
};

#endif