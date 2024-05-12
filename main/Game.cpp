#include "Game.h"

void Game::game_loop() {
    m_piece.init_piece();
    m_desk.set_position();
    m_piece.set_pos();
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color(5,150,150,100));
        draw_desk();
        draw_piece();
        while (m_window.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed) {
                m_window.close();
            }
            king_desk_draw();
            play();
        }
        m_window.display();
    }
}
void Game::init_systems() {
    m_window.create(sf::VideoMode(1000, 1000), "game");
}

void Game::run() {
    init_systems();
    game_loop();
}

void Game::draw_desk() {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++)
        {
            m_window.draw(m_desk.m_board[i][j]);
        }
    }
}

void Game::draw_piece() {
    for (int i = 0; i < 16; i++){
        m_window.draw(m_piece.m_pawn.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_rook.size();i++) {
        m_window.draw(m_piece.m_rook.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_knight.size(); i++) {
        m_window.draw(m_piece.m_knight.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_bishop.size(); i++) {
        m_window.draw(m_piece.m_bishop.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_queen.size(); i++) {
        m_window.draw(m_piece.m_queen.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_king.size(); i++) {
        m_window.draw(m_piece.m_king.at(i).m_sprite);
    }
}

void Game::w_pawn_run() {
    for (int i = 0; i < 8; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_pawn.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_pawn.at(i).m_position.y == 6) {
                        if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x] and m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 2][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 2][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));

                        }
                        else if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x] and !m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 2][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));

                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    else {
                        if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y - 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    pawn_run[i] = true;
                }
                else{
                    pawn_run[i] = false;
                }
            }
        }
        if (pawn_run[i]){
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (y < m_piece.m_pawn.at(i).m_position.y and x == m_piece.m_pawn.at(i).m_position.x) {

                                        reset_desk();

                                        std::swap(m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y][m_piece.m_pawn.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_pawn.at(i).m_position.y = y;
                                        pawn_run[i] = false;
                                        queue = false;
                                    }
                                    if ((m_piece.m_pawn.at(i).m_position.y - y) == 1 and (abs(x - m_piece.m_pawn.at(i).m_position.x) == 1)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y][m_piece.m_pawn.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_pawn.at(i).m_position.y = y;
                                            m_piece.m_pawn.at(i).m_position.x = x;
                                            for (int j = 8; j < 16; j++) {
                                                if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_pawn.at(j).m_position.y = -1;
                                                    m_piece.m_pawn.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 2; j < 4; j++) {
                                                if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_rook.at(j).m_position.y = -1;
                                                    m_piece.m_rook.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_knight.at(j).m_position.y = -1;
                                                    m_piece.m_knight.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_bishop.at(j).m_position.y = -1;
                                                    m_piece.m_bishop.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 1; j < 2; j++) {
                                                if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_queen.at(j).m_position.y = -1;
                                                    m_piece.m_queen.at(j).m_position.x = -1;
                                                }
                                            }
                                            pawn_run[i] = false;
                                            queue = false;
                                        }

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
    
void Game::b_pawn_run() {
    for (int i = 8; i < 16; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_pawn.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_pawn.at(i).m_position.y == 1) {
                        if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x] and m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 2][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 2][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            pawn_run[i] = true;
                        }
                        else if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x] and !m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 2][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            pawn_run[i] = true;
                        }
                        if(!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    else {
                        if (m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            pawn_run[i] = true;
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_pawn.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    pawn_run[i] = true;
                }
                else {
                    pawn_run[i] = false;
                }
            }
        }
        if (pawn_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (y > m_piece.m_pawn.at(i).m_position.y and x == m_piece.m_pawn.at(i).m_position.x) {

                                        reset_desk();

                                        std::swap(m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y][m_piece.m_pawn.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_pawn.at(i).m_position.y = y;
                                        pawn_run[i] = false;
                                        queue = true;
                                    }
                                    if ((y - m_piece.m_pawn.at(i).m_position.y) == 1  and (abs(x - m_piece.m_pawn.at(i).m_position.x) == 1)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_pawn.at(i).m_position.y][m_piece.m_pawn.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_pawn.at(i).m_position.y = y;
                                            m_piece.m_pawn.at(i).m_position.x = x;
                                            for (int j = 0; j < 8; j++) {
                                                if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_pawn.at(j).m_position.y = -1;
                                                    m_piece.m_pawn.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 0; j < 2; j++) {
                                                if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_rook.at(j).m_position.y = -1;
                                                    m_piece.m_rook.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_knight.at(j).m_position.y = -1;
                                                    m_piece.m_knight.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_bishop.at(j).m_position.y = -1;
                                                    m_piece.m_bishop.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 0; j < 1; j++) {
                                                if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_pawn.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_queen.at(j).m_position.y = -1;
                                                    m_piece.m_queen.at(j).m_position.x = -1;
                                                }
                                            }
                                            pawn_run[i] = false;
                                            queue = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_rook_run() {
    for (int i = 0; i <2; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_rook.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_rook.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                            for (int z = 8; z < 16; z++){
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x] ) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));                      
                    }

                    rook_run[i] = true;
                }
                else {
                    rook_run[i] = false;
                }
            }
        }
        if (rook_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.y = y;
                                            m_piece.m_rook.at(i).m_position.x = x;
                                            for (int j = 8; j < 16; j++) {
                                                if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_pawn.at(j).m_position.y = -1;
                                                    m_piece.m_pawn.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 2; j < 4; j++) {
                                                if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_rook.at(j).m_position.y = -1;
                                                    m_piece.m_rook.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_knight.at(j).m_position.y = -1;
                                                    m_piece.m_knight.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_bishop.at(j).m_position.y = -1;
                                                    m_piece.m_bishop.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 1; j < 2; j++) {
                                                if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_queen.at(j).m_position.y = -1;
                                                    m_piece.m_queen.at(j).m_position.x = -1;
                                                }
                                            }
                                            rook_run[i] = false;
                                            queue = false;
                                    }
                                    else {
                                        if (y < m_piece.m_rook.at(i).m_position.y and x == m_piece.m_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.y = y;

                                            rook_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_rook.at(i).m_position.y and x == m_piece.m_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.y = y;

                                            rook_run[i] = false;
                                            queue = false;
                                        }
                                        else if (x < m_piece.m_rook.at(i).m_position.x and y == m_piece.m_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.x = x;

                                            rook_run[i] = false;
                                            queue = false;
                                        }
                                        else if (x > m_piece.m_rook.at(i).m_position.x and y == m_piece.m_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.x = x;

                                            rook_run[i] = false;
                                            queue = false;
                                            m_piece.m_rook.at(i).castling[i] = false;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } 
    }
}

void Game::b_rook_run() {
    for (int i = 2; i < 4; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_rook.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_rook.at(i).m_position.x + 1; j < 8; j++) {
                        if(!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.x - 1; j > -1 ; j--) {
                        if (!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_rook.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    rook_run[i] = true;
                }
                else {
                    rook_run[i] = false;
                }
            }
        }
        if (rook_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_rook.at(i).m_position.y = y;
                                        m_piece.m_rook.at(i).m_position.x = x;
                                        for (int j = 0; j < 8; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 2; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 1; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_rook.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        rook_run[i] = false;
                                        queue = true;
                                    }
                                    else {
                                        if (y < m_piece.m_rook.at(i).m_position.y and x == m_piece.m_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.y = y;

                                            rook_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_rook.at(i).m_position.y and x == m_piece.m_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.y = y;

                                            rook_run[i] = false;
                                            queue = true;
                                        }
                                        else if (x < m_piece.m_rook.at(i).m_position.x and y == m_piece.m_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.x = x;

                                            rook_run[i] = false;
                                            queue = true;
                                        }
                                        else if (x > m_piece.m_rook.at(i).m_position.x and y == m_piece.m_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][m_piece.m_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(i).m_position.x = x;

                                            rook_run[i] = false;
                                            queue = true;
                                            m_piece.m_rook.at(i).castling[i] = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_knight_run() {
    for (int i = 0; i < 2; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_knight.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                       
                    }
                    if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2]) {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    knight_run[i] = true;
                }
                else {
                    knight_run[i] = false;
                }
            }
        }
        if (knight_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if ((abs(m_piece.m_knight.at(i).m_position.y - y) == 2 and abs(m_piece.m_knight.at(i).m_position.x - x) == 1) or (abs(m_piece.m_knight.at(i).m_position.y - y) == 1 and abs(m_piece.m_knight.at(i).m_position.x - x) == 2)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y][m_piece.m_knight.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_knight.at(i).m_position.y = y;
                                            m_piece.m_knight.at(i).m_position.x = x;
                                            for (int j = 8; j < 16; j++) {
                                                if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_pawn.at(i).m_position.y = -1;
                                                    m_piece.m_pawn.at(i).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 2; j < 4; j++) {
                                                if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_rook.at(i).m_position.y = -1;
                                                    m_piece.m_rook.at(i).m_position.x = -1;
                                                }
                                                if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_knight.at(i).m_position.y = -1;
                                                    m_piece.m_knight.at(i).m_position.x = -1;
                                                }
                                                if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_bishop.at(i).m_position.y = -1;
                                                    m_piece.m_bishop.at(i).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 1; j < 2; j++) {
                                                if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_queen.at(i).m_position.y = -1;
                                                    m_piece.m_queen.at(i).m_position.x = -1;
                                                }
                                            }
                                            knight_run[i] = false;
                                            queue = false;
                                        }
                                        else {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y][m_piece.m_knight.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_knight.at(i).m_position.y = y;
                                            m_piece.m_knight.at(i).m_position.x = x;
                                            knight_run[i] = false;
                                            queue = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::b_knight_run() {
    for (int i = 2; i < 4; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_knight.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                    }
                    if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 2 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2]) {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_knight.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else m_desk.m_board[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    knight_run[i] = true;
                }
                else {
                    knight_run[i] = false;
                }
            }
        }
        if (knight_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if ((abs(m_piece.m_knight.at(i).m_position.y - y) == 2 and abs(m_piece.m_knight.at(i).m_position.x - x) == 1) or (abs(m_piece.m_knight.at(i).m_position.y - y) == 1 and abs(m_piece.m_knight.at(i).m_position.x - x) == 2)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y][m_piece.m_knight.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_knight.at(i).m_position.y = y;
                                            m_piece.m_knight.at(i).m_position.x = x;
                                            for (int j = 0; j < 8; j++) {
                                                if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_pawn.at(j).m_position.y = -1;
                                                    m_piece.m_pawn.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 0; j < 2; j++) {
                                                if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_rook.at(j).m_position.y = -1;
                                                    m_piece.m_rook.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_knight.at(j).m_position.y = -1;
                                                    m_piece.m_knight.at(j).m_position.x = -1;
                                                }
                                                if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_bishop.at(j).m_position.y = -1;
                                                    m_piece.m_bishop.at(j).m_position.x = -1;
                                                }
                                            }
                                            for (int j = 0; j < 1; j++) {
                                                if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_knight.at(i).m_sprite.getPosition()) {
                                                    m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                    m_piece.m_queen.at(j).m_position.y = -1;
                                                    m_piece.m_queen.at(j).m_position.x = -1;
                                                }
                                            }
                                            knight_run[i] = false;
                                            queue = true;
                                        }
                                        else {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_knight.at(i).m_position.y][m_piece.m_knight.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_knight.at(i).m_position.y = y;
                                            m_piece.m_knight.at(i).m_position.x = x;
                                            knight_run[i] = false;
                                            queue = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_bishop_run() {
    for (int i = 0; i < 2; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_bishop.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_bishop.at(i).m_position.y + 1,z = m_piece.m_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++,z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j  and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y + 1, z = m_piece.m_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y - 1, z = m_piece.m_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y - 1, z = m_piece.m_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    bishop_run[i] = true;
                }
                else {
                    bishop_run[i] = false;
                }
            }
        }
        if (bishop_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {

                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_bishop.at(i).m_position.y = y;
                                        m_piece.m_bishop.at(i).m_position.x = x;
                                        for (int j = 8; j < 16; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 2; j < 4; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 1; j < 2; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        bishop_run[i] = false;
                                        queue = false;
                                    }
                                    else {
                                        if (y > m_piece.m_bishop.at(i).m_position.y and x > m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_bishop.at(i).m_position.y and x < m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_bishop.at(i).m_position.y and x > m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_bishop.at(i).m_position.y and x < m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::b_bishop_run() {
    for (int i = 2; i < 4; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_bishop.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_bishop.at(i).m_position.y + 1, z = m_piece.m_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y + 1, z = m_piece.m_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y - 1, z = m_piece.m_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_bishop.at(i).m_position.y - 1, z = m_piece.m_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    bishop_run[i] = true;
                }
                else {
                    bishop_run[i] = false;
                }
            }
        }
        if (bishop_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {

                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_bishop.at(i).m_position.y = y;
                                        m_piece.m_bishop.at(i).m_position.x = x;
                                        for (int j = 0; j < 8; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 2; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 1; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_bishop.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        bishop_run[i] = false;
                                        queue = true;
                                    }
                                    else {
                                        if (y > m_piece.m_bishop.at(i).m_position.y and x > m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_bishop.at(i).m_position.y and x < m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_bishop.at(i).m_position.y and x > m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_bishop.at(i).m_position.y and x < m_piece.m_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_bishop.at(i).m_position.y][m_piece.m_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_bishop.at(i).m_position.y = y;
                                            m_piece.m_bishop.at(i).m_position.x = x;

                                            bishop_run[i] = false;
                                            queue = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_queen_run() {
    for (int i = 0; i < 1; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_queen.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_queen.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][j]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][j]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_queen.at(i).m_position.x]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_queen.at(i).m_position.x]) {
                            for (int z = 8; z < 16; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 2; z < 4; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 1; z < 2; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //////
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1, z = m_piece.m_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1, z = m_piece.m_queen.at(i).m_position.x - 1; j < 8 and z > -1 ; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y -1, z = m_piece.m_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y - 1, z = m_piece.m_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 8; f < 16; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 2; f < 4; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 1; f < 2; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    queen_run[i] = true;
                }
                else {
                    queen_run[i] = false;
                }
            }
        }
        if (queen_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_queen.at(i).m_position.y = y;
                                        m_piece.m_queen.at(i).m_position.x = x;
                                        for (int j = 8; j < 16; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 2; j < 4; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 1; j < 2; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        queen_run[i] = false;
                                        queue = false;
                                    }
                                    else {
                                        if (y < m_piece.m_queen.at(i).m_position.y and x == m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_queen.at(i).m_position.y and x == m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (x < m_piece.m_queen.at(i).m_position.x and y == m_piece.m_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (x > m_piece.m_queen.at(i).m_position.x and y == m_piece.m_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        //////////
                                        if (y > m_piece.m_queen.at(i).m_position.y and x > m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_queen.at(i).m_position.y and x < m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_queen.at(i).m_position.y and x > m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_queen.at(i).m_position.y and x < m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::b_queen_run() {
    for (int i = 1; i < 2; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_queen.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_queen.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.y == m_piece.m_queen.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_queen.at(i).m_position.x]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_queen.at(i).m_position.x]) {
                            for (int z = 0; z < 8; z++) {
                                if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 2; z++) {
                                if (m_piece.m_rook.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < 1; z++) {
                                if (m_piece.m_queen.at(z).m_position.x == m_piece.m_queen.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //////
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1, z = m_piece.m_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y + 1, z = m_piece.m_queen.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y - 1, z = m_piece.m_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_queen.at(i).m_position.y - 1, z = m_piece.m_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < 8; f++) {
                                if (m_piece.m_pawn.at(f).m_position.y == j and m_piece.m_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 2; f++) {
                                if (m_piece.m_rook.at(f).m_position.y == j and m_piece.m_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_knight.at(f).m_position.y == j and m_piece.m_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(f).m_position.y == j and m_piece.m_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < 1; f++) {
                                if (m_piece.m_queen.at(f).m_position.y == j and m_piece.m_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    queen_run[i] = true;
                }
                else {
                    queen_run[i] = false;
                }
            }
        }
        if (queen_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_queen.at(i).m_position.y = y;
                                        m_piece.m_queen.at(i).m_position.x = x;
                                        for (int j = 0; j < 8; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 2; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 1; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_queen.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        queen_run[i] = false;
                                        queue = true;
                                    }
                                    else {
                                        if (y < m_piece.m_queen.at(i).m_position.y and x == m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_queen.at(i).m_position.y and x == m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (x < m_piece.m_queen.at(i).m_position.x and y == m_piece.m_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (x > m_piece.m_queen.at(i).m_position.x and y == m_piece.m_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        //////////
                                        if (y > m_piece.m_queen.at(i).m_position.y and x > m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_queen.at(i).m_position.y and x < m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_queen.at(i).m_position.y and x > m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_queen.at(i).m_position.y and x < m_piece.m_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_queen.at(i).m_position.y][m_piece.m_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_queen.at(i).m_position.y = y;
                                            m_piece.m_queen.at(i).m_position.x = x;

                                            queen_run[i] = false;
                                            queue = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_king_run() {
    for (int i = 0; i < 1; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_king.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x]) {
                            for (int x = 2; x < 4; x++) {
                                for (int j = m_piece.m_bishop.at(x).m_position.y + 1, z = m_piece.m_bishop.at(x).m_position.x + 1; j < 8 and z < 8; j++,z++){
                                    if (m_piece.m_king.at(i).m_position.y - 1 != j and m_piece.m_king.at(i).m_position.x != z) {
                                        m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                    }
                                }
                            }
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x ) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                   m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1 and m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1 and m_piece.m_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y + 1 < 8 and m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y+ 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if(m_piece.m_king.at(i).m_position.y + 1 < 8 and m_piece.m_king.at(i).m_position.x + 1 < 8){
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 8; j < 16; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 2; j < 4; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 1; j < 2; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).active_castle) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 2] and m_piece.m_rook.at(1).castling[1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 2] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 3] and m_piece.m_rook.at(0).castling[0]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                    }
                    king_run[i] = true;
                }
            }
        }
        if (king_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    reset_desk();

                                    if (y == m_piece.m_king.at(i).m_position.y and x == m_piece.m_king.at(i).m_position.x + 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1], m_desk.m_is_open[m_piece.m_rook.at(1).m_position.y][m_piece.m_rook.at(1).m_position.x]);
                                            m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(1).m_sprite.setPosition(m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].getPosition());
                                            m_piece.m_rook.at(1).m_position.y = m_piece.m_king.at(i).m_position.y;
                                            m_piece.m_rook.at(1).m_position.x = m_piece.m_king.at(i).m_position.x + 1;
                                            m_piece.m_king.at(i).m_position.y = y;
                                            m_piece.m_king.at(i).m_position.x = x;

                                            m_piece.m_king.at(i).active_castle = false;
                                            king_run[i] = false;
                                            queue = true;
                                    }
                                    else if (y == m_piece.m_king.at(i).m_position.y and x == m_piece.m_king.at(i).m_position.x - 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1], m_desk.m_is_open[m_piece.m_rook.at(0).m_position.y][m_piece.m_rook.at(0).m_position.x]);
                                            m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_rook.at(0).m_sprite.setPosition(m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].getPosition());
                                            m_piece.m_rook.at(0).m_position.y = m_piece.m_king.at(i).m_position.y;
                                            m_piece.m_rook.at(0).m_position.x = m_piece.m_king.at(i).m_position.x - 1;
                                            m_piece.m_king.at(i).m_position.y = y;
                                            m_piece.m_king.at(i).m_position.x = x;

                                            m_piece.m_king.at(i).active_castle = false;
                                            king_run[i] = false;
                                            queue = true;
                                    }
                                    else {

                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;
                                        king_run[i] = false;
                                        queue = true;
                                    }
                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;
                                        for (int j = 8; j < 16; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 2; j < 4; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 1; j < 2; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        king_run[i] = false;
                                        queue = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void Game::b_king_run() {
    for (int i = 1; i < 2; i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_king.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1 and m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y - 1 > -1 and m_piece.m_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y - 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y - 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y + 1 < 8 and m_piece.m_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).m_position.y + 1 < 8 and m_piece.m_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else {
                            for (int j = 0; j < 8; j++) {
                                if (m_piece.m_pawn.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_pawn.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 2; j++) {
                                if (m_piece.m_knight.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_knight.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_bishop.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_bishop.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                                if (m_piece.m_rook.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_rook.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < 1; j++) {
                                if (m_piece.m_queen.at(j).m_position.y == m_piece.m_king.at(i).m_position.y + 1 and m_piece.m_queen.at(j).m_position.x == m_piece.m_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_king.at(i).m_position.y + 1][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_king.at(i).active_castle) {
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 2] and m_piece.m_rook.at(3).castling[3]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 2] and m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 3] and m_piece.m_rook.at(2).castling[2]) {
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                    }
                    king_run[i] = true;
                }
            }
        }
        if (king_run[i]) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    reset_desk();

                                    if (y == m_piece.m_king.at(i).m_position.y and x == m_piece.m_king.at(i).m_position.x + 2) {
                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1], m_desk.m_is_open[m_piece.m_rook.at(3).m_position.y][m_piece.m_rook.at(3).m_position.x]);
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_rook.at(3).m_sprite.setPosition(m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x + 1].getPosition());
                                        m_piece.m_rook.at(3).m_position.y = m_piece.m_king.at(i).m_position.y;
                                        m_piece.m_rook.at(3).m_position.x = m_piece.m_king.at(i).m_position.x + 1;
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;

                                        m_piece.m_king.at(i).active_castle = false;
                                        king_run[i] = false;
                                        queue = true;
                                    }
                                    else if (y == m_piece.m_king.at(i).m_position.y and x == m_piece.m_king.at(i).m_position.x - 2) {
                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1], m_desk.m_is_open[m_piece.m_rook.at(2).m_position.y][m_piece.m_rook.at(2).m_position.x]);
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_rook.at(2).m_sprite.setPosition(m_desk.m_board[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x - 1].getPosition());
                                        m_piece.m_rook.at(2).m_position.y = m_piece.m_king.at(i).m_position.y;
                                        m_piece.m_rook.at(2).m_position.x = m_piece.m_king.at(i).m_position.x - 1;
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;

                                        m_piece.m_king.at(i).active_castle = false;
                                        king_run[i] = false;
                                        queue = true;
                                    }
                                    else {
                                        std::swap(m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;
                                        king_run[i] = false;
                                        queue = true;
                                    }

                                    if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_king.at(i).m_position.y][m_piece.m_king.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_king.at(i).m_position.y = y;
                                        m_piece.m_king.at(i).m_position.x = x;
                                        for (int j = 0; j < 8; j++) {
                                            if (m_piece.m_pawn.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_pawn.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_pawn.at(j).m_position.y = -1;
                                                m_piece.m_pawn.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 2; j++) {
                                            if (m_piece.m_rook.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_rook.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_rook.at(j).m_position.y = -1;
                                                m_piece.m_rook.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_knight.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_knight.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_knight.at(j).m_position.y = -1;
                                                m_piece.m_knight.at(j).m_position.x = -1;
                                            }
                                            if (m_piece.m_bishop.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_bishop.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_bishop.at(j).m_position.y = -1;
                                                m_piece.m_bishop.at(j).m_position.x = -1;
                                            }
                                        }
                                        for (int j = 0; j < 1; j++) {
                                            if (m_piece.m_queen.at(j).m_sprite.getPosition() == m_piece.m_king.at(i).m_sprite.getPosition()) {
                                                m_piece.m_queen.at(j).m_sprite.setPosition(10000, 0);
                                                m_piece.m_queen.at(j).m_position.y = -1;
                                                m_piece.m_queen.at(j).m_position.x = -1;
                                            }
                                        }
                                        king_run[i] = false;
                                        queue = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::play() {
    if (queue) {
        w_pawn_run();
        w_rook_run();
        w_knight_run();
        w_bishop_run();
        w_queen_run();
        w_king_run();
    }
    else {
        b_pawn_run();
        b_rook_run();
        b_knight_run();
        b_bishop_run();
        b_queen_run();
        b_king_run();
    }
}

void Game::isok() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << m_desk.m_is_open[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Game::king_desk() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m_desk.m_w_king_can[i][j] = 1;
        }
    }

    for (int i = 8; i < 16; i++){
        if (m_piece.m_pawn.at(i).m_position.x + 1 < 8 and m_piece.m_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1] = 0;
            m_desk.m_w_king_can[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_pawn.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_pawn.at(i).m_position.y + 1][m_piece.m_pawn.at(i).m_position.x - 1] = 0;
        }
    }
    for (int i = 2; i < 4; i++){
        for (int j = m_piece.m_rook.at(i).m_position.x + 1; j < 8; j++) {
            if (!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                for (int z = 0; z < 8; z++) {
                    if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                for (int z = 0; z < 2; z++) {
                    if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                    if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                    if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                for (int z = 0; z < 1; z++) {
                    if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                break;
            }
            m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_rook.at(i).m_position.x - 1; j > -1; j--) {
            if (!m_desk.m_is_open[m_piece.m_rook.at(i).m_position.y][j]) {
                for (int z = 0; z < 8; z++) {
                    if (m_piece.m_pawn.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_pawn.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                for (int z = 0; z < 2; z++) {
                    if (m_piece.m_rook.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_rook.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                    if (m_piece.m_knight.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_knight.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                    if (m_piece.m_bishop.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_bishop.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                for (int z = 0; z < 1; z++) {
                    if (m_piece.m_queen.at(z).m_position.y == m_piece.m_rook.at(i).m_position.y and m_piece.m_queen.at(z).m_position.x == j) {
                        m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
                    }
                }
                break;
            }
            m_desk.m_w_king_can[m_piece.m_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_rook.at(i).m_position.y + 1; j < 8; j++) {
            if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x]) {
                for (int z = 0; z < 8; z++) {
                    if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                for (int z = 0; z < 2; z++) {
                    if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                    if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                    if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                for (int z = 0; z < 1; z++) {
                    if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                break;
            }
            m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
        }
        for (int j = m_piece.m_rook.at(i).m_position.y - 1; j > -1; j--) {
            if (!m_desk.m_is_open[j][m_piece.m_rook.at(i).m_position.x]) {
                for (int z = 0; z < 8; z++) {
                    if (m_piece.m_pawn.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_pawn.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                for (int z = 0; z < 2; z++) {
                    if (m_piece.m_rook.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_rook.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                    if (m_piece.m_knight.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_knight.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                    if (m_piece.m_bishop.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_bishop.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                for (int z = 0; z < 1; z++) {
                    if (m_piece.m_queen.at(z).m_position.x == m_piece.m_rook.at(i).m_position.x and m_piece.m_queen.at(z).m_position.y == j) {
                        m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
                    }
                }
                break;
            }
            m_desk.m_w_king_can[j][m_piece.m_rook.at(i).m_position.x] = 0;
        }
        ///////////
        if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y + 2 < 8 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y + 2][m_piece.m_knight.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y - 2 > -1 and m_piece.m_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y - 2][m_piece.m_knight.at(i).m_position.x - 1] = 0;
        }

        if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y + 1 < 8 and m_piece.m_knight.at(i).m_position.x - 2 > -1) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y + 1][m_piece.m_knight.at(i).m_position.x - 2] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_knight.at(i).m_position.y - 1 > -1 and m_piece.m_knight.at(i).m_position.x - 2 < -1) {
            m_desk.m_w_king_can[m_piece.m_knight.at(i).m_position.y - 1][m_piece.m_knight.at(i).m_position.x - 2] = 0;
        }
    }
}

void Game::king_desk_draw() {
    king_desk();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << m_desk.m_w_king_can[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Game::reset_desk() {
    sf::Color White = sf::Color::White;
    sf::Color Black = sf::Color::Black;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (j % 2 == 0) {
                m_desk.m_board[i][j].setFillColor(White);
            }
            else {
                m_desk.m_board[i][j].setFillColor(Black);
            }
        }
        std::swap(White, Black);
    }
}

