// Resident-Survivor-Alpha-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SDL.h>
#include <libtcod.h>
#include <cstdlib>

int main(int argc, char** argv) {
    auto params = TCOD_ContextParams{};
    params.tcod_version = TCOD_COMPILEDVERSION;
    params.argc = argc;
    params.argv = argv;
    params.vsync = 1;
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    params.window_title = "Resident:Survivor";

    auto console = tcod::Console{100,34};
    params.console = console.get();

    auto context = tcod::new_context(params);

    //player
    int playerx = 10, playery = 10;

    // Game loop.
    while (true) {
        // Rendering.
        console.clear();
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 33; j++) {
                if (i >= 21 && j >= 3 && j != 34) console.at({i,j}).ch = '.';
            }
        /*for (auto& tile : console) {
            if (tile. > 21)
                tile.ch = '.';
        }
        */
        auto& player = console.at({ playerx, playery });
        player.fg = { 255, 0, 0};
        player.ch = '@';
        //tcod::print(console, { playerx, playery }, "@", TCOD_white, std::nullopt);
      
        context->present(console);

        // Handle input.
        SDL_Event event;
        SDL_WaitEvent(nullptr);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                std::exit(EXIT_SUCCESS);
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                    case SDLK_8:
                        playery--;
                        break;
                    case SDLK_DOWN:
                        playery++;
                        break;
                    case SDLK_LEFT:
                        playerx--;
                        break;
                    case SDLK_RIGHT:
                        playerx++;
                        break;
                default:break;
                }
            default:break;
            }
        }
    }
    return 0;
}