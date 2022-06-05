#include "particles.h"

Particle_grid::Particle_grid(){
    vector<vector<vector<Particle>>> map(CARTE_Y, vector<vector<Particle>>(CARTE_X, vector<Particle>(0, Particle())));
    this->particle_map = map;
}

void Particle_grid::update_grid(){
    update_particles();
    particles_propagation();
}

void Particle_grid::reset_particles(){
    vector<vector<vector<Particle>>> map(CARTE_Y, vector<vector<Particle>>(CARTE_X, vector<Particle>(0, Particle())));
    this->particle_map = map;
}

void Particle_grid::update_particles(){
    vector<vector<vector<Particle>>>::iterator y_iterator;
    vector<vector<Particle>>::iterator x_iterator;
    vector<Particle>::iterator overlapping_particles_iterator;
    this->animation_running = false;
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
                if(overlapping_particles_iterator->alive && overlapping_particles_iterator->can_be_propagated && !overlapping_particles_iterator->juste_propagated){
                    particle_propagation(&(*overlapping_particles_iterator), y, x, overlapping_particles_iterator);
                }
            }
            x++;
        }
        y++;
    }
}

void Particle_grid::update_particle(Particle * particle){
    if(particle->alive && (particle->current_frame) < (particle->ASCII_frames.size() - 1) && particle->lifespan > 0){
        particle->current_frame += 1;
        this->animation_running = true;
        particle->juste_propagated = false;
    } else {
        particle->alive = false;
    }
}

void Particle_grid::particle_propagation(Particle * particle, int y, int x, vector<Particle>::iterator position){
    Particle new_particle = *particle;
    particle->can_be_propagated = false;
    new_particle.current_frame = 0;
    new_particle.lifespan -= 1;
    new_particle.can_be_propagated = true;
    new_particle.juste_propagated = true;
    if(particle->alive){
        if((x + particle->direction[0]) < CARTE_X && (x + particle->direction[0]) >= 0){
            if((y + particle->direction[1]) < CARTE_Y && (y + particle->direction[1]) >= 0){
                particle_map[y + particle->direction[1]][x + particle->direction[0]].push_back(new_particle);
            }
        }
    }
}

void Particle_grid::spawn_particle(vector<char> frames, vector<int> direction, int max_movement, int x, int y){
    Particle particle = Particle();
    particle.alive = true;
    particle.ASCII_frames = frames;
    particle.lifespan = max_movement;
    if(direction[0] == 0 && direction[1] == 0){
        particle.can_be_propagated = false;
    } else {
        particle.can_be_propagated = true;
    }
    particle.direction = direction;
    this->particle_map[y][x].push_back(particle);
    this->animation_running = true;
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

bool Particle_grid::isAnimationRunning(){
    return this->animation_running;
}

Particle Particle_grid::GetParticleAtLocation(int x, int y){
    if(particle_map[y][x].size() != 0){
        return particle_map[y][x].at(0);
    }
    Particle * defaultp = new Particle();
    defaultp->alive = false;
    return * defaultp;
}