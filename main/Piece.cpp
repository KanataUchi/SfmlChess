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
	

	for (int i = 0; i < m_pawn.size()/2; i++) {
		m_pawn.at(i).m_sprite.setTexture(m_textures.at(W_PAWN));
	}
	for (int i = 8; i < m_pawn.size(); i++) {
		m_pawn.at(i).m_sprite.setTexture(m_textures.at(B_PAWN));
	}

	for (int i = 0; i < m_rook.size() / 2; i++) {
		m_rook.at(i).m_sprite.setTexture(m_textures.at(W_ROOK));
	}
	for (int i = 2; i < m_rook.size(); i++) {
		m_rook.at(i).m_sprite.setTexture(m_textures.at(B_ROOK));
	}
	
	for (int i = 0; i < m_knight.size() / 2; i++) {
		m_knight.at(i).m_sprite.setTexture(m_textures.at(W_KNIGHT));
	}
	for (int i = 2; i < m_knight.size(); i++) {
		m_knight.at(i).m_sprite.setTexture(m_textures.at(B_KNIGHT));
	}
	
	for (int i = 0; i < m_bishop.size() / 2; i++) {
		m_bishop.at(i).m_sprite.setTexture(m_textures.at(W_BISHOP));
	}
	for (int i = 2; i < m_bishop.size(); i++) {
		m_bishop.at(i).m_sprite.setTexture(m_textures.at(B_BISHOP));
	}
	
	for (int i = 0; i < m_queen.size() / 2; i++) {
		m_queen.at(i).m_sprite.setTexture(m_textures.at(W_QUEEN));
	}
	for (int i = 1; i < m_queen.size(); i++) {
		m_queen.at(i).m_sprite.setTexture(m_textures.at(B_QUEEN));
	}
	
	for (int i = 0; i < m_king.size() / 2; i++) {
		m_king.at(i).m_sprite.setTexture(m_textures.at(W_KING));
	}
	for (int i = 1; i < m_king.size(); i++) {
		m_king.at(i).m_sprite.setTexture(m_textures.at(B_KING));
	}
	
}
void Piece::set_pos(){
	m_desk.set_position();
	for (int i = 0, p = 0; i < m_pawn.size()/2; i++, p++) {
		m_pawn.at(p).m_sprite.setPosition(m_desk.m_board[6][i].getPosition());
		m_pawn.at(p).m_position.x = i;
		m_pawn.at(p).m_position.y = 6;
		m_desk.m_is_open[6][i] = false;
	}
	
	for (int i = 0, p = 8; p < m_pawn.size(); i++, p++) {
		m_pawn.at(p).m_sprite.setPosition(m_desk.m_board[1][i].getPosition());
		m_pawn.at(p).m_position.x = i;
		m_pawn.at(p).m_position.y = 1;
		m_desk.m_is_open[1][i] = false;
	}
	
	for (int i = 0, p = 0; p < m_rook.size() / 2; i+= 7, p++) {
		m_rook.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_rook.at(p).m_position.x = i;
		m_rook.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
		m_rook.at(p).castling[p] = true;
	}
	for (int i = 0, p = 2; p < m_rook.size(); i += 7, p++) {
		m_rook.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_rook.at(p).m_position.x = i;
		m_rook.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
		m_rook.at(p).castling[p] = true;
	}
	
	for (int i = 1, p = 0; p < m_knight.size() / 2; i += 5, p++) {
		m_knight.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_knight.at(p).m_position.x = i;
		m_knight.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 1, p = 2; p < m_knight.size(); i += 5, p++) {
		m_knight.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_knight.at(p).m_position.x = i;
		m_knight.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 2, p = 0; p < m_bishop.size() / 2; i += 3, p++) {
		m_bishop.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_bishop.at(p).m_position.x = i;
		m_bishop.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 2, p = 2; p < m_bishop.size(); i += 3, p++) {
		m_bishop.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_bishop.at(p).m_position.x = i;
		m_bishop.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 3, p = 0; p < m_queen.size() / 2; i += 1, p++) {
		m_queen.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_queen.at(p).m_position.x = i;
		m_queen.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
	}
	for (int i = 3, p = 1; p < m_queen.size(); i += 1, p++) {
		m_queen.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_queen.at(p).m_position.x = i;
		m_queen.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
	}
	
	for (int i = 4, p = 0; p < m_king.size() / 2; i += 1, p++) {
		m_king.at(p).m_sprite.setPosition(m_desk.m_board[7][i].getPosition());
		m_king.at(p).m_position.x = i;
		m_king.at(p).m_position.y = 7;
		m_desk.m_is_open[7][i] = false;
		m_king.at(p).active_castle = true;
	}
	for (int i = 4, p = 1; p < m_king.size(); i += 1, p++) {
		m_king.at(p).m_sprite.setPosition(m_desk.m_board[0][i].getPosition());
		m_king.at(p).m_position.x = i;
		m_king.at(p).m_position.y = 0;
		m_desk.m_is_open[0][i] = false;
		m_king.at(p).active_castle = true;
	}
}
