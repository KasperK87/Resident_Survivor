#include "libtcod.h"
#include "Actor.h"

Actor::Actor(int x, int y, int ch, const tcod::ColorRGB& col) :
	x(x), y(y), ch(ch), col(col) {
}

void Actor::render(tcod::Console con) const {
	auto& p = con.at({ x, y });
	p.ch = ch;
	p.fg = col;
	
	//tcod::print(con, {x, y}, "@", TCOD_white, std::nullopt);
}