#include "logloop.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>

void run_loop(AppContext ctx, Simulation sim) {
    bool running = true;

    while (running) {
        SDL_Event event;
        const Uint8* state = SDL_GetKeyboardState(NULL);
        SDL_PumpEvents();

        handle_input(event, state, &running, &sim, &ctx);

        if (ctx.painting) {
            int x = ctx.mouse_x;
            int y = ctx.mouse_y;
            for (int r = -ctx.radius / 2; r < ctx.radius / 2; r++) {
                for (int s = -ctx.radius / 2; s < ctx.radius / 2; s++) {
                    int distance_squared = r*r + s*s;
                    if (distance_squared < ((ctx.radius/2)*(ctx.radius/2))) {
                        sim.set_from_coord(x + r, y + s, ctx.erasing ? Simulation::ParticleTypes::NONE : Simulation::ParticleTypes::SAND);
                    }                    
                }
            }
        }

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

Uint8 handle_input(SDL_Event event, const Uint8* state, bool* running, Simulation* sim, AppContext* ctx) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                *running = false;
                return 255;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    ctx->painting = true;
                }
                if (event.button.button == SDL_BUTTON_RIGHT) {
                    ctx->erasing = true;
                }
            }
            if (event.type == SDL_MOUSEBUTTONUP) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    ctx->painting = false;
                }
                if (event.button.button == SDL_BUTTON_RIGHT) {
                    ctx->erasing = false;
                }
            }
            if (event.type == SDL_MOUSEMOTION) {
                ctx->mouse_x = event.motion.x;
                ctx->mouse_y = event.motion.y;
            }
            if (event.type == SDL_MOUSEWHEEL) {
                if (event.wheel.y > 0 && ctx->radius < 64) { //Scroll up
                    ctx->radius++;
                } else if (event.wheel.y < 0 && ctx->radius > 1) { //Scroll down
                    ctx->radius--;
                }
            }
        }
    return 0;
}
