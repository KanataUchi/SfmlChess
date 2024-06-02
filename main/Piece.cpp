#include "Piece.h"

void Piece::init_piece() {
	m_textures.at(W_PAWN).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_pawn.png");
	m_textures.at(B_PAWN).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_pawn.png");
	
	m_textures.at(W_ROOK).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_rook.png");
	m_textures.at(B_ROOK).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_rook.png");

	m_textures.at(W_KNIGHT).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_knight.png");
	m_textures.at(B_KNIGHT).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_knight.png");
	
	m_textures.at(W_BISHOP).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_bishop.png");
	m_textures.at(B_BISHOP).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_bishop.png");
	
	m_textures.at(W_QUEEN).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_queen.png");
	m_textures.at(B_QUEEN).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_queen.png");
	
	m_textures.at(W_KING).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\w_king.png");
	m_textures.at(B_KING).loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\image\\b_king.png");
	
	
	m_w_pawn.resize(8);
	m_b_pawn.resize(8);
	m_w_rook.resize(2);
	m_b_rook.resize(2);
	m_b_knight.resize(2);
	m_w_knight.resize(2);
	m_b_bishop.resize(2);
	m_w_bishop.resize(2);
	m_w_queen.resize(1);
	m_b_queen.resize(1);
	m_b_king.resize(1);
	m_w_king.resize(1);

	for (int i = 0; i < m_w_pawn.size(); i++) {
		m_w_pawn.at(i).m_sprite.setTexture(m_textures.at(W_PAWN));
	}
	for (int i = 0; i < m_b_pawn.size(); i++) {
		m_b_pawn.at(i).m_sprite.setTexture(m_textures.at(B_PAWN));
	}

	for (int i = 0; i < m_w_rook.size(); i++) {
		m_w_rook.at(i).m_sprite.setTexture(m_textures.at(W_ROOK));
	}
	for (int i = 0; i < m_b_rook.size(); i++) {
		m_b_rook.at(i).m_sprite.setTexture(m_textures.at(B_ROOK));
	}
	
	for (int i = 0; i < m_w_knight.size(); i++) {
		m_w_knight.at(i).m_sprite.setTexture(m_textures.at(W_KNIGHT));
	}
	for (int i = 0; i < m_b_knight.size(); i++) {
		m_b_knight.at(i).m_sprite.setTexture(m_textures.at(B_KNIGHT));
	}
	
	for (int i = 0; i < m_w_bishop.size(); i++) {
		m_w_bishop.at(i).m_sprite.setTexture(m_textures.at(W_BISHOP));
	}
	for (int i = 0; i < m_b_bishop.size(); i++) {
		m_b_bishop.at(i).m_sprite.setTexture(m_textures.at(B_BISHOP));
	}
	
	for (int i = 0; i < m_w_queen.size(); i++) {
		m_w_queen.at(i).m_sprite.setTexture(m_textures.at(W_QUEEN));
	}
	for (int i = 0; i < m_b_queen.size(); i++) {
		m_b_queen.at(i).m_sprite.setTexture(m_textures.at(B_QUEEN));
	}
	
	for (int i = 0; i < m_w_king.size(); i++) {
		m_w_king.at(i).m_sprite.setTexture(m_textures.at(W_KING));
	}
	for (int i = 0; i < m_b_king.size(); i++) {
		m_b_king.at(i).m_sprite.setTexture(m_textures.at(B_KING));
	}
	
}

void Piece::vectorsize() {
	
}

void Piece::set_pos(){
	m_desk.set_position();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			m_desk.m_is_open[i][j] = 1;
		}
	}

	for (int i = 0, p = 0; p < m_w_pawn.size(); i++, p++) {
		;
		m_w_pawn.at(i).m_sprite.setPosition(m_desk.m_board[6][i].getPosition());
		m_w_pawn.at(i).m_position.x = i;
		m_w_pawn.at(i).m_position.y = 6;
		m_desk.m_is_open[6][i] = false;
	}
	
	for (int i = 0, p = 0; p < m_b_pawn.size(); i++, p++) {

		m_b_pawn.at(p).m_sprite.setPosition(m_desk.m_board[1][i].getPosition());
		m_b_pawn.at(p).m_position.x = i;
		m_b_pawn.at(p).m_position.y = 1;
		m_desk.m_is_open[1][i] = false;
	}
	
	for (int i = 0, p = 0; p < m_w_rook.size(); i += 7, p++) {
		m_w_rook.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_w_rook.at(p).m_position.x = i;
		m_w_rook.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
		m_w_rook.at(p).w_castling[p] = true;
	}

	for (int i = 0, p = 0; p < m_b_rook.size(); i += 7, p++) {
		m_b_rook.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_b_rook.at(p).m_position.x = i;
		m_b_rook.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
		m_b_rook.at(p).b_castling[p] = true;
	}
	
	for (int i = 1, p = 0; p < m_w_knight.size(); i += 5, p++) {
		m_w_knight.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_w_knight.at(p).m_position.x = i;
		m_w_knight.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 1, p = 0; p < m_b_knight.size(); i += 5, p++) {
		m_b_knight.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_b_knight.at(p).m_position.x = i;
		m_b_knight.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 2, p = 0; p < m_w_bishop.size(); i += 3, p++) {
		m_w_bishop.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_w_bishop.at(p).m_position.x = i;
		m_w_bishop.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 2, p = 0; p < m_b_bishop.size(); i += 3, p++) {
		m_b_bishop.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_b_bishop.at(p).m_position.x = i;
		m_b_bishop.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 3, p = 0; p < m_w_queen.size(); i += 1, p++) {
		m_w_queen.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_w_queen.at(p).m_position.x = i;
		m_w_queen.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 3, p = 0; p < m_b_queen.size(); i += 1, p++) {
		m_b_queen.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_b_queen.at(p).m_position.x = i;
		m_b_queen.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 4, p = 0; p < m_w_king.size(); i += 1, p++) {
		m_w_king.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_w_king.at(p).m_position.x = i;
		m_w_king.at(p).m_position.y = 7;
		m_w_king.at(p).w_first[p] = true;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 4, p = 0; p < m_b_king.size(); i += 1, p++) {
		m_b_king.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_b_king.at(p).m_position.x = i;
		m_b_king.at(p).m_position.y = 0;
		m_b_king.at(p).b_first[p] = true;
		m_desk.m_is_open[0][i] = false;
	}
}

