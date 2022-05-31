#include <iostream>
using namespace std;
#include "../lib/acteur.h"
#include "../lib/bateau.h"
#include "../lib/carte_acteur.h"
#include "../lib/carte.h"
#include "../lib/case.h"
#include "../lib/joueur.h"
#include "../lib/orientation.h"


bool victoire(){ 
  int a=0;
  a++;
  return 1;
  /*
  int compteur1 = 0, compteur2 = 0;
  for (int i = 0 ; i < 9 ; i++){
    for (int j = 0 ; j < 9 ; j++){
      if (carte_acteur1.type_case[i,j] ==  PARTIE_BATEAU){
        compteur1++;
      }
      if (carte_acteur2.type_case[i,j] ==  PARTIE_BATEAU){
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
  */
  }




int main(void){

  //1 - Initialisation carte et choix du mode de jeu

  Carte carte_principale;
  Carte carte_a1;
  Carte carte_a2;
  
  
  
  bool mode=0;
  
  cout<<endl<<"Entrez 0 si vous souhaitez jouer contre une IA ou entrez 1 si vous êtes 2 joueurs"<<endl;
  cin>>mode;

  //if (mode==0){
    //joueur acteur1;
    //ia acteur 2;
    //}
  
  //if (mode==1){
    joueur acteur1;
    joueur acteur2;
    //}


  //2 - Placement des bateaux Acteur 1
  
  cout<<endl<<"--JOUEUR 1--"<<endl;

  carte_a1=acteur1.Getcarte();
  
  carte_a1.AffichierCarte();
  //AffichierCarte(); ACTEUR 1
  cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
  acteur1.Placerbateaux(porte_avion);

  //AffichierCarte(); ACTEUR 1
  cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
  acteur1.Placerbateaux(croiseur);

  //AffichierCarte(); ACTEUR 1
  cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
  acteur1.Placerbateaux(contre_torpilleur);

  //AffichierCarte(); ACTEUR 1
  cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
  acteur1.Placerbateaux(contre_torpilleur);

  //AffichierCarte(); ACTEUR 1
  cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
  acteur1.Placerbateaux(torpilleur);


  //3 - Placement des bateaux Acteur 2

  cout<<endl<<"--JOUEUR 2--"<<endl;
  
  //AffichierCarte(); ACTEUR 2
  cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
  acteur2.Placerbateaux(porte_avion); //0 pour porte avion

  //AffichierCarte(); ACTEUR 2
  cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
  acteur2.Placerbateaux(croiseur); //1 pour porte croiseur

  //AffichierCarte(); ACTEUR 2
  cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
  acteur2.Placerbateaux(contre_torpilleur); //2 pour porte contre-torpilleur

  //AffichierCarte(); ACTEUR 2
  cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
  acteur2.Placerbateaux(contre_torpilleur);

  //AffichierCarte(); ACTEUR 2
  cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
  acteur2.Placerbateaux(torpilleur); //3 pour porte torpilleur


  //4 - Boucle du jeu


  while (victoire()== 0){

    cout<<endl<<"--Au tour du JOUEUR 1--"<<endl;

  //AfficherTypeCase(TIR_RATE, X); ACTEUR 2
    acteur1.Attaquer();

    cout<<endl<<"--Au tour du JOUEUR 2--"<<endl;

    
  //AfficherTypeCase(TIR_RATE, X); ACTEUR 1
    acteur2.Attaquer();

      
    //}

}