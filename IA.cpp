#include <stdio.h>
#include <iostream>

//début du code

		/*Partie IA du jeu*/

	int x,y,prevX,prevY,prevOrientation=0,orgX,orgY,orientation=0;

	bool continues = false,iaTouche = false,essaiOppose=true;

	bool termine=false;

		//IA r�aliste

		if(!termine ){

			if(!iaTouche){

				while(!continues){

					y = RAND_NUM(0,this->carteJ->getNumColonnes()-1);
					x = RAND_NUM(0,this->carteJ->getNumLignes()-1);

					if(!this->carteJ->getCase(y,x)->touche)
						continues=true;
				}
				continues=false;		

			}else{

				if(!calcTirIA(x,y,prevX,prevY,orientation)){

					for(int i = 1;i<5;i++){
						if((i==OUEST && orgX == 0) ||
							(i==NORD && orgY == 0) ||
							(i==EST && orgX == this->carteJ->getNumColonnes()-1) ||
							(i==SUD && orgY == this->carteJ->getNumLignes()-1))
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

			this->updateGrille(y,x,false);


			if(verifAppartenance(y,x,1)){
				cout <<"\n!**Un de vos bateaux est touche**!\n";

				if(!iaTouche){
					iaTouche=true;
					orgX=x;
					orgY=y;
					prevX=x;
					prevY=y;

					while(!continues){
						orientation = RAND_NUM(1,4);
						if((orientation==OUEST && x == 0) ||
							(orientation==NORD && y == 0) ||
							(orientation==EST && x == this->carteJ->getNumColonnes()-1) ||
							(orientation==SUD && y == this->carteJ->getNumLignes()-1))
							continue;
						else{

							continues = verifIAOrientation(this->carteJ,orgX,orgY,orientation);

					 }
					}
					continues=false;
					prevOrientation = orientation;
				}

				for(int i=0;i<this->regle->getNombrebateauxParJoueur();i++){

					if(this->listeBatimentsJoueur1[i]->estCoule() && this->listeBatimentsJoueur1[i]->getStatus()){

						this->listeBatimentsJoueur1[i]->setCoule(true);	
						this->joueurs[0]->decrementNumBateaux();
						iaTouche=false;
						orientation=0;
						prevOrientation=0;
						cout <<"\n\n!***!Un de vos "<<this->listeBatimentsJoueur1[i]->getType()<<" a ete coule!***!\n\n";

						for(int i=0;i<this->regle->getNombrebateauxParJoueur();i++){

							if(this->listeBatimentsJoueur1[i]->estPartiellementTouche()){

								_case *temp = this->listeBatimentsJoueur1[i]->getCaseTouchee();

								iaTouche=true;
								orgX = temp->X;
								orgY = temp->Y;
								prevX=orgX;
								prevY=orgY;

								while(!continues){
									orientation = RAND_NUM(1,4);
									if((orientation==OUEST && x == 0) ||
										(orientation==NORD && y == 0) ||
										(orientation==EST && x == this->carteJ->getNumColonnes()-1) ||
										(orientation==SUD && y == this->carteJ->getNumLignes()-1))
										continue;
									else{

										continues = verifIAOrientation(this->carteJ,orgX,orgY,orientation);
									}
								}
								continues=false;
							}

						}
						break;
					}

				}

			}

			if(this->verifVictoire(2)){

				cout << *this->carteJ <<"\n";

				cout <<"\n\n****Le joueur 2 a gagne!****\n\n";
				termine = true;

			}

		}



bool jeu::calcTirIA(int &x,int &y, int X, int Y,int orientation){

	bool retour = true;

	switch(orientation){

		/*calcul des coordonnees du prochain tir en fonction de l'orientation.
		  puis verification de la validite du tir qui suit en second*/

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

	return retour; //renvoi false si la pr�vision � 2 coups n'est pas valide
}

bool jeu::verifIAOrientation(grille *g,int orgX,int orgY,int orientation){

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

void jeu::placerbateau(regles *r){

	int compteur = 0;

	this->listeBatimentsIA = new batiment*[r->totalBateaux/2];

	srand(time(NULL));

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

}