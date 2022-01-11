#pragma once
#include "libtcod.h"

class Actor;
class Map;

class Engine {
public:
	TCODList<Actor*> actors;
	Actor* player;
	Map* map;

	Engine();
	~Engine();
	void update();
	void render(tcod::Console& con);
};

