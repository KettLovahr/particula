#include "logloop.h"
#include <SDL2/SDL_events.h>

void run_loop(AppContext ctx, Simulation sim) {
    bool running = true;

    while (running) {
        SDL_Event event;
        const Uint8* state = SDL_GetKeyboardState(NULL);
        SDL_PumpEvents();

        handle_input(event, state, &running, &sim);
        sim.execute_sim_step();
        draw_loop(ctx, &sim);

        SDL_RenderPresent(ctx.render);

        SDL_Delay(16);

    }

}

void draw_loop(AppContext ctx, Simulation* sim) {
    SDL_SetRenderDrawColor(ctx.render, 25, 30, 40, 255);
    SDL_RenderClear(ctx.render);

    for (int i = 0; i < sim->width; i++) {
        for (int j = 0; j < sim->height; j++) {
            if (sim->matrix[i][j] == 0) {
                continue;
            }
            SDL_SetRenderDrawColor(
                    ctx.render,
                    (sim->types[sim->matrix[i][j]].color & 0xFF0000) >> 16,
                    (sim->types[sim->matrix[i][j]].color & 0x00FF00) >> 8,
                    (sim->types[sim->matrix[i][j]].color & 0x0000FF) >> 0,
                    255
                );
            SDL_RenderDrawPoint(ctx.render, i, j);
        }
    }
}

Uint8 handle_input(SDL_Event event, const Uint8* state, bool* running, Simulation* sim) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                //And thus, by fucking around, I've learned the usefulness of pointers.
                //Rust would be far too pedantic about this.
                *running = false;
                return 255;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    sim->matrix[x][y] = Simulation::ParticleTypes::SAND;
                }
            }
        }
    return 0;
}
