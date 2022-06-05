#ifndef ia_h
#define ia_h

#include "acteur.h"

class ia : public acteur {
public :
    //constructeur
    ia(Carte * carte);
    void Attaquer() override;
    void Placerbateaux(type_bateau bateau) override;
};

#endif

