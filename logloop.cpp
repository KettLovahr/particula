#include "boiler.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>

void run_loop(AppContext ctx) {
    bool running = true;

    while (running) {
        SDL_UpdateWindowSurface(ctx.window);
        SDL_Event event;
        const Uint8* state = SDL_GetKeyboardState(NULL);
        SDL_PumpEvents();




        while (SDL_PollEvent(&event)) {
            printf("%d\n", event.type);
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
    }

}
