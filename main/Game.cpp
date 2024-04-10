#include "Game.h"

void Game::game_loop() {
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color(5,150,150,100));
        draw_desk();
        while (m_window.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed)
                m_window.close();
        }
        m_window.display();
    }
}
void Game::init_systems() {
    m_window.create(sf::VideoMode(1920, 1080), "game");


}

void Game::run() {
    init_systems();
    game_loop();
}

void Game::draw_desk() {
    m_desk.set_position();
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++)
        {
            m_window.draw(m_desk.m_board[i][j]);
        }
    }
}
