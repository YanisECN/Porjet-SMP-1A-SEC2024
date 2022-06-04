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

bool victoire(acteur acteur1, acteur acteur2){ 
  
  int compteur1 = 0, compteur2 = 0;
  
  for (int x = 0 ; x < CARTE_X; x++){
    for (int y = 0 ; y < CARTE_Y; y++){

      if (acteur1.Getcarte()->GetCarte()[y][x] ==  PARTIE_BATEAU){
        compteur1++;
      }
      if (acteur2.Getcarte()->GetCarte()[y][x] ==  PARTIE_BATEAU){
        compteur2++;
      }
    }
  }
  if (compteur1 > 0 && compteur2 > 0){ 
      return 0;
  }
  else if (compteur1 == 0){
      cout<<endl<<"JOUEUR 2 a gagné la partie ! Félicitations !";
      return 1;
  }
  else if (compteur2 == 0){
      cout<<endl<<"JOUEUR 1 a gagné la partie ! Félicitations !";
      return 1;
  }
}

int main(void){
    //1 - Initialisation carte et choix du mode de jeu
    Carte carte_principale;
  
    bool mode = 0;
  
    cout << endl << "Entrez 0 si vous souhaitez jouer contre une IA ou entrez 1 si vous êtes 2 joueurs" << endl;
    cin >> mode;

    joueur acteur1 (&carte_principale);
    joueur acteur2 (&carte_principale);

    //2 - Placement des bateaux Acteur 1
  
    cout<<endl<<"--JOUEUR 1--"<<endl;
  
    acteur1.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
    acteur1.Placerbateaux(PORTE_AVIONS);

    acteur1.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
    acteur1.Placerbateaux(CROISSEUR);

    acteur1.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
    acteur1.Placerbateaux(CONTRE_TORPILLEUR);

    acteur1.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
    acteur1.Placerbateaux(CONTRE_TORPILLEUR);

    acteur1.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
    acteur1.Placerbateaux(TORPILLEUR);


    //3 - Placement des bateaux Acteur 2

    cout<<endl<<"--JOUEUR 2--"<<endl;
  
    acteur2.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
    acteur2.Placerbateaux(PORTE_AVIONS);

    acteur2.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
    acteur2.Placerbateaux(CROISSEUR);

    acteur2.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
    acteur2.Placerbateaux(CONTRE_TORPILLEUR);

    acteur2.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
    acteur2.Placerbateaux(CONTRE_TORPILLEUR);

    acteur2.Getcarte()->AffichierCarte();
    cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
    acteur2.Placerbateaux(TORPILLEUR);


    //4 - Boucle du jeu

    while (victoire(acteur1, acteur2)== 0){
        cout<<endl<<"--Au tour du JOUEUR 1--"<<endl;
        acteur1.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
        acteur1.Attaquer();
        acteur1.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
        cout<<endl<<"--Au tour du JOUEUR 2--"<<endl;
        acteur2.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
        acteur2.Attaquer();
        acteur2.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
    }

    return 0;
}