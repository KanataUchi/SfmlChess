#pragma once

#include <SFML/Graphics.hpp>

class Pawn{
	sf::Sprite m_sprite;
	struct position {
		int x;
		int y;
	};
	position m_position;
	friend class Piece;
	friend class Game;
};

