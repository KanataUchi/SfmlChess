#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Piece.h"
#include "Desk.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Enums.h"


class Game{
	sf::RenderWindow m_window;
	sf::Event m_event;
	bool pawn_run[16]{};
	bool rook_run[4]{};
	bool knight_run[4]{};
	bool bishop_run[4]{};
	bool queen_run[2]{};
	bool king_run[2]{};
	bool queue = true;

	Desk  m_desk;
	Piece m_piece;

public:
	void run();
	void init_systems();
	void game_loop();
	void draw_desk();
	void draw_piece();
	void reset_desk();

	void play();

	void isok();
	void w_pawn_run();
	void b_pawn_run();
	void w_rook_run();
	void b_rook_run();
	void w_knight_run();
	void b_knight_run();
	void w_bishop_run();
	void b_bishop_run();
	void w_queen_run();
	void b_queen_run();
	void w_king_run();
	void b_king_run();
	void w_king_desk();
	void w_king_desk_draw();
	void b_king_desk();
};

