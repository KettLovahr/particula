#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include "boiler.cpp"
#include "simulation.cpp"


void run_loop(AppContext ctx, Simulation sim);

void draw_loop(AppContext ctx, Simulation* sim);

Uint8 handle_input(SDL_Event event, const Uint8* state, bool* running, Simulation* sim);
