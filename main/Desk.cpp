#include "Desk.h"

Desk::Desk() :
    m_cell_width{123.f},
    m_cell_height{123.f}
{}


void Desk::set_position() {
    sf::RectangleShape white(sf::Vector2f(m_cell_height, m_cell_width));
    sf::RectangleShape black(sf::Vector2f(m_cell_height, m_cell_width));
    white.setFillColor(sf::Color::White);
    black.setFillColor(sf::Color::Black);
    int x = 0, y = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0) {
                m_board[i][j] = white;
                m_board[i][j].move(x, y);
                x += m_cell_height;
            }
            else {
                m_board[i][j] = black;
                m_board[i][j].move(x, y);
                x += m_cell_height;
            }
        }
        y += m_cell_width;
        x = 0;
        std::swap(white, black);
    }
}
