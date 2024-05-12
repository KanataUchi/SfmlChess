#pragma once

#include <SFML/Graphics.hpp>

class Desk
{
	float m_cell_width;
	float m_cell_height;
	sf::RectangleShape m_board[8][8];
	bool m_is_open[8][8]{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	};

	bool m_w_king_can[8][8]{
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1};

public:
	Desk();
	void set_position();
	friend class Game;
	friend class Piece;
};

