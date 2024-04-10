#pragma once

#include <SFML/Graphics.hpp>

class Bishop
{
	sf::Sprite m_sprite;
	struct m_position {
		int x;
		int y;
	};
	bool m_alive;
	friend class Piece;
};
