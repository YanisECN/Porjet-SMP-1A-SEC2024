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
#include "IA.h"
#include "particles.h"
#include <iostream>
#include <vector>
#include <ctime>

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

void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}

int main(void){

    //0 - Ecran d'introduction   

    //1 - Initialisation carte et choix du mode de jeu
    Carte carte_principale;

    bool mode = 0;
  
    cout << "                                     |__" << endl;
    cout << "                                     |\\/" << endl;
    cout << "                                     ---" << endl;
    cout << "                                     / | [" << endl;
    cout << "                              !      | |||" << endl;
    cout << "                            _/|     _/|-++'" << endl;
    cout << "                        +  +--|    |--|--|_ |-" << endl;
    cout << "                     { /|__|  |/\\__|  |--- |||__/" << endl;
    cout << "                    +---------------___[}-_===_.\'____               /\\" << endl;
    cout << "                ____`-' ||___-{]_| _[}-  |     |_[___\\==--          \\/   _" << endl;
    cout << " __..._____--==/___]_|__|_____________________________[___\\==--___,-----\' .7" << endl;
    cout << "|                                                                   BB-61/" << endl;
    cout << " \\_______________________________________________________________________|" << endl;
    cout << "SEC2024 - Bataille navalle - C. Jouin, C. Guidon, C. D'Ardhuy, Y. Keto" << endl;

    cout << endl << "Entrez 0 si vous souhaitez jouer contre une IA (indisponible) ou entrez 1 si vous êtes 2 joueurs" << endl;
    cin >> mode;

    joueur acteur1 (&carte_principale);
    joueur acteur2 (&carte_principale);

    //2 - Placement des bateaux Acteur 1
    Clear();

    cout<<endl<<"--JOUEUR 1--"<<endl;
  
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
    acteur1.Placerbateaux(PORTE_AVIONS);
    Clear();
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
    acteur1.Placerbateaux(CROISSEUR);
    Clear();
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
    acteur1.Placerbateaux(CONTRE_TORPILLEUR);
    Clear();
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
    acteur1.Placerbateaux(CONTRE_TORPILLEUR);
    Clear();
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
    acteur1.Placerbateaux(TORPILLEUR);
    acteur1.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');


    //3 - Placement des bateaux Acteur 2
    Clear();
    cout<<endl<<"--JOUEUR 2--"<<endl;
  
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le porte avion (5 cases)"<<endl;
    acteur2.Placerbateaux(PORTE_AVIONS);
    Clear();
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le croiseur (4 cases)"<<endl;
    acteur2.Placerbateaux(CROISSEUR);
    Clear();
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le premier contre-torpilleur (3 cases)"<<endl;
    acteur2.Placerbateaux(CONTRE_TORPILLEUR);
    Clear();
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le second contre-torpilleur (3 cases)"<<endl;
    acteur2.Placerbateaux(CONTRE_TORPILLEUR);
    Clear();
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');
    cout<<endl<<"Placez le torpilleur (2) cases)"<<endl;
    acteur2.Placerbateaux(TORPILLEUR);
    acteur2.Getcarte()->AfficherTypeCase(PARTIE_BATEAU, 'X');

    //4 - Boucle du jeu

    while (victoire(acteur1, acteur2)== 0){
        Clear();
        cout<<"--Au tour du JOUEUR 1--"<<endl;
        acteur1.Getcarte()->AffichierCarte();
        acteur1.Attaquer();
        acteur1.Getcarte()->AffichierCarte();
        Clear();
        cout<<"--Au tour du JOUEUR 2--"<<endl;
        acteur2.Getcarte()->AffichierCarte();
        acteur2.Attaquer();
        acteur2.Getcarte()->AffichierCarte();
    }

    return 0;
}