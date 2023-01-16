#include "logloop.cpp"

int main() {
    AppContext ctx = spawn_win_surf();
    bool running = true;

    Simulation sim = Simulation();
    
    run_loop(ctx, sim);

    return 0;
}
