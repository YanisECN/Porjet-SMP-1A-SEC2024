#ifndef bateau_h
#define bateau_h
#include <map>

enum type_bateau{
    porte_avion,
    croiseur,
    contre_torpilleur, 
    torpilleur
};

std::map<type_bateau, int> longueurs_bateau = {
    {porte_avion, 5},
    {croiseur, 4},
    {contre_torpilleur, 3},
    {torpilleur, 2}
};

#endif