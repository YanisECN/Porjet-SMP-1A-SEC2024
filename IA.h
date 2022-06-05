#include <iostream>
#include "acteur.h"
#include "orientation.h"

class IA : public acteur, public Carte {

private:
  Carte_acteur * CarteActeur; 
  bool calcTirIA(int &x,int &y, int X, int Y,int orientation);//calcul le prochain tir de l'IA
  bool verifIAOrientation(Carte *g,int orgX,int orgY,int orientation);//vérifie si l'orientation de tir de l'IA est valide
  
  
public :
//constructeur
    void Attaquer();
    void Placerbateaux(int x, int y, type_bateau bateau, orientation orientation);
    
	
}