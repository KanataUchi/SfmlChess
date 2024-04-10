#include "Piece.h"

void Piece::load_texture() {
	m_textures.at(W_PAWN).loadFromFile("image/w_pawn.png");
	m_textures.at(B_PAWN).loadFromFile("image/b_pawn.png");

	m_textures.at(W_ROOK).loadFromFile("image/w_rook.png");
	m_textures.at(B_ROOK).loadFromFile("image/b_rook.png");

	m_textures.at(W_KNIGHT).loadFromFile("image/w_knight.png");
	m_textures.at(B_KNIGHT).loadFromFile("image/b_knight.png");

	m_textures.at(W_BISHOP).loadFromFile("image/w_bishop.png");
	m_textures.at(B_BISHOP).loadFromFile("image/b_bishop.png");

	m_textures.at(W_QUEEN).loadFromFile("image/w_queen.png");
	m_textures.at(B_QUEEN).loadFromFile("image/b_queen.png");

	m_textures.at(W_KING).loadFromFile("image/w_king.png");
	m_textures.at(B_KING).loadFromFile("image/b_king.png");
}

void Piece::set_texture() {
	for (int i = 0; i < m_pawn.size() / 2; i++) {
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
	for (int i = 2; i < m_rook.size(); i++) {
		m_bishop.at(i).m_sprite.setTexture(m_textures.at(B_BISHOP));
	}

	for (int i = 0; i < m_queen.size() / 2; i++) {
		m_queen.at(i).m_sprite.setTexture(m_textures.at(W_QUEEN));
	}
	for (int i = 1; i < m_rook.size(); i++) {
		m_queen.at(i).m_sprite.setTexture(m_textures.at(B_QUEEN));
	}

	for (int i = 0; i < m_king.size() / 2; i++) {
		m_king.at(i).m_sprite.setTexture(m_textures.at(W_KING));
	}
	for (int i = 1; i < m_king.size(); i++) {
		m_king.at(i).m_sprite.setTexture(m_textures.at(B_KING));
	}
	
}

void Piece::set_position() {

}