// #include "lib/bateau.h"
// #include "lib/carte.h"
// #include "lib/carte_acteur.h"
// #include "lib/case.h"
// #include "lib/orientation.h"
// #include "bateau.h"

#include "carte.h"
#include "carte_acteur.h"
#include "acteur.h"
#include "joueur.h"
#include <iostream>

using namespace std;

int main(void){
    cout << "Debut" << endl;
    Carte * carte = new Carte();

    acteur * joueur1 = new joueur(carte);
    acteur * joueur2 = new joueur(carte);

    std::cout << "Placement du bateau du joueur 1" << std::endl;
    joueur1->Placerbateaux(MOYEN);
    joueur1->Getcarte()->AffichierCarte();
    std::cout << "Tir du joueur 2 sur le bateau du joueur 1" << std::endl;
    joueur2->Attaquer();
    joueur2->Getcarte()->AffichierCarte();
    std::cout << "Affichage de la carte du joueur 1 maintenant" << std::endl;
    joueur1->Getcarte()->AffichierCarte();

    return 0;
}