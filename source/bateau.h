#include <map>

#ifndef bateau_H
#define bateau_H

enum type_bateau{
    PORTE_AVIONS,
    CROISSEUR,
    CONTRE_TORPILLEUR,
    TORPILLEUR
};

const std::map<type_bateau, int> longueurs_bateau = {
    {PORTE_AVIONS, 5},
    {CROISSEUR, 4},
    {CONTRE_TORPILLEUR, 3},
    {TORPILLEUR,2}
};

#endif