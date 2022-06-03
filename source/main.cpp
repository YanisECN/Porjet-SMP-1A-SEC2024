#include <iostream>
using namespace std;
#include "../lib/acteur.h"
#include "../lib/bateau.h"
#include "../lib/carte_acteur.h"
#include "../lib/carte.h"
#include "../lib/case.h"
#include "../lib/joueur.h"


bool victoire(acteur acteur1, acteur acteur2){ 
  
  int compteur1 = 0, compteur2 = 0;
  
  for (int x = 0 ; x < 9 ; x++){
    for (int y = 0 ; y < 9 ; y++){

      if (acteur1.Getcarte()->Getcase(x,y) ==  PARTIE_BATEAU){
        compteur1++;
      }
      if (acteur1.Getcarte()->Getcase(x,y) ==  PARTIE_BATEAU){
        compteur2++;
      }
    }
  }
  if (compteur1 > 0 and compteur2 > 0){ 
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
  
  bool mode=0;
  
  cout<<endl<<"Entrez 0 si vous souhaitez jouer contre une IA ou entrez 1 si vous êtes 2 joueurs"<<endl;
  cin>>mode;

  //if (mode==0){
    //joueur acteur1;
    //ia acteur 2;
    //}
  
  //if (mode==1){
    joueur acteur1 (&carte_principale);
    joueur acteur2 (&carte_principale);
    //}


  //2 - Placement des bateaux Acteur 1
  
  cout<<endl<<"--JOUEUR 1--"<<endl;
  
  acteur1.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
  acteur1.Placerbateaux(porte_avion);

  acteur1.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
  acteur1.Placerbateaux(croiseur);

  acteur1.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
  acteur1.Placerbateaux(contre_torpilleur);

  acteur1.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
  acteur1.Placerbateaux(contre_torpilleur);

  acteur1.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
  acteur1.Placerbateaux(torpilleur);


  //3 - Placement des bateaux Acteur 2

  cout<<endl<<"--JOUEUR 2--"<<endl;
  
  acteur2.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
  acteur2.Placerbateaux(porte_avion);

  acteur2.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
  acteur2.Placerbateaux(croiseur);

  acteur2.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
  acteur2.Placerbateaux(contre_torpilleur);

  acteur2.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
  acteur2.Placerbateaux(contre_torpilleur);

  acteur2.Getcarte()->AffichierCarte();
  cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
  acteur2.Placerbateaux(torpilleur);


  //4 - Boucle du jeu

  while (victoire(acteur1, acteur2)== 0){

    cout<<endl<<"--Au tour du JOUEUR 1--"<<endl;
    acteur2.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
    acteur1.Attaquer();

    cout<<endl<<"--Au tour du JOUEUR 2--"<<endl;
    acteur1.Getcarte()->AfficherTypeCase(TIR_RATE, 'X');
    acteur2.Attaquer();
    }

}