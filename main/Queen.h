#pragma once

#include <SFML/Graphics.hpp>

class Queen
{
	sf::Sprite m_sprite;
	struct position {
		int x;
		int y;
	};
	position m_position;
	bool m_alive;
	friend class Piece;
	friend class Game;
};

