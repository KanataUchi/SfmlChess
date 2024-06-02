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
	bool w_first[1];
	bool b_first[1];
	friend class Piece;
	friend class Game;
};

