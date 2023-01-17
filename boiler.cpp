#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

struct AppContext {
    SDL_Window* window;
    SDL_Surface* surf;
    SDL_Renderer* render;
    bool painting;
    int mouse_x;
    int mouse_y;
};

AppContext spawn_win_surf() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Particula", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Surface* surf = SDL_GetWindowSurface(window);
    SDL_Renderer* render = SDL_GetRenderer(window);
    AppContext ctx = {window, surf, render};
    return ctx;
}
