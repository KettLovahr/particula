#pragma once
#include <cstdint>

struct Simulation {
    int width = 640;
    int height = 480;
    int matrix[640][480]; //Current simulation step
    int new_matrix[640][480]; //Next simulation step

    Simulation();

    void initialize_matrix();

    void execute_sim_step();

    void copy_matrix();


    enum ParticleTypes {
        NONE,
        SAND,
        ROCK
    };

    struct ParticleProperties {
        int value = ParticleTypes::SAND;
        uint32_t color = 0xFFFF00;
        uint8_t move_to = 0b00000010;
        uint8_t or_else = 0b00000101;
    };

    const ParticleProperties types[3] = {
        {0, 0x000000},
        {ParticleTypes::SAND, 0xFFFF00, 0b00000010, 0b00000101},
        {ParticleTypes::ROCK, 0x404040, 0b00000000, 0b00000000}
    };
};
