#include <stdio.h>
#include <iostream>
#include "../lib/joueur.h"
#include "../lib/orientation.h"
#include "IA.hpp"


//début du code
#define RAND_NUM(min,max) (rand()%(max-min+1))+min


		/*Partie IA du jeu*/
void acteur::Attaquer(){

  int attx, atty;
  std::cout << "C'est l'heure de l'attaque" << endl;
  attx=RAND_NUM(0,10);
  atty=RAND_NUM(0,10);
  std::cout << " IA Attaque en x... et y..." << endl;
  this ->  CarteActeur->Attaquer(attx, atty);

  /*int x,y,prevX,prevY,prevOrientation=0,orgX,orgY,orientation=0;

bool continues = false,iaTouche = false,essaiOppose=true;

  if(!iaTouche){

				while(!continues){

					y = RAND_NUM(0,this->carteJ->getCase()-1);
					x = RAND_NUM(0,this->carteJ->getCase()-1);

					if(!this->carteJ->getCase(y,x)->touche)
						continues=true;
				}
				continues=false;		

			}else{

				if(!calcTirIA(x,y,prevX,prevY,orientation)){

					for(int i = 1;i<5;i++){
						if((i==OUEST && orgX == 0) ||
							(i==NORD && orgY == 0) ||
							(i==EST && orgX == this->carteJ->getCase()-1) ||
							(i==SUD && orgY == this->carteJ->getCase()-1))
							continue;
						continues |= verifIAOrientation(this->carteJ,orgX,orgY,i);
					}
					continues = !continues;

					if(orientation!=0 && essaiOppose && !continues){

						switch(orientation){

							case NORD: orientation = SUD;break;
							case SUD: orientation = NORD;break;
							case OUEST: orientation = EST;break;
							case EST: orientation = OUEST;break;

						}

					}

					while(!continues){

						if(!essaiOppose)
							orientation = RAND_NUM(1,4);
						else
							essaiOppose = false;

						if((orientation==OUEST && orgX == 0) ||
							(orientation==NORD && orgY == 0) ||
							(orientation==EST && orgX == this->carteJ->getNumColonnes()-1) ||
							(orientation==SUD && orgY == this->carteJ->getNumLignes()-1) ||
							(orientation==prevOrientation))
							continue;
						else{
							prevX=orgX;
							prevY=orgY;

							continues = verifIAOrientation(this->carteJ,orgX,orgY,orientation);
						}
					}
					continues=false;
					prevOrientation = orientation;

				}else{

					prevX=x;
					prevY=y;
					essaiOppose = true;			

				}
			}
        }



			cout <<"\nL'IA tire en ("<<x<<" , "<<y<<") \n";

		}
	}

}
*/


}


	

bool IA::calcTirIA(int &x,int &y, int X, int Y,int orientation){

	bool retour = true;

	switch(orientation){

		/*calcul des coordonnees du prochain tir en fonction de l'orientation.*/
		  

			case OUEST: 
				if((!this->carteJ->getCase(Y,X-1)->occupee) || (X-2<0))
					retour = false;
				else
					if(X-2>=0)
						if(this->carteJ->getCase(Y,X-2)->touche)
							retour = false;
				x=X-1;
				y=Y;
				break;

			case NORD: 
				if((!this->carteJ->getCase(Y-1,X)->occupee) || (Y-2<0))
					retour = false;
				else
					if(Y-2>=0)
						if(this->carteJ->getCase(Y-2,X)->touche)
							retour = false;


				x=X;
				y=Y-1;
				break;



			case EST: 
				if((!this->carteJ->getCase(Y,X+1)->occupee) || (X+2>this->carteJ->getNumColonnes()-1)) 
					retour = false;
				else
					if(X+2>=0)
						if(this->carteJ->getCase(Y,X+2)->touche)
							retour = false;


				x=X+1;
				y=Y;				
				break;

			case SUD: 
				if((!this->carteJ->getCase(Y+1,X)->occupee) || (Y+2>this->carteJ->getNumLignes()-1)) 
					retour = false;
				else
					if(Y+2>=0)
						if(this->carteJ->getCase(Y+2,X)->touche)
							retour = false;

				x=X;
				y=Y+1;

				break;

	}

	return retour; 
}

bool IA::verifIAOrientation(grille *g,int orgX,int orgY,int orientation){

	bool retour;

	switch(orientation){

		case OUEST: g->getCase(orgY,orgX-1)->touche ? retour = false:retour =  true;break;
		case NORD: g->getCase(orgY-1,orgX)->touche ? retour = false:retour =  true;break;
		case EST: g->getCase(orgY,orgX+1)->touche ? retour = false:retour =  true;break;
		case SUD: g->getCase(orgY+1,orgX)->touche ? retour = false:retour =  true;break;

		default: retour = false;

	}

	return retour;
}

void acteur ::Placerbateau(regles *r){


  int x,y;
  int orient;
  orientation ation;
  
  std::cout << "Coordonnée du bateau en x :" << endl;
  x=RAND_NUM(0,10);
  std::cout << "Coordonnée du bateau en y :" << endl;
  y=RAND_NUM(0,10);

  std::cout << "Saisir l'orientation du bateau" << endl << "NORD : 0 | EST : 1 | SUD : 2 | OUEST : 3" << endl;
  std::cin >> orient;
  switch (orient)
  {
    case 0:
      ation = orientation::NORD;
      break;
    case 1:
      ation = orientation::EST;
      break;
    case 2:
      ation = orientation::SUD;
      break;
    default:    // Ouest (default)
      ation = orientation::OUEST;
      break;
  }
  this -> CarteActeur -> PlacerBateau(x, y, bateau, ation);
	/*int compteur = 0;

	this->listeBatimentsIA = new batiment*[r->totalBateaux/2];


	for(int i = 0;i<r->nombrePorteAvions/2;i++){		


		this->listeBatimentsIA[i] = new porteAvion(r->longueurPorteAvion,i+1,2,true);


		do{

			this->carteIA->randomCoordonnee(*this->listeBatimentsIA[i]);
			*this->carteIA += *this->listeBatimentsIA[i];


		}while(!this->carteIA->ajoutEstValide());


		compteur++;

	}

	for(int i = 0;i<r->nombreCroiseurs/2;i++){

		this->listeBatimentsIA[compteur] = new croiseur(r->longueurCroiseurs,i+1,2,true);

		do{

			this->carteIA->randomCoordonnee(*this->listeBatimentsIA[compteur]);
			*this->carteIA += *this->listeBatimentsIA[compteur];


		}while(!this->carteIA->ajoutEstValide());

		compteur++;


	}

	for(int i = 0;i<r->nombreContreTorpilleurs/2;i++){

	
		this->listeBatimentsIA[compteur] = new contreTorpilleur(r->longueurContreTorpilleurs,i+1,2,true);
		do{

			this->carteIA->randomCoordonnee(*this->listeBatimentsIA[compteur]);
			*this->carteIA += *this->listeBatimentsIA[compteur];


		}while(!this->carteIA->ajoutEstValide());
		compteur++;


	}

	for(int i = 0;i<r->nombreSousMarins/2;i++){

		
		this->listeBatimentsIA[compteur] = new sousMarin(r->longueurSousMarins,i+1,2,true);
		do{

			this->carteIA->randomCoordonnee(*this->listeBatimentsIA[compteur]);
			*this->carteIA += *this->listeBatimentsIA[compteur];


		}while(!this->carteIA->ajoutEstValide());
		compteur++;


	}

	for(int i = 0;i<r->nombreTorpilleurs/2;i++){

		this->listeBatimentsIA[compteur] = new torpilleur(r->longueurTorpilleurs,i+1,2,true);

		do{

			this->carteIA->randomCoordonnee(*this->listeBatimentsIA[compteur]);
			*this->carteIA += *this->listeBatimentsIA[compteur];


		}while(!this->carteIA->ajoutEstValide());
		compteur++;
	}
*/

}