#include "simulation.h"
#include <cstdint>
#include <cstdio>
#include <cstring>


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
            if (get_from_coord(i, j) == 0) {continue;}

            if (!check_collision(i, j, types[get_from_coord(i, j)].move_to)) {
                if (set_from_coord(i, j + 1, get_from_coord(i, j))) {
                    set_from_coord(i, j, ParticleTypes::NONE);
                } 
            } else {
                int choice = choose_from_fork(i, j, types[get_from_coord(i, j)].or_else);
                if (set_from_coord(i + COL_POSITIONS[choice][0], j + COL_POSITIONS[choice][1], get_from_coord(i, j))) {
                    set_from_coord(i, j, ParticleTypes::NONE);
                }
            }
        }
    }
    iterations++;
    copy_matrix();
}

void Simulation::copy_matrix() {
    memcpy(matrix, new_matrix, sizeof(matrix));
}

int Simulation::get_from_coord(int x, int y) {
    if (x > width || x < 0) {
        return 255;
    }
    if (y > height || y < 0) {
        return 255;
    }
    return matrix[x][y];
}

bool Simulation::set_from_coord(int x, int y, int value) {
    if (x < 0) {return false;}
    if (y < 0) {return false;}
    if (x > width - 1) {return false;}
    if (y > height - 1) {return false;}
    new_matrix[x][y] = value;
    return true;
}


bool Simulation::check_collision(int x, int y, int bit) {
    for (int i = 0; i < 8; i++) {
        if ((bit >> (7-i) & 0x1) == 1) {
            if (get_from_coord(x + COL_POSITIONS[i][0], y + COL_POSITIONS[i][1]) != 0) {
                return true;
            }
        }
    }
    return false;
}

int Simulation::choose_from_fork(int x, int y, int move_to) {
    for (int i = 0; i < 8; i++) {
        if ((move_to >> (7-i) & 0x1) == 1) {
            if (get_from_coord(x + COL_POSITIONS[i][0], y + COL_POSITIONS[i][1]) == 0) {
                return i;
            }
        }
    }
    return -1;
}
