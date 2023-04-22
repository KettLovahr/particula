#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

struct AppContext {
    SDL_Window* window;
    SDL_Surface* surf;
    SDL_Renderer* render;
    bool painting = false;
    int mouse_x = 0;
    int mouse_y = 0;
    int radius = 5;
};

AppContext spawn_win_surf() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Particula", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface* surf = SDL_GetWindowSurface(window);
    SDL_Renderer* render = SDL_GetRenderer(window);
    AppContext ctx = {window, surf, render};
    return ctx;
}
