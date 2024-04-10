#pragma once

#include <map>
#include <SFML/Graphics.hpp>

#include "Piece.h"
#include "Desk.h"

class Game{
	sf::RenderWindow m_window;
	sf::Event m_event;

	Desk  m_desk;
	Piece m_piece;

public:
	void run();
	void init_systems();
	void game_loop();
	void draw_desk();
};

