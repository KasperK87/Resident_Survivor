// Resident-Survivor-Alpha-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SDL.h>
#include <libtcod.h>
#include <cstdlib>
#include "Engine.h"

int main(int argc, char** argv) {

	auto params = TCOD_ContextParams{};
	params.tcod_version = TCOD_COMPILEDVERSION;
	//params.argc = argc;
	//params.argv = argv;
	params.vsync = 1;
	params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
	params.window_title = "Resident:Survivor";

	auto console = tcod::Console{ 100,34 };
	params.console = console.get();

	auto context = tcod::new_context(params);

	auto engine = new Engine();

    while (true) {
		engine->update();
        engine->render(console);

		context->present(console);
    }
    return 0;
}