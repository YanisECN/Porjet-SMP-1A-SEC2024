#ifndef joueur_h
#define joueur_h

#include "acteur.h"

class joueur : public acteur {
public :
    //constructeur
    joueur(Carte * carte);
    void Attaquer() override;
    void Placerbateaux(type_bateau bateau) override;
};

#endif