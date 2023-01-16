#include "logloop.h"

void run_loop(AppContext ctx, Simulation sim) {
    bool running = true;

    while (running) {
        SDL_Event event;
        const Uint8* state = SDL_GetKeyboardState(NULL);
        SDL_PumpEvents();

        SDL_SetRenderDrawColor(ctx.render, 25, 30, 40, 255);
        SDL_RenderClear(ctx.render);

        handle_input(event, state, &running);
        draw_loop(ctx, sim);

        SDL_RenderDrawPoint(ctx.render, 20, 10);
        SDL_RenderPresent(ctx.render);

        SDL_Delay(16);

    }

}

void draw_loop(AppContext ctx, Simulation sim) {
    for (int i = 0; i < sim.width; i++) {
        for (int j = 0; j < sim.width; j++) {
            if (sim.matrix[i][j] == 0) {
                continue;
            }
            SDL_SetRenderDrawColor(ctx.render, 255, 255, 255, 255);
            SDL_RenderDrawPoint(ctx.render, i, j);
        }
    }
}

Uint8 handle_input(SDL_Event event, const Uint8* state, bool* running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                //And thus, by fucking around, I've learned the usefulness of pointers.
                //Rust would be far too pedantic about this.
                *running = false;
                return 255;
            }
        }
    return 0;
}
