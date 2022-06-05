#include "joueur.h"
#include "orientation.h"

joueur::joueur(Carte * carte) : acteur(carte){
}

void joueur::Attaquer(){
  char attx; 
  int atty;
  std::cout << "C'est l'heure de l'attaque" << endl;
  std::cout << "Attaque x" << endl;
  std::cin >> attx; 
  std::cout << "Attaque y" << endl;
  std::cin >> atty; 
  if(attx >= 'A' && attx <= 'Z'){
    attx -= 'A';
  } else if(attx >= 'a' && attx <= 'z'){
    attx -= 'a';
  }

  vector<char> missile{'<', '~', '-'};
  Particle_grid * particle_system = this -> CarteActeur -> GetParticleSystem();
  particle_system->spawn_particle(missile, {-1, 0}, CARTE_X - 1 - attx, 9, atty);
  while(particle_system->isAnimationRunning()){
    this->Getcarte()->Clear_console();
    cout << CARTE_X - 1 - attx <<endl;
    particle_system->update_grid();
    this->Getcarte()->AffichierCarte();
    this->Getcarte()->sleep_anim(.25);
  }
  this->Getcarte()->Clear_console();
  particle_system->reset_particles();

  int rslt = 0;
  rslt = this -> CarteActeur -> Attaquer(attx, atty);

  if(rslt == 1){
    vector<char> wave{'@', '~'};
    particle_system->spawn_particle(wave, {-1,0}, 2, attx, atty);
    particle_system->spawn_particle(wave, {1,0}, 2, attx, atty);

    particle_system->spawn_particle(wave, {0,1}, 2, attx, atty);
    particle_system->spawn_particle(wave, {0,-1}, 2, attx, atty);

    particle_system->spawn_particle(wave, {-1,-1}, 2, attx, atty);
    particle_system->spawn_particle(wave, {1,1}, 2, attx, atty);

    particle_system->spawn_particle(wave, {-1,1}, 2, attx, atty);
    particle_system->spawn_particle(wave, {1,-1}, 2, attx, atty);
   
    while(particle_system->isAnimationRunning()){
      particle_system->update_grid();
      this->Getcarte()->AffichierCarte();
      this->Getcarte()->sleep_anim(.25);
      this->Getcarte()->Clear_console();
    }
  }

  this->Getcarte()->AffichierCarte();
  this->Getcarte()->sleep_anim(.50);
}

void joueur::Placerbateaux(type_bateau bateau){
  char x;
  int y;
  int orient;
  orientation ation;
  
  std::cout << "Coordonnée du bateau en x :" << endl;
  std::cin >> x;
  std::cout << "Coordonnée du bateau en y :" << endl;
  std::cin >> y;

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
  if(x >= 'A' && x <= 'Z'){
    x -= 'A';
  } else if(x >= 'a' && x <= 'z'){
    x -= 'a';
  }
  this -> CarteActeur -> PlacerBateau(x, y, bateau, ation);
}
