#pragma once

#include <SFML/Graphics.hpp>
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
	std::array<Pawn,16> m_pawn;
	std::array <Rook, 4> m_rook;
	std::array <Knight, 4> m_knight;
	std::array <Bishop, 4> m_bishop;
	std::array <Queen, 2> m_queen;
	std::array <King, 2> m_king;

	std::array<sf::Texture, 12> m_textures;

	Desk m_desk;
public:
	void init_piece();
	void set_pos();

	friend class Game;
};

