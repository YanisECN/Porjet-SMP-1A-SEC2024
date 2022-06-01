#include <map>

#ifndef bateau_H
#define bateau_H

enum type_bateau{
    PETIT,
    MOYEN,
    GRAND
};

const std::map<type_bateau, int> longueurs_bateau = {
    {PETIT, 1},
    {MOYEN, 2},
    {GRAND, 3}
};

#endif