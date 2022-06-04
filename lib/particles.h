#ifndef particles_H
#define particles_H

#include "carte.h"
#include <vector>
#include <iostream>

using namespace std;

typedef struct {
    vector<char> ASCII_frames;
    int current_frame = 0;
    vector<int> direction {0, 0};
    bool alive = false;
    int lifespan = 0;
} Particle;

class Particle_grid {
    private :
    vector<vector<vector<Particle>>> particle_map;

    public :
    Particle_grid();
    void update_grid();
    void update_particles();
    void update_particle(Particle * particle);
    void particle_propagation(Particle * particle, int y, int x, vector<Particle>::iterator position);
    void particles_propagation();
    void spawn_particle(vector<char> frames, vector<int> direction, int max_movement, int x, int y);
    void display_grid();
};

#endif