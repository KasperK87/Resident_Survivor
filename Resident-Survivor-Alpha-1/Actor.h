#pragma once
class Actor {
public:
	int x, y; // position on map
	int ch; // ascii code
	tcod::ColorRGB col; // color

	Actor(int x, int y, int ch, const tcod::ColorRGB& col);
	
	void render(tcod::Console& con) const;
};