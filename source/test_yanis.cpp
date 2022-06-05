#include "bateau.h"
#include "carte.h"
#include "carte_acteur.h"
#include "case.h"
#include "orientation.h"
#include <iostream>

using namespace std;

int main(void){
    cout << "Debut" << endl;
    Carte * carte = new Carte();

    Carte_acteur * CarteActeur = new Carte_acteur(carte);
    CarteActeur->AffichierCarte();
    return 0;
}