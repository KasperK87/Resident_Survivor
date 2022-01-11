#pragma once

#ifndef _HEADER_AAA
#define _HEADER_AAA

#include "Engine.h"
#include "libtcod.h"
#include "Actor.h"
#include "Map.h"
#include "SDL.h"


Engine::Engine() {
		player = new Actor(40, 25, 64, tcod::ColorRGB(TCOD_white));
		actors.push(player);
		actors.push(new Actor(60, 13, 64, tcod::ColorRGB(TCOD_yellow)));
		map = new Map(100, 34);
	}
	//~Engine();
	void Engine::update() {
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
                    player->y--;
                    break;
                case SDLK_DOWN:
                    player->y++;
                    break;
                case SDLK_LEFT:
                    player->x--;
                    break;
                case SDLK_RIGHT:
                    player->x++;
                    break;
                default:break;
                }
            default:break;
            }
        }
	}
    void Engine::render(tcod::Console& con) {
        // Rendering.
        con.clear();

        //draw playing field
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 33; j++) {
                if (i >= 21 && j >= 3 && j != 34) con.at({ i,j }).ch = '.';
            }

        //draw map
        // draw the map
        map->render(con);
    
        // draw the actors
        for (auto actor : actors) {
            actor->render(con);
        }
    }

    Engine::~Engine() {
        actors.clearAndDelete();
        delete map;
    }

#endif