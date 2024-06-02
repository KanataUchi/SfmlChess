#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <string>

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Enums.h"
#include "Desk.h"

class Piece{
	std::vector <Pawn> m_w_pawn;
	std::vector <Pawn> m_b_pawn;
	std::vector <Rook> m_w_rook;
	std::vector <Rook> m_b_rook;
	std::vector <Knight> m_w_knight;
	std::vector <Knight> m_b_knight;
	std::vector <Bishop> m_w_bishop;
	std::vector <Bishop> m_b_bishop;
	std::vector <Queen> m_w_queen;
	std::vector <Queen> m_b_queen;
	std::vector <King> m_w_king;
	std::vector <King> m_b_king;

	std::array<sf::Texture, 12> m_textures;

	Desk m_desk;
public:
	void init_piece();
	void set_pos();
	void vectorsize();

	friend class Game;
};

