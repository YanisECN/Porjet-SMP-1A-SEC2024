#include "..//source//lib//bateau.h"
#include "..//source//lib//carte.h"
#include "..//source//lib//carte_acteur.h"
#include "..//source//lib//case.h"
#include "..//source//lib//orientation.h"
#include <iostream>

using namespace std;

int main(void){
    cout << "Debut" << endl;
    Carte * carte = new Carte();

    Carte_acteur * CarteActeur = new Carte_acteur(carte);
    CarteActeur->AffichierCarte();
    return 0;
}