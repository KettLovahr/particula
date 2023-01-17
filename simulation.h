#pragma once
#include <cstdint>

struct Simulation {
    int width = 640;
    int height = 480;
    unsigned long long iterations = 0;
    int matrix[640][480]; //Current simulation step
    int new_matrix[640][480]; //Next simulation step

    Simulation();

    //This will fill the matrix with zeroes so that it may be safely used in subsequent operations
    void initialize_matrix();

    //Executes one step of the simulation across the entire matrix.
    void execute_sim_step();

    //Will copy the value of new_matrix onto the main matrix for display
    void copy_matrix();

    //Function to safely fetch a value from the matrix without going out of bounds.
    int get_from_coord(int x, int y);
    //Function to safely set a value on the matrix without going out of bounds.
    bool set_from_coord(int x, int y, int value);

    bool check_collision(int x, int y, int bit);

    int choose_from_fork(int x, int y, int move_to);

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

    const int COL_POSITIONS[8][2] = {
        {-1, -1},
        { 0, -1},
        { 1, -1},
        {-1,  0},

        { 1,  0},
        {-1,  1},
        { 0,  1},
        { 1,  1},
    };
};
