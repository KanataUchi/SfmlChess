#pragma once

#include <SFML/Graphics.hpp>

class Desk
{
	float m_cell_width;
	float m_cell_height;
	sf::RectangleShape m_board[8][8];
	bool m_is_open[8][8];

public:
	Desk();
	void set_position();
	friend class Game;
	friend class Piece;
};

