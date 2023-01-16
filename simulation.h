#pragma once
#include <cstdint>

struct Simulation {
    int width = 640;
    int height = 480;
    int matrix[640][480]; //Current simulation step
    int new_matrix[640][480]; //Next simulation step

    void initialize_matrix() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    Simulation() {
        width = 640;
        height = 480;
        initialize_matrix();

        matrix[120][120] = 1;
    }

    enum ParticleTypes {
        SAND,
        ROCK
    };

    struct ParticleProperties {
        int value = ParticleTypes::SAND;
        uint32_t color = 0xFFFF00;
    };

    const ParticleProperties types[2] = {
        {ParticleTypes::SAND, 0xFFFF00},
        {ParticleTypes::ROCK, 0x404040}
    };
};
