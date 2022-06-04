#include "particles.h"

Particle_grid::Particle_grid(){
    vector<vector<vector<Particle>>> map(CARTE_Y, vector<vector<Particle>>(CARTE_X, vector<Particle>(0, Particle())));
    this->particle_map = map;
}

void Particle_grid::update_grid(){
    particles_propagation();
    update_particles();
}

void Particle_grid::update_particles(){
    vector<vector<vector<Particle>>>::iterator y_iterator;
    vector<vector<Particle>>::iterator x_iterator;
    vector<Particle>::iterator overlapping_particles_iterator;
    int y = 0;
    int x;

    for(y_iterator = particle_map.begin(); y_iterator != particle_map.end(); y_iterator++){
        x = 0;
        for(x_iterator = y_iterator->begin(); x_iterator != y_iterator->end(); x_iterator++){
            
            for(overlapping_particles_iterator = x_iterator->begin(); overlapping_particles_iterator != x_iterator->end(); overlapping_particles_iterator++){
                update_particle(&(*overlapping_particles_iterator));
            }
            x++;
        }
        y++;
    }
}

void Particle_grid::particles_propagation(){
    vector<vector<vector<Particle>>>::iterator y_iterator;
    vector<vector<Particle>>::iterator x_iterator;
    vector<Particle>::iterator overlapping_particles_iterator;
    int x;
    int y = 0;

    for(y_iterator = particle_map.begin(); y_iterator != particle_map.end(); y_iterator++){
        x = 0;
        for(x_iterator = y_iterator->begin(); x_iterator != y_iterator->end(); x_iterator++){
            
            for(overlapping_particles_iterator = x_iterator->begin(); overlapping_particles_iterator != x_iterator->end(); overlapping_particles_iterator++){
                particle_propagation(&(*overlapping_particles_iterator), y, x, overlapping_particles_iterator);
            }
            x++;
        }
        y++;
    }
}

void Particle_grid::update_particle(Particle * particle){
    if(particle->alive && particle->current_frame < (particle->ASCII_frames.size() - 1)){
        particle->current_frame += 1;
    } else {
        particle->alive = false;
    }
}

void Particle_grid::particle_propagation(Particle * particle, int y, int x, vector<Particle>::iterator position){
    Particle new_particle = *particle;
    new_particle.current_frame = 0;
    if(new_particle.alive){
        cout << "checking for propagation!"<<endl;
        cout << "direction x : " << particle->direction[0] << ", direction y : " << particle->direction[1] << endl;
        cout <<  "x : " << x << ", y : " << y << endl;
        if((x + particle->direction[0]) < CARTE_X && (x + particle->direction[0]) >= 0){
            cout << "propagation x, ok !"<<endl;
            if((y + particle->direction[1]) < CARTE_Y && (y + particle->direction[1]) >= 0){
                particle_map[y + particle->direction[1]][x + particle->direction[0]].push_back(new_particle);
                cout << "propagated!"<<endl;
            }
        }
    }
}

void Particle_grid::spawn_particle(vector<char> frames, vector<int> direction, int max_movement, int x, int y){
    Particle particle = Particle();
    particle.alive = true;
    particle.ASCII_frames = frames;
    particle.lifespan = max_movement;
    particle.direction = direction;
    this->particle_map[y][x].push_back(particle);
}

void Particle_grid::display_grid(){
    vector<vector<vector<Particle>>>::iterator y_iterator;
    vector<vector<Particle>>::iterator x_iterator;
    vector<Particle>::iterator overlapping_particles_iterator;
    int x;
    int y = 0;

    for(y_iterator = particle_map.begin(); y_iterator != particle_map.end(); y_iterator++){
        x = 0;
        for(x_iterator = y_iterator->begin(); x_iterator != y_iterator->end(); x_iterator++){
            
            if(x_iterator->size() != 0){
                if(x_iterator->at(0).alive){
                    cout << x_iterator->at(0).ASCII_frames[x_iterator->at(0).current_frame];
                } else {
                    cout << " ";
                }
            } else {
                cout << " ";
            }
            cout << " ";
            x++;
        }
        cout << endl;
        y++;
    }
}