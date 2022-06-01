// #include "lib/bateau.h"
// #include "lib/carte.h"
// #include "lib/carte_acteur.h"
// #include "lib/case.h"
// #include "lib/orientation.h"
// #include "bateau.h"

#include "carte.h"
#include "carte_acteur.h"
#include <iostream>

using namespace std;

int main(void){
    cout << "Debut" << endl;
    Carte * carte = new Carte();

    Carte_acteur * CarteActeur = new Carte_acteur(carte);
    CarteActeur->AffichierCarte();

    CarteActeur->PlacerBateau(4,4, GRAND, NORD);
    CarteActeur->Attaquer(4,6);
    CarteActeur->Attaquer(5,6);

    CarteActeur->AffichierCarte();

    return 0;
}