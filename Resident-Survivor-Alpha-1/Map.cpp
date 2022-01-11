#include "libtcod.h"
#include "Map.h"

Map::Map(int width, int height) : width(width), height(height) {
	tiles = new Tile[width * height];
	/*
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			tiles[i + j * width].canWalk = true;
	*/
	setWall(30, 22);
	setWall(50, 22);
	
}

Map::~Map() {
	delete[] tiles;
}

bool Map::isWall(int x, int y) const {
	return !tiles[x + y * width].canWalk;
}

void Map::setWall(int x, int y) {
	tiles[x + y * width].canWalk = false;
}

void Map::render(tcod::Console& con) const {
	static const tcod::ColorRGB darkWall(0, 0, 100);
	static const tcod::ColorRGB darkGround(50, 50, 150);

	for (int x = 21; x < width; x++) {
		for (int y = 3; y < height-1; y++) {
			con.at({ x,y }).bg = isWall(x, y) ? darkWall : darkGround;
		}
	}
}