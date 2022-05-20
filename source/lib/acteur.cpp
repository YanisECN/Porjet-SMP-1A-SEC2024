#include "acteur.h"


void Acteur::Attaquer(int attx , int atty){
    Carte_acteur.Attaquer(attx, atty);
}

void Acteur::Placerbateaux(int x, int y, type_bateau bateau, orientation orientation){

    Carte_acteur.PlacerBateau(x,y);
}
