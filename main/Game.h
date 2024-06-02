#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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
	sf::RenderWindow m_window_extra;
	sf::Event m_event;
	bool queue = true;
	bool check = false;
	bool w_draw;
	bool b_draw;
	bool open = true;
	bool w_can = false;
	

	std::vector <bool> m_w_pawn_run;
	std::vector <bool> m_b_pawn_run;
	std::vector <bool> m_w_rook_run;
	std::vector <bool> m_b_rook_run;
	std::vector <bool> m_w_knight_run;
	std::vector <bool> m_b_knight_run;
	std::vector <bool> m_w_bishop_run;
	std::vector <bool> m_b_bishop_run;
	std::vector <bool> m_w_queen_run;
	std::vector <bool> m_b_queen_run;
	std::vector <bool> m_w_king_run;
	std::vector <bool> m_b_king_run;

	Desk  m_desk;
	Piece m_piece;



public:
	int restart;
	void main_menu();

	void run();
	void init_systems(int x,int y);
	void window(int x, int y);
	void game_loop();
	void reference();
	void draw_desk();
	void draw_piece();
	void reset_desk();
	void can_run();

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

	void w_check();
	void b_check();
	void w_is_life();
	void b_is_life();
    void w_checkmate();
	void b_checkmate();
	void draw();

	int w_appear();
	int b_appear();
};

