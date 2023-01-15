#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#include "logloop.cpp"

int main() {
    AppContext ctx = spawn_win_surf();
    bool running = true;

    run_loop(ctx);

    return 0;
}
