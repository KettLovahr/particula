#include "simulation.h"
#include <cstdint>
#include <cstdio>


Simulation::Simulation() {
    width = 640;
    height = 480;
    initialize_matrix();

    matrix[120][120] = 1;
}

void Simulation::initialize_matrix() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            matrix[i][j] = 0;
            new_matrix[i][j] = 0;
        }
    }
}

void Simulation::execute_sim_step() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            switch (matrix[i][j]) {
                case ParticleTypes::SAND:
                    if (j < height - 2){
                        new_matrix[i][j] = ParticleTypes::NONE;
                        new_matrix[i][j+1] = ParticleTypes::SAND;
                    }
                    break;
            }
        }
    }

    copy_matrix();
}

void Simulation::copy_matrix() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}
