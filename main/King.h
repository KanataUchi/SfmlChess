#pragma once

#include <SFML/Graphics.hpp>

class King
{
	sf::Sprite m_sprite;
	struct position {
		int x;
		int y;
	};
	position m_position;
	bool active_castle;
	friend class Piece;
	friend class Game;
};

