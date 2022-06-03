#include "../lib/acteur.h"


acteur::acteur(Carte * Carte){
  this -> CarteActeur  = new Carte_acteur(Carte);
}
