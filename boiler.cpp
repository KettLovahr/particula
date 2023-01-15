#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

struct AppContext {
    SDL_Window* window;
    SDL_Surface* surf;
};

AppContext spawn_win_surf() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Particula", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface* surf = SDL_GetWindowSurface(window);
    AppContext ctx = {window, surf};
    return ctx;
}
