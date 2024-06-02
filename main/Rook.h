#pragma once

#include <SFML/Graphics.hpp>

class Rook
{
	sf::Sprite m_sprite;
	struct position {
		int x;
		int y;
	};
	position m_position;
	bool w_castling[2];
	bool b_castling[2];

	friend class Piece;
	friend class Game;
};

