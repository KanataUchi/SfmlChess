#include "Game.h"

void Game::game_loop() {
    init_systems(1500, 1000);
    m_desk.set_position();
    m_piece.init_piece();
    m_piece.set_pos();
    can_run();

    sf::RectangleShape que;
    que.setSize(sf::Vector2f(300, 100));
    que.setPosition(1100, 200);

    sf::Font font;
    if (!font.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\gnyrwn971.ttf")) {
        std::cout << "шрифт не загружен";
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(68);
    text.setFillColor(sf::Color::Black);
    text.setPosition(1100, 200);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\return_menu.png");
    sf::Sprite butten_return_menu;
    butten_return_menu.setTexture(butten_2);
    butten_return_menu.setPosition(1075, 800);

    while (m_window.isOpen()){
        
        m_window.clear(sf::Color(239,136,190,255));
        draw_desk();
        draw_piece();
       
        while (m_window.pollEvent(m_event))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
            if (m_event.type == sf::Event::Closed) {
                m_window.close();
            }
            if (queue) {
                text.setString("Queue: White");
            }
            else {
                text.setString("Queue: Black");
            }
            if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_return_menu.setColor(sf::Color::Red);
            }
            else butten_return_menu.setColor(sf::Color(240, 134, 80, 250));
            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 3;
                }
            }
            isok();

            w_king_desk();
            b_king_desk();
            
            play();
        }
        
        m_window.draw(que);
        m_window.draw(text);
        m_window.draw(butten_return_menu);
        m_window.display();
    }
}


void Game::init_systems(int x,int y) {
    m_window.create(sf::VideoMode(x, y), "game",sf::Style::None);
}

void Game::window(int x, int y) {
    m_window_extra.create(sf::VideoMode(x, y),"",sf::Style::None);
}

void Game::main_menu() {
    sf::Texture background;
    background.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\пуик 2.png");
    sf::Sprite back;
    back.setTexture(background);


    sf::Texture butten;
    butten.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\play.png");
    sf::Sprite butten_play;
    butten_play.setTexture(butten);
    butten_play.setPosition(200, 350);
    
    sf::Texture butten_1;
    butten_1.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\rules.png");
    sf::Sprite butten_rules;
    butten_rules.setTexture(butten_1);
    butten_rules.setPosition(200, 550);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\exit.png");
    sf::Sprite butten_exit;
    butten_exit.setTexture(butten_2);
    butten_exit.setPosition(200, 750);

    init_systems(1920,1080);

    while (m_window.isOpen())
    {
        while (m_window.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed) {
                m_window.close();
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

            if (butten_play.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_play.setColor(sf::Color(220,255,0,250));
            }
            else butten_play.setColor(sf::Color(131,255,150,250));
            if (butten_rules.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_rules.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_rules.setColor(sf::Color(131, 255, 150, 250));
            if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_exit.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_exit.setColor(sf::Color(131, 255, 150, 250));
            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                

                if (butten_play.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    game_loop();
                    
                }
                else if (butten_rules.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    reference();
                }
                else if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    restart = 2;
                }
            }
        }
        m_window.draw(back);
        m_window.draw(butten_play);
        m_window.draw(butten_rules);
        m_window.draw(butten_exit);
        m_window.display();
    }
}

void Game::reference() {
    window(1200, 675);
    sf::Font font;
    if (!font.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\gnyrwn971.ttf")) {
        std::cout << "шрифт не загружен";
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::Black);
    text.setString("This program is a chess game for two players.\nYou can play by yourself or with your friend.\nI tried very hard while writing this game.\nFor me, this was the first project of such complexity.\n It was not an easy path, but I completed it.\n Hurray!!!\n.I really hope you like it.\nEnjoy!!!");
    sf::Texture background;
    background.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\reference.png");
    sf::Sprite back;
    back.setTexture(background);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\return_menu.png");
    sf::Sprite butten_return_menu;
    butten_return_menu.setTexture(butten_2);
    butten_return_menu.setPosition(100, 500);
    while (m_window_extra.isOpen())
    {
        
        while (m_window_extra.pollEvent(m_event)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);
            if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_return_menu.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_return_menu.setColor(sf::Color(131, 255, 150, 250));

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window_extra.close();
                    restart = 3;
                }
            }
            m_window_extra.draw(back);
            m_window_extra.draw(text);
            m_window_extra.draw(butten_return_menu);
            m_window_extra.display();
        }
       
    }
}

void Game::w_checkmate() {
    window(450, 650);
    sf::Texture background;
    background.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\window_check.png");
    sf::Sprite back;
    back.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\gnyrwn971.ttf")) {

        std::cout << "шрифт не загружен";
    }
    sf::Text text("Black Wins", font, 121);

    sf::Texture butten;
    butten.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\restart.png");
    sf::Sprite butten_restart;
    butten_restart.setTexture(butten);
    butten_restart.setPosition(48, 150);

    sf::Texture butten_1;
    butten_1.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\exit.png");
    sf::Sprite butten_exit;
    butten_exit.setTexture(butten_1);
    butten_exit.setPosition(48, 450);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\return_menu.png");
    sf::Sprite butten_return_menu;
    butten_return_menu.setTexture(butten_2);
    butten_return_menu.setPosition(48, 300);

    while (m_window_extra.isOpen())
    {
        while (m_window_extra.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed) {
                m_window_extra.close();
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);

            if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_restart.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_restart.setColor(sf::Color(131, 255, 150, 250));

            if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_exit.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_exit.setColor(sf::Color(131, 255, 150, 250));

            if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_return_menu.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_return_menu.setColor(sf::Color(131, 255, 150, 250));

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 1;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 2;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 3;
                }
            }
        }
        m_window_extra.draw(back);
        m_window_extra.draw(text);
        m_window_extra.draw(butten_restart);
        m_window_extra.draw(butten_exit);
        m_window_extra.draw(butten_return_menu);
        m_window_extra.display();
    }
}

void Game::draw() {
    window(450, 650);
    sf::Texture background;
    background.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\window_check.png");
    sf::Sprite back;
    back.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\gnyrwn971.ttf")) {

        std::cout << "шрифт не загружен";
    }
    sf::Text text("draw", font, 121);

    sf::Texture butten;
    butten.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\restart.png");
    sf::Sprite butten_restart;
    butten_restart.setTexture(butten);
    butten_restart.setPosition(48, 150);

    sf::Texture butten_1;
    butten_1.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\exit.png");
    sf::Sprite butten_exit;
    butten_exit.setTexture(butten_1);
    butten_exit.setPosition(48, 450);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\return_menu.png");
    sf::Sprite butten_return_menu;
    butten_return_menu.setTexture(butten_2);
    butten_return_menu.setPosition(48, 300);

    while (m_window_extra.isOpen())
    {
        while (m_window_extra.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed) {
                m_window_extra.close();
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);

            if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_restart.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_restart.setColor(sf::Color(131, 255, 150, 250));

            if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_exit.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_exit.setColor(sf::Color(131, 255, 150, 250));

            if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_return_menu.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_return_menu.setColor(sf::Color(131, 255, 150, 250));

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 1;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 2;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 3;
                }
            }
        }
        m_window_extra.draw(back);
        m_window_extra.draw(text);
        m_window_extra.draw(butten_restart);
        m_window_extra.draw(butten_exit);
        m_window_extra.draw(butten_return_menu);
        m_window_extra.display();
    }
}


void Game::b_checkmate() {
    window(450, 650);
    sf::Texture background;
    background.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\window_check.png");
    sf::Sprite back;
    back.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\gnyrwn971.ttf")) {

        std::cout << "шрифт не загружен";
    }
    sf::Text text("White Wins", font, 121);

    sf::Texture butten;
    butten.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\restart.png");
    sf::Sprite butten_restart;
    butten_restart.setTexture(butten);
    butten_restart.setPosition(48, 150);

    sf::Texture butten_1;
    butten_1.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\exit.png");
    sf::Sprite butten_exit;
    butten_exit.setTexture(butten_1);
    butten_exit.setPosition(48, 450);

    sf::Texture butten_2;
    butten_2.loadFromFile("D:\\для учебы\\лабы по оаипу 2 сем\\SfmlChess\\main\\image\\return_menu.png");
    sf::Sprite butten_return_menu;
    butten_return_menu.setTexture(butten_2);
    butten_return_menu.setPosition(48, 300);

    while (m_window_extra.isOpen())
    {
        while (m_window_extra.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::Closed) {
                m_window_extra.close();
            }
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);

            if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_restart.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_restart.setColor(sf::Color(131, 255, 150, 250));

            if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_exit.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_exit.setColor(sf::Color(131, 255, 150, 250));

            if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                butten_return_menu.setColor(sf::Color(220, 255, 0, 250));
            }
            else butten_return_menu.setColor(sf::Color(131, 255, 150, 250));

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_restart.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 1;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_exit.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 2;
                }
            }

            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                if (butten_return_menu.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                    m_window_extra.close();
                    restart = 3;
                }
            }
        }
        m_window_extra.draw(back);
        m_window_extra.draw(text);
        m_window_extra.draw(butten_restart);
        m_window_extra.draw(butten_exit);
        m_window_extra.draw(butten_return_menu);
        m_window_extra.display();
    }
}

void Game::run() {
    
    main_menu();
}

int Game::w_appear() {
    window(240, 240);
    sf::Sprite w_rook;
    w_rook.setTexture(m_piece.m_textures.at(W_ROOK));

    sf::Sprite w_bishop;
    w_bishop.setTexture(m_piece.m_textures.at(W_BISHOP));
    w_bishop.setPosition(120, 0);

    sf::Sprite w_knight;
    w_knight.setTexture(m_piece.m_textures.at(W_KNIGHT));
    w_knight.setPosition(0, 120);

    sf::Sprite w_queen;
    w_queen.setTexture(m_piece.m_textures.at(W_QUEEN));
    w_queen.setPosition(120, 120);

    while (m_window_extra.isOpen())
    {
        while (m_window_extra.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);
                int point;
                if (w_rook.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 1;
                    m_window_extra.close();
                    return point;
                }
                else if (w_bishop.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 2;
                    m_window_extra.close();
                    return point;
                }
                else if (w_knight.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 3;
                    m_window_extra.close();
                    return point;
                }
                else if (w_queen.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 4;
                    m_window_extra.close();
                    return point;
                }
            }
        }
        m_window_extra.clear(sf::Color::Blue);
        m_window_extra.draw(w_rook);
        m_window_extra.draw(w_bishop);
        m_window_extra.draw(w_knight);
        m_window_extra.draw(w_queen);
        m_window_extra.display();
    }
}

int Game::b_appear() {
    window(240, 240);
    sf::Sprite b_rook;
    b_rook.setTexture(m_piece.m_textures.at(B_ROOK));

    sf::Sprite b_bishop;
    b_bishop.setTexture(m_piece.m_textures.at(B_BISHOP));
    b_bishop.setPosition(120, 0);

    sf::Sprite b_knight;
    b_knight.setTexture(m_piece.m_textures.at(B_KNIGHT));
    b_knight.setPosition(0, 120);

    sf::Sprite b_queen;
    b_queen.setTexture(m_piece.m_textures.at(B_QUEEN));
    b_queen.setPosition(120, 120);

    while (m_window_extra.isOpen())
    {
        while (m_window_extra.pollEvent(m_event))
        {
            if (m_event.type == sf::Event::MouseButtonPressed and m_event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window_extra);
                int point;
                if (b_rook.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 1;
                    m_window_extra.close();
                    return point;
                }
                else if (b_bishop.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 2;
                    m_window_extra.close();
                    return point;
                }
                else if (b_knight.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 3;
                    m_window_extra.close();
                    return point;
                }
                else if (b_queen.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    point = 4;
                    m_window_extra.close();
                    return point;
                }
            }
        }
        m_window_extra.clear(sf::Color::Blue);
        m_window_extra.draw(b_rook);
        m_window_extra.draw(b_bishop);
        m_window_extra.draw(b_knight);
        m_window_extra.draw(b_queen);
        m_window_extra.display();
    }
}

void Game::draw_desk() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {
            m_window.draw(m_desk.m_board[i][j]);
        }
    }
}

void Game::draw_piece() {
    for (int i = 0; i < m_piece.m_w_pawn.size(); i++){
        m_window.draw(m_piece.m_w_pawn.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_pawn.size(); i++) {
        m_window.draw(m_piece.m_b_pawn.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_w_rook.size();i++) {
        m_window.draw(m_piece.m_w_rook.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_rook.size();i++) {
        m_window.draw(m_piece.m_b_rook.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_w_knight.size();i++) {
        m_window.draw(m_piece.m_w_knight.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_knight.size();i++) {
        m_window.draw(m_piece.m_b_knight.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_w_bishop.size();i++) {
        m_window.draw(m_piece.m_w_bishop.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_bishop.size();i++) {
        m_window.draw(m_piece.m_b_bishop.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_w_queen.size(); i++) {
        m_window.draw(m_piece.m_w_queen.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_queen.size(); i++) {
        m_window.draw(m_piece.m_b_queen.at(i).m_sprite);
    }

    for (int i = 0; i < m_piece.m_w_king.size(); i++) {
        m_window.draw(m_piece.m_w_king.at(i).m_sprite);
    }
    for (int i = 0; i < m_piece.m_b_king.size(); i++) {
        m_window.draw(m_piece.m_b_king.at(i).m_sprite);
    }
}

void Game::play() {
    w_check();
    b_check();
    if (queue) {
        if (check) {
            m_desk.m_board[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x].setFillColor(sf::Color::Red);
            if (m_piece.m_w_king.at(0).m_position.y + 1 > 7) {
                if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                    check = false;
                    w_checkmate();
                }
            }
            else if (m_piece.m_w_king.at(0).m_position.y - 1 < 0) {
                if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                    check = false;
                    w_checkmate();
                }
            }
            else if (m_piece.m_w_king.at(0).m_position.x - 1 < 0) {
                if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false) {
                    check = false;
                    w_checkmate();
                }
            }
            else if (m_piece.m_w_king.at(0).m_position.x + 1 > 7) {
                if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false) {
                    check = false;
                    w_checkmate();
                }
            }
            else {
                if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                    check = false;
                    w_checkmate();
                }
            }
            w_king_run();
            check = false;
        }
        else {
            w_draw = true;
            w_is_life();
            if (w_draw) {
                if (m_piece.m_w_king.at(0).m_position.y + 1 > 7) {
                    if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_w_king.at(0).m_position.y - 1 < 0) {
                    if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_w_king.at(0).m_position.x - 1 < 0) {
                    if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_w_king.at(0).m_position.x + 1 > 7) {
                    if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false) {
                        draw();
                    }
                }
                else {
                    if (m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x - 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y - 1][m_piece.m_w_king.at(0).m_position.x + 1] == false and m_desk.m_w_king_can[m_piece.m_w_king.at(0).m_position.y + 1][m_piece.m_w_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
            }
            w_pawn_run();
            w_rook_run();
            w_knight_run();
            w_bishop_run();
            w_queen_run();
            w_king_run();
        }
    }
    else {
        if (check) {
            m_desk.m_board[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x].setFillColor(sf::Color::Red);
            if (m_piece.m_b_king.at(0).m_position.y + 1 > 7) {
                if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                    b_checkmate();
                }
            }
            else if (m_piece.m_b_king.at(0).m_position.y - 1 < 0) {
                if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                    b_checkmate();
                }
            }
            else if (m_piece.m_b_king.at(0).m_position.x - 1 < 0) {
                if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false) {
                    b_checkmate();
                }
            }
            else if (m_piece.m_b_king.at(0).m_position.x + 1 > 7) {
                if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false) {
                    b_checkmate();
                }
            }
            else {
                if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and  m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                    b_checkmate();
                }
            }
            b_king_run();


            check = false;
        }
        else {
            b_draw = true;
            b_is_life();
            if (b_draw) {
                if (m_piece.m_b_king.at(0).m_position.y + 1 > 7) {
                    if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_b_king.at(0).m_position.y - 1 < 0) {
                    if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_b_king.at(0).m_position.x - 1 < 0) {
                    if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false) {
                        draw();
                    }
                }
                else if (m_piece.m_b_king.at(0).m_position.x + 1 > 7) {
                    if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false) {
                        draw();
                    }
                }
                else {
                    if (m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x - 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y - 1][m_piece.m_b_king.at(0).m_position.x + 1] == false and m_desk.m_b_king_can[m_piece.m_b_king.at(0).m_position.y + 1][m_piece.m_b_king.at(0).m_position.x + 1] == false) {
                        draw();
                    }
                }
            }
            b_pawn_run();
            b_rook_run();
            b_knight_run();
            b_bishop_run();
            b_queen_run();
            b_king_run();
        }
    }
}

void Game::w_is_life() {
    if (m_piece.m_w_pawn.size() != 0) {
        w_draw = false;
    }
    if (m_piece.m_w_rook.size() != 0) {
        w_draw = false;
    }
    if (m_piece.m_w_knight.size() != 0) {
        w_draw = false;
    }
    if (m_piece.m_w_bishop.size() != 0) {
        w_draw = false;
    }
    if (m_piece.m_w_queen.size() != 0) {
        w_draw = false;
    }
}

void Game::b_is_life() {
    if (m_piece.m_b_pawn.size() != 0) {
        b_draw = false;
    }
    if (m_piece.m_b_rook.size() != 0) {
        b_draw = false;
    }
    if (m_piece.m_b_knight.size() != 0) {
        b_draw = false;
    }
    if (m_piece.m_b_bishop.size() != 0) {
        b_draw = false;
    }
    if (m_piece.m_b_queen.size() != 0) {
        b_draw = false;
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

void Game::can_run() {
    m_w_pawn_run.resize(m_piece.m_w_pawn.size());
    m_b_pawn_run.resize(m_piece.m_b_pawn.size());

    m_w_rook_run.resize(m_piece.m_w_rook.size());
    m_b_rook_run.resize(m_piece.m_b_rook.size());

    m_w_knight_run.resize(m_piece.m_w_knight.size());
    m_b_knight_run.resize(m_piece.m_b_knight.size());

    m_w_bishop_run.resize(m_piece.m_w_bishop.size());
    m_b_bishop_run.resize(m_piece.m_b_bishop.size());

    m_w_queen_run.resize(m_piece.m_w_queen.size());
    m_b_queen_run.resize(m_piece.m_b_queen.size());

    m_w_king_run.resize(m_piece.m_w_king.size());
    m_b_king_run.resize(m_piece.m_b_king.size());
}

void Game::w_pawn_run() {
    for (int i = 0; i < m_piece.m_w_pawn.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_pawn.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_w_pawn.at(i).m_position.y == 6) {
                        if (m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x] and m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 2][m_piece.m_w_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 2][m_piece.m_w_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));

                        }
                        else if (m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x] and !m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 2][m_piece.m_w_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));

                        }
                        if (!m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    else {
                        if (m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (!m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_pawn.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    m_w_pawn_run.at(i) = true;
                }
                else{
                    m_w_pawn_run.at(i) = false;
                }
            }
        }
        if (m_w_pawn_run.at(i)){
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (y < m_piece.m_w_pawn.at(i).m_position.y and x == m_piece.m_w_pawn.at(i).m_position.x) {

                                        reset_desk();

                                        std::swap(m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y][m_piece.m_w_pawn.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_w_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_w_pawn.at(i).m_position.y = y;
                                        m_w_pawn_run.at(i) = false;
                                        queue = false;
                                    }
                                    if ((m_piece.m_w_pawn.at(i).m_position.y - y) == 1 and (abs(x - m_piece.m_w_pawn.at(i).m_position.x) == 1)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_w_pawn.at(i).m_position.y][m_piece.m_w_pawn.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_w_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_pawn.at(i).m_position.y = y;
                                            m_piece.m_w_pawn.at(i).m_position.x = x;
                                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                                if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_pawn.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_pawn.begin() + j;
                                                    auto point_1 = m_b_pawn_run.begin() + j;
                                                    m_piece.m_b_pawn.erase(point);
                                                    m_b_pawn_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                                if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_pawn.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_rook.begin() + j;
                                                    auto point_1 = m_b_rook_run.begin() + j;
                                                    m_piece.m_b_rook.erase(point);
                                                    m_b_rook_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                                if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_pawn.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_knight.begin() + j;
                                                    auto point_1 = m_b_knight_run.begin() + j;
                                                    m_piece.m_b_knight.erase(point);
                                                    m_b_knight_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                                if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_pawn.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_bishop.begin() + j;
                                                    auto point_1 = m_b_bishop_run.begin() + j;
                                                    m_piece.m_b_bishop.erase(point);
                                                    m_b_bishop_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                                if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_pawn.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_queen.begin() + j;
                                                    auto point_1 = m_b_queen_run.begin() + j;
                                                    m_piece.m_b_queen.erase(point);
                                                    m_b_queen_run.erase(point_1);
                                                }
                                            }
                                            m_w_pawn_run.at(i) = false;
                                            queue = false;
                                            if (m_piece.m_w_pawn.at(i).m_position.y == 0) {
                                                int  choice = w_appear();
                                                if (choice == 1) {
                                                    m_piece.m_w_rook.resize(m_piece.m_w_rook.size() + 1);
                                                    m_piece.m_w_rook.at(m_piece.m_w_rook.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(W_ROOK));
                                                    m_piece.m_w_rook.at(m_piece.m_w_rook.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_piece.m_w_rook.at(m_piece.m_w_rook.size() - 1).m_position.y = m_piece.m_w_pawn.at(i).m_position.y;
                                                    m_piece.m_w_rook.at(m_piece.m_w_rook.size() - 1).m_position.x = m_piece.m_w_pawn.at(i).m_position.x;
                                                    m_piece.m_w_rook.at(m_piece.m_w_rook.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_w_rook_run.resize(m_piece.m_w_rook.size());
   
                                                    auto point = m_piece.m_w_pawn.begin() + i;
                                                    m_piece.m_w_pawn.erase(point);
                                                }
                                                else if (choice == 2) {
                                                    m_piece.m_w_bishop.resize(m_piece.m_w_bishop.size() + 1);
                                                    m_piece.m_w_bishop.at(m_piece.m_w_bishop.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(W_BISHOP));
                                                    m_piece.m_w_bishop.at(m_piece.m_w_bishop.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_piece.m_w_bishop.at(m_piece.m_w_bishop.size() - 1).m_position.y = m_piece.m_w_pawn.at(i).m_position.y;
                                                    m_piece.m_w_bishop.at(m_piece.m_w_bishop.size() - 1).m_position.x = m_piece.m_w_pawn.at(i).m_position.x;
                                                    m_piece.m_w_bishop.at(m_piece.m_w_bishop.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_w_bishop_run.resize(m_piece.m_w_bishop.size());

                                                    auto point = m_piece.m_w_pawn.begin() + i;
                                                    m_piece.m_w_pawn.erase(point);
                                                }
                                                else if (choice == 3) {
                                                    m_piece.m_w_knight.resize(m_piece.m_w_knight.size() + 1);
                                                    m_piece.m_w_knight.at(m_piece.m_w_knight.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(W_KNIGHT));
                                                    m_piece.m_w_knight.at(m_piece.m_w_knight.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_piece.m_w_knight.at(m_piece.m_w_knight.size() - 1).m_position.y = m_piece.m_w_pawn.at(i).m_position.y;
                                                    m_piece.m_w_knight.at(m_piece.m_w_knight.size() - 1).m_position.x = m_piece.m_w_pawn.at(i).m_position.x;
                                                    m_piece.m_w_knight.at(m_piece.m_w_knight.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_w_knight_run.resize(m_piece.m_w_knight.size());

                                                    auto point = m_piece.m_w_pawn.begin() + i;
                                                    m_piece.m_w_pawn.erase(point);
                                                }
                                                else {
                                                    m_piece.m_w_queen.resize(m_piece.m_w_queen.size() + 1);
                                                    m_piece.m_w_queen.at(m_piece.m_w_queen.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(W_QUEEN));
                                                    m_piece.m_w_queen.at(m_piece.m_w_queen.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_piece.m_w_queen.at(m_piece.m_w_queen.size() - 1).m_position.y = m_piece.m_w_pawn.at(i).m_position.y;
                                                    m_piece.m_w_queen.at(m_piece.m_w_queen.size() - 1).m_position.x = m_piece.m_w_pawn.at(i).m_position.x;
                                                    m_piece.m_w_queen.at(m_piece.m_w_queen.size() - 1).m_sprite.setPosition(m_piece.m_w_pawn.at(i).m_sprite.getPosition());
                                                    m_w_queen_run.resize(m_piece.m_w_queen.size());

                                                    auto point = m_piece.m_w_pawn.begin() + i;
                                                    m_piece.m_w_pawn.erase(point);
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
    }
}

void Game::b_pawn_run() {
    for (int i = 0; i < m_piece.m_b_pawn.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_pawn.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_b_pawn.at(i).m_position.y == 1) {
                        if (m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x] and m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 2][m_piece.m_b_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 2][m_piece.m_b_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x] and !m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 2][m_piece.m_b_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if(!m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    else {
                        if (m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (!m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                        if (!m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_pawn.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_pawn.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                                }
                            }
                        }
                    }
                    m_b_pawn_run.at(i) = true;
                }
                else {
                    m_b_pawn_run.at(i) = false;
                }
            }
        }
        if (m_b_pawn_run.at(i)) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if (y > m_piece.m_b_pawn.at(i).m_position.y and x == m_piece.m_b_pawn.at(i).m_position.x) {

                                        reset_desk();

                                        std::swap(m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y][m_piece.m_b_pawn.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                        m_piece.m_b_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_b_pawn.at(i).m_position.y = y;
                                        m_b_pawn_run.at(i) = false;
                                        queue = true;
                                    }
                                    if ((y - m_piece.m_b_pawn.at(i).m_position.y) == 1  and (abs(x - m_piece.m_b_pawn.at(i).m_position.x) == 1)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_b_pawn.at(i).m_position.y][m_piece.m_b_pawn.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_b_pawn.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_pawn.at(i).m_position.y = y;
                                            m_piece.m_b_pawn.at(i).m_position.x = x;
                                                for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                                    if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_pawn.at(i).m_sprite.getPosition()) {
                                                        auto point = m_piece.m_w_pawn.begin() + j;
                                                        auto point_1 = m_w_pawn_run.begin() + j;
                                                        m_piece.m_w_pawn.erase(point);
                                                        m_w_pawn_run.erase(point_1);
                                                    }
                                                }
                                                for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                                    if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_pawn.at(i).m_sprite.getPosition()) {
                                                        auto point = m_piece.m_w_rook.begin() + j;
                                                        auto point_1 = m_w_rook_run.begin() + j;
                                                        m_piece.m_w_rook.erase(point);
                                                        m_w_rook_run.erase(point_1);
                                                    }
                                                }
                                                for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                                    if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_pawn.at(i).m_sprite.getPosition()) {
                                                        auto point = m_piece.m_w_knight.begin() + j;
                                                        auto point_1 = m_w_knight_run.begin() + j;
                                                        m_piece.m_w_knight.erase(point);
                                                        m_w_knight_run.erase(point_1);
                                                    }
                                                }
                                                for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                                    if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_pawn.at(i).m_sprite.getPosition()) {
                                                        auto point = m_piece.m_w_bishop.begin() + j;
                                                        auto point_1 = m_w_bishop_run.begin() + j;
                                                        m_piece.m_w_bishop.erase(point);
                                                        m_w_bishop_run.erase(point_1);
                                                    }
                                                }
                                                for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                                    if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_pawn.at(i).m_sprite.getPosition()) {
                                                        auto point = m_piece.m_w_queen.begin() + j;
                                                        auto point_1 = m_w_queen_run.begin() + j;
                                                        m_piece.m_w_queen.erase(point);
                                                        m_w_queen_run.erase(point_1);
                                                    }
                                                }
                                                m_b_pawn_run.at(i) = false;
                                            queue = true;
                                        }
                                        if (m_piece.m_b_pawn.at(i).m_position.y == 7) {
                                            int  choice = b_appear();
                                            if (choice == 1) {
                                                m_piece.m_b_rook.resize(m_piece.m_b_rook.size() + 1);
                                                m_piece.m_b_rook.at(m_piece.m_b_rook.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(B_ROOK));
                                                m_piece.m_b_rook.at(m_piece.m_b_rook.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_piece.m_b_rook.at(m_piece.m_b_rook.size() - 1).m_position.y = m_piece.m_b_pawn.at(i).m_position.y;
                                                m_piece.m_b_rook.at(m_piece.m_b_rook.size() - 1).m_position.x = m_piece.m_b_pawn.at(i).m_position.x;
                                                m_piece.m_b_rook.at(m_piece.m_b_rook.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_b_rook_run.resize(m_piece.m_b_rook.size());

                                                auto point = m_piece.m_b_pawn.begin() + i;
                                                m_piece.m_b_pawn.erase(point);
                                            }
                                            else if (choice == 2) {
                                                m_piece.m_b_bishop.resize(m_piece.m_b_bishop.size() + 1);
                                                m_piece.m_b_bishop.at(m_piece.m_b_bishop.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(B_BISHOP));
                                                m_piece.m_b_bishop.at(m_piece.m_b_bishop.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_piece.m_b_bishop.at(m_piece.m_b_bishop.size() - 1).m_position.y = m_piece.m_b_pawn.at(i).m_position.y;
                                                m_piece.m_b_bishop.at(m_piece.m_b_bishop.size() - 1).m_position.x = m_piece.m_b_pawn.at(i).m_position.x;
                                                m_piece.m_b_bishop.at(m_piece.m_b_bishop.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_b_bishop_run.resize(m_piece.m_b_bishop.size());

                                                auto point = m_piece.m_b_pawn.begin() + i;
                                                m_piece.m_b_pawn.erase(point);
                                            }
                                            else if (choice == 3) {
                                                m_piece.m_b_knight.resize(m_piece.m_b_knight.size() + 1);
                                                m_piece.m_b_knight.at(m_piece.m_b_knight.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(B_KNIGHT));
                                                m_piece.m_b_knight.at(m_piece.m_b_knight.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_piece.m_b_knight.at(m_piece.m_b_knight.size() - 1).m_position.y = m_piece.m_b_pawn.at(i).m_position.y;
                                                m_piece.m_b_knight.at(m_piece.m_b_knight.size() - 1).m_position.x = m_piece.m_b_pawn.at(i).m_position.x;
                                                m_piece.m_b_knight.at(m_piece.m_b_knight.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_b_knight_run.resize(m_piece.m_b_knight.size());

                                                auto point = m_piece.m_b_pawn.begin() + i;
                                                m_piece.m_b_pawn.erase(point);
                                            }
                                            else {
                                                m_piece.m_b_queen.resize(m_piece.m_b_queen.size() + 1);
                                                m_piece.m_b_queen.at(m_piece.m_b_queen.size() - 1).m_sprite.setTexture(m_piece.m_textures.at(B_QUEEN));
                                                m_piece.m_b_queen.at(m_piece.m_b_queen.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_piece.m_b_queen.at(m_piece.m_b_queen.size() - 1).m_position.y = m_piece.m_b_pawn.at(i).m_position.y;
                                                m_piece.m_b_queen.at(m_piece.m_b_queen.size() - 1).m_position.x = m_piece.m_b_pawn.at(i).m_position.x;
                                                m_piece.m_b_queen.at(m_piece.m_b_queen.size() - 1).m_sprite.setPosition(m_piece.m_b_pawn.at(i).m_sprite.getPosition());
                                                m_b_queen_run.resize(m_piece.m_b_queen.size());

                                                auto point = m_piece.m_b_pawn.begin() + i;
                                                m_piece.m_b_pawn.erase(point);
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
}

void Game::w_rook_run() {
    for (int i = 0; i < m_piece.m_w_rook.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_rook.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_w_rook.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++){
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_rook.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_w_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_rook.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_w_rook.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_rook.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_w_rook.at(i).m_position.x] ) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_w_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }

                    m_w_rook_run.at(i) = true;
                }
                else {
                    m_w_rook_run.at(i) = false;
                }
            }
        }
        if (m_w_rook_run.at(i)) {
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

                                            m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_w_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(i).m_position.y = y;
                                            m_piece.m_w_rook.at(i).m_position.x = x;
                                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                                if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_rook.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_pawn.begin() + j;
                                                    auto point_1 = m_b_pawn_run.begin() + j;
                                                    m_piece.m_b_pawn.erase(point);
                                                    m_b_pawn_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                                if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_rook.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_rook.begin() + j;
                                                    auto point_1 = m_b_rook_run.begin() + j;
                                                    m_piece.m_b_rook.erase(point);
                                                    m_b_rook_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                                if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_rook.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_knight.begin() + j;
                                                    auto point_1 = m_b_knight_run.begin() + j;
                                                    m_piece.m_b_knight.erase(point);
                                                    m_b_knight_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                                if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_rook.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_bishop.begin() + j;
                                                    auto point_1 = m_b_bishop_run.begin() + j;
                                                    m_piece.m_b_bishop.erase(point);
                                                    m_b_bishop_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                                if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_rook.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_queen.begin() + j;
                                                    auto point_1 = m_b_queen_run.begin() + j;
                                                    m_piece.m_b_queen.erase(point);
                                                    m_b_queen_run.erase(point_1);
                                                }
                                            }
                                    }
                                    else {
                                        if (y < m_piece.m_w_rook.at(i).m_position.y and x == m_piece.m_w_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(i).m_position.y = y;
                                        }
                                        else if (y > m_piece.m_w_rook.at(i).m_position.y and x == m_piece.m_w_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(i).m_position.y = y;
                                        }
                                        else if (x < m_piece.m_w_rook.at(i).m_position.x and y == m_piece.m_w_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(i).m_position.x = x;
                                        }
                                        else if (x > m_piece.m_w_rook.at(i).m_position.x and y == m_piece.m_w_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(i).m_position.x = x;
                                        }
                                    }
                                    m_w_rook_run.at(i) = false;
                                    queue = false;
                                    m_piece.m_w_rook.at(i).w_castling[i] = false;
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
    for (int i = 0; i < m_piece.m_b_rook.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_rook.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_b_rook.at(i).m_position.x + 1; j < 8; j++) {
                        if(!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_rook.at(i).m_position.x - 1; j > -1 ; j--) {
                        if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_b_rook.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_rook.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_b_rook.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_rook.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_b_rook.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_b_rook.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_b_rook_run.at(i) = true;
                }
                else {
                    m_b_rook_run.at(i) = false;
                }
            }
        }
        if (m_b_rook_run.at(i)) {
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

                                        m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_b_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_b_rook.at(i).m_position.y = y;
                                        m_piece.m_b_rook.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                            if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_rook.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_pawn.begin() + j;
                                                auto point_1 = m_w_pawn_run.begin() + j;
                                                m_piece.m_w_pawn.erase(point);
                                                m_w_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                            if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_rook.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_rook.begin() + j;
                                                auto point_1 = m_w_rook_run.begin() + j;
                                                m_piece.m_w_rook.erase(point);
                                                m_w_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                            if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_rook.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_knight.begin() + j;
                                                auto point_1 = m_w_knight_run.begin() + j;
                                                m_piece.m_w_knight.erase(point);
                                                m_w_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                            if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_rook.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_bishop.begin() + j;
                                                auto point_1 = m_w_bishop_run.begin() + j;
                                                m_piece.m_w_bishop.erase(point);
                                                m_w_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                            if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_rook.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_queen.begin() + j;
                                                auto point_1 = m_w_queen_run.begin() + j;
                                                m_piece.m_w_queen.erase(point);
                                                m_w_queen_run.erase(point_1);
                                            }
                                        }
                                    }
                                    else {
                                        if (y < m_piece.m_b_rook.at(i).m_position.y and x == m_piece.m_b_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(i).m_position.y = y;
                                        }
                                        else if (y > m_piece.m_b_rook.at(i).m_position.y and x == m_piece.m_b_rook.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(i).m_position.y = y;
                                        }
                                        else if (x < m_piece.m_b_rook.at(i).m_position.x and y == m_piece.m_b_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(i).m_position.x = x;
                                        }
                                        else if (x > m_piece.m_b_rook.at(i).m_position.x and y == m_piece.m_b_rook.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_rook.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(i).m_position.x = x;
                                        }
                                    }
                                    m_b_rook_run.at(i) = false;
                                    queue = true;
                                    m_piece.m_b_rook.at(i).b_castling[i] = false;
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
    for (int i = 0; i < m_piece.m_w_knight.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_knight.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                       
                    }
                    if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 2 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 2 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //
                    if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));

                    }
                    if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y + 1 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_knight.at(i).m_position.y - 1 and m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_w_knight_run.at(i) = true;
                }
                else {
                    m_w_knight_run.at(i) = false;
                }
            }
        }
        if (m_w_knight_run.at(i)) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if ((abs(m_piece.m_w_knight.at(i).m_position.y - y) == 2 and abs(m_piece.m_w_knight.at(i).m_position.x - x) == 1) or (abs(m_piece.m_w_knight.at(i).m_position.y - y) == 1 and abs(m_piece.m_w_knight.at(i).m_position.x - x) == 2)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y][m_piece.m_w_knight.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_w_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_knight.at(i).m_position.y = y;
                                            m_piece.m_w_knight.at(i).m_position.x = x;
                                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                                if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_pawn.begin() + j;
                                                    auto point_1 = m_b_pawn_run.begin() + j;
                                                    m_piece.m_b_pawn.erase(point);
                                                    m_b_pawn_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                                if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_rook.begin() + j;
                                                    auto point_1 = m_b_rook_run.begin() + j;
                                                    m_piece.m_b_rook.erase(point);
                                                    m_b_rook_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                                if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_knight.begin() + j;
                                                    auto point_1 = m_b_knight_run.begin() + j;
                                                    m_piece.m_b_knight.erase(point);
                                                    m_b_knight_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                                if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_bishop.begin() + j;
                                                    auto point_1 = m_b_bishop_run.begin() + j;
                                                    m_piece.m_b_bishop.erase(point);
                                                    m_b_bishop_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                                if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_b_queen.begin() + j;
                                                    auto point_1 = m_b_queen_run.begin() + j;
                                                    m_piece.m_b_queen.erase(point);
                                                    m_b_queen_run.erase(point_1);
                                                }
                                            }
                                            m_w_knight_run.at(i) = false;
                                            queue = false;
                                        }
                                        else {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_knight.at(i).m_position.y][m_piece.m_w_knight.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_knight.at(i).m_position.y = y;
                                            m_piece.m_w_knight.at(i).m_position.x = x;
                                            m_w_knight_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_b_knight.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_knight.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));

                    }
                    if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 2 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 2 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //
                    if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));

                    }
                    if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y + 1 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x + 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x - 2 > -1) {
                        if (!m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_knight.at(i).m_position.y - 1 and m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_knight.at(i).m_position.x - 2) {
                                    m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                        else  m_desk.m_board[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_b_knight_run.at(i) = true;
                }
                else {
                    m_b_knight_run.at(i) = false;
                }
            }
        }
        if (m_b_knight_run.at(i)) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    if ((abs(m_piece.m_b_knight.at(i).m_position.y - y) == 2 and abs(m_piece.m_b_knight.at(i).m_position.x - x) == 1) or (abs(m_piece.m_b_knight.at(i).m_position.y - y) == 1 and abs(m_piece.m_b_knight.at(i).m_position.x - x) == 2)) {
                                        if (!m_desk.m_is_open[y][x]) {
                                            reset_desk();

                                            m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y][m_piece.m_b_knight.at(i).m_position.x] = true;
                                            m_desk.m_is_open[y][x] = false;
                                            m_piece.m_b_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_knight.at(i).m_position.y = y;
                                            m_piece.m_b_knight.at(i).m_position.x = x;
                                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                                if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_w_pawn.begin() + j;
                                                    auto point_1 = m_w_pawn_run.begin() + j;
                                                    m_piece.m_w_pawn.erase(point);
                                                    m_w_pawn_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                                if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_w_rook.begin() + j;
                                                    auto point_1 = m_w_rook_run.begin() + j;
                                                    m_piece.m_w_rook.erase(point);
                                                    m_w_rook_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                                if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_w_knight.begin() + j;
                                                    auto point_1 = m_w_knight_run.begin() + j;
                                                    m_piece.m_w_knight.erase(point);
                                                    m_w_knight_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                                if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_w_bishop.begin() + j;
                                                    auto point_1 = m_w_bishop_run.begin() + j;
                                                    m_piece.m_w_bishop.erase(point);
                                                    m_w_bishop_run.erase(point_1);
                                                }
                                            }
                                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                                if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_knight.at(i).m_sprite.getPosition()) {
                                                    auto point = m_piece.m_w_queen.begin() + j;
                                                    auto point_1 = m_w_queen_run.begin() + j;
                                                    m_piece.m_w_queen.erase(point);
                                                    m_w_queen_run.erase(point_1);
                                                }
                                            }
                                            m_b_knight_run.at(i) = false;
                                            queue = true;
                                        }
                                        else {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_knight.at(i).m_position.y][m_piece.m_b_knight.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_knight.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_knight.at(i).m_position.y = y;
                                            m_piece.m_b_knight.at(i).m_position.x = x;
                                            m_b_knight_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_w_bishop.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_bishop.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_w_bishop.at(i).m_position.y + 1,z = m_piece.m_w_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++,z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j  and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_bishop.at(i).m_position.y + 1, z = m_piece.m_w_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_bishop.at(i).m_position.y - 1, z = m_piece.m_w_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_bishop.at(i).m_position.y - 1, z = m_piece.m_w_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_w_bishop_run.at(i) = true;
                }
                else {
                    m_w_bishop_run.at(i) = false;
                }
            }
        }
        if (m_w_bishop_run.at(i)) {
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

                                        m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_w_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_w_bishop.at(i).m_position.y = y;
                                        m_piece.m_w_bishop.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                            if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_pawn.begin() + j;
                                                auto point_1 = m_b_pawn_run.begin() + j;
                                                m_piece.m_b_pawn.erase(point);
                                                m_b_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                            if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_rook.begin() + j;
                                                auto point_1 = m_b_rook_run.begin() + j;
                                                m_piece.m_b_rook.erase(point);
                                                m_b_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                            if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_knight.begin() + j;
                                                auto point_1 = m_b_knight_run.begin() + j;
                                                m_piece.m_b_knight.erase(point);
                                                m_b_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                            if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_bishop.begin() + j;
                                                auto point_1 = m_b_bishop_run.begin() + j;
                                                m_piece.m_b_bishop.erase(point);
                                                m_b_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                            if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_queen.begin() + j;
                                                auto point_1 = m_b_queen_run.begin() + j;
                                                m_piece.m_b_queen.erase(point);
                                                m_b_queen_run.erase(point_1);
                                            }
                                        }
                                        m_w_bishop_run.at(i) = false;
                                        queue = false;
                                    }
                                    else {
                                        if (y > m_piece.m_w_bishop.at(i).m_position.y and x > m_piece.m_w_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_bishop.at(i).m_position.y = y;
                                            m_piece.m_w_bishop.at(i).m_position.x = x;

                                            m_w_bishop_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_w_bishop.at(i).m_position.y and x < m_piece.m_w_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_bishop.at(i).m_position.y = y;
                                            m_piece.m_w_bishop.at(i).m_position.x = x;

                                            m_w_bishop_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_w_bishop.at(i).m_position.y and x > m_piece.m_w_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_bishop.at(i).m_position.y = y;
                                            m_piece.m_w_bishop.at(i).m_position.x = x;

                                            m_w_bishop_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_w_bishop.at(i).m_position.y and x < m_piece.m_w_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_bishop.at(i).m_position.y = y;
                                            m_piece.m_w_bishop.at(i).m_position.x = x;

                                            m_w_bishop_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_b_bishop.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_bishop.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_b_bishop.at(i).m_position.y + 1, z = m_piece.m_b_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_bishop.at(i).m_position.y + 1, z = m_piece.m_b_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_bishop.at(i).m_position.y - 1, z = m_piece.m_b_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_bishop.at(i).m_position.y - 1, z = m_piece.m_b_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_b_bishop_run.at(i) = true;
                }
                else {
                    m_b_bishop_run.at(i) = false;
                }
            }
        }
        if (m_b_bishop_run.at(i)) {
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

                                        m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_b_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_b_bishop.at(i).m_position.y = y;
                                        m_piece.m_b_bishop.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                            if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_pawn.begin() + j;
                                                auto point_1 = m_w_pawn_run.begin() + j;
                                                m_piece.m_w_pawn.erase(point);
                                                m_w_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                            if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_rook.begin() + j;
                                                auto point_1 = m_w_rook_run.begin() + j;
                                                m_piece.m_w_rook.erase(point);
                                                m_w_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                            if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_knight.begin() + j;
                                                auto point_1 = m_w_knight_run.begin() + j;
                                                m_piece.m_w_knight.erase(point);
                                                m_w_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                            if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_bishop.begin() + j;
                                                auto point_1 = m_w_bishop_run.begin() + j;
                                                m_piece.m_w_bishop.erase(point);
                                                m_w_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                            if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_bishop.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_queen.begin() + j;
                                                auto point_1 = m_w_queen_run.begin() + j;
                                                m_piece.m_w_queen.erase(point);
                                                m_w_queen_run.erase(point_1);
                                            }
                                        }
                                        m_b_bishop_run.at(i) = false;
                                        queue = true;
                                    }
                                    else {
                                        if (y > m_piece.m_b_bishop.at(i).m_position.y and x > m_piece.m_b_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_bishop.at(i).m_position.y = y;
                                            m_piece.m_b_bishop.at(i).m_position.x = x;

                                            m_b_bishop_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_b_bishop.at(i).m_position.y and x < m_piece.m_b_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_bishop.at(i).m_position.y = y;
                                            m_piece.m_b_bishop.at(i).m_position.x = x;

                                            m_b_bishop_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_b_bishop.at(i).m_position.y and x > m_piece.m_b_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_bishop.at(i).m_position.y = y;
                                            m_piece.m_b_bishop.at(i).m_position.x = x;

                                            m_b_bishop_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_b_bishop.at(i).m_position.y and x < m_piece.m_b_bishop.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_bishop.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_bishop.at(i).m_position.y = y;
                                            m_piece.m_b_bishop.at(i).m_position.x = x;

                                            m_b_bishop_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_w_queen.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_queen.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_w_queen.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_w_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_w_queen.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.x== m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_w_queen.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                                if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                                if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                                if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                                if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                                if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_w_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //////
                    for (int j = m_piece.m_w_queen.at(i).m_position.y + 1, z = m_piece.m_w_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.y + 1, z = m_piece.m_w_queen.at(i).m_position.x - 1; j < 8 and z > -1 ; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.y -1, z = m_piece.m_w_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_w_queen.at(i).m_position.y - 1, z = m_piece.m_w_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                                if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                                if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                                if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                                if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                                if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_w_queen_run.at(i) = true;
                }
                else {
                    m_w_queen_run.at(i) = false;
                }
            }
        }
        if (m_w_queen_run.at(i)) {
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

                                        m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_w_queen.at(i).m_position.y = y;
                                        m_piece.m_w_queen.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                            if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_pawn.begin() + j;
                                                auto point_1 = m_b_pawn_run.begin() + j;
                                                m_piece.m_b_pawn.erase(point);
                                                m_b_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                            if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_rook.begin() + j;
                                                auto point_1 = m_b_rook_run.begin() + j;
                                                m_piece.m_b_rook.erase(point);
                                                m_b_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                            if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_knight.begin() + j;
                                                auto point_1 = m_b_knight_run.begin() + j;
                                                m_piece.m_b_knight.erase(point);
                                                m_b_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                            if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_bishop.begin() + j;
                                                auto point_1 = m_b_bishop_run.begin() + j;
                                                m_piece.m_b_bishop.erase(point);
                                                m_b_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                            if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_queen.begin() + j;
                                                auto point_1 = m_b_queen_run.begin() + j;
                                                m_piece.m_b_queen.erase(point);
                                                m_b_queen_run.erase(point_1);
                                            }
                                        }
                                        m_w_queen_run.at(i) = false;
                                        queue = false;
                                    }
                                    else {
                                        if (y < m_piece.m_w_queen.at(i).m_position.y and x == m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_w_queen.at(i).m_position.y and x == m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (x < m_piece.m_w_queen.at(i).m_position.x and y == m_piece.m_w_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (x > m_piece.m_w_queen.at(i).m_position.x and y == m_piece.m_w_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        //////////
                                        if (y > m_piece.m_w_queen.at(i).m_position.y and x > m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y > m_piece.m_w_queen.at(i).m_position.y and x < m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_w_queen.at(i).m_position.y and x > m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
                                            queue = false;
                                        }
                                        else if (y < m_piece.m_w_queen.at(i).m_position.y and x < m_piece.m_w_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_queen.at(i).m_position.y = y;
                                            m_piece.m_w_queen.at(i).m_position.x = x;

                                            m_w_queen_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_b_queen.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_queen.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    for (int j = m_piece.m_b_queen.at(i).m_position.x + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.x - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][j]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                                    m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[m_piece.m_b_queen.at(i).m_position.y][j].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.y + 1; j < 8; j++) {
                        if (!m_desk.m_is_open[j][m_piece.m_b_queen.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.y - 1; j > -1; j--) {
                        if (!m_desk.m_is_open[j][m_piece.m_b_queen.at(i).m_position.x]) {
                            for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                                if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                                if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                                if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                                if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                                if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                                    m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][m_piece.m_b_queen.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    //////
                    for (int j = m_piece.m_b_queen.at(i).m_position.y + 1, z = m_piece.m_b_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.y + 1, z = m_piece.m_b_queen.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.y - 1, z = m_piece.m_b_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    for (int j = m_piece.m_b_queen.at(i).m_position.y - 1, z = m_piece.m_b_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
                        if (!m_desk.m_is_open[j][z]) {
                            for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                                if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                                if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                                if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                                if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                                if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                                    m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            break;
                        }
                        m_desk.m_board[j][z].setFillColor(sf::Color(7, 111, 28, 0));
                    }
                    m_b_queen_run.at(i) = true;
                }
                else {
                    m_b_queen_run.at(i) = false;
                }
            }
        }
        if (m_b_queen_run.at(i)) {
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

                                        m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_b_queen.at(i).m_position.y = y;
                                        m_piece.m_b_queen.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                            if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_pawn.begin() + j;
                                                auto point_1 = m_w_pawn_run.begin() + j;
                                                m_piece.m_w_pawn.erase(point);
                                                m_w_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                            if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_rook.begin() + j;
                                                auto point_1 = m_w_rook_run.begin() + j;
                                                m_piece.m_w_rook.erase(point);
                                                m_w_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                            if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_knight.begin() + j;
                                                auto point_1 = m_w_knight_run.begin() + j;
                                                m_piece.m_w_knight.erase(point);
                                                m_w_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                            if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_bishop.begin() + j;
                                                auto point_1 = m_w_bishop_run.begin() + j;
                                                m_piece.m_w_bishop.erase(point);
                                                m_w_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                            if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_queen.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_queen.begin() + j;
                                                auto point_1 = m_w_queen_run.begin() + j;
                                                m_piece.m_w_queen.erase(point);
                                                m_w_queen_run.erase(point_1);
                                            }
                                        }
                                        m_b_queen_run.at(i) = false;
                                        queue = true;
                                    }
                                    else {
                                        if (y < m_piece.m_b_queen.at(i).m_position.y and x == m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_b_queen.at(i).m_position.y and x == m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (x < m_piece.m_b_queen.at(i).m_position.x and y == m_piece.m_b_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (x > m_piece.m_b_queen.at(i).m_position.x and y == m_piece.m_b_queen.at(i).m_position.y) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        //////////
                                        if (y > m_piece.m_b_queen.at(i).m_position.y and x > m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y > m_piece.m_b_queen.at(i).m_position.y and x < m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_b_queen.at(i).m_position.y and x > m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y < m_piece.m_b_queen.at(i).m_position.y and x < m_piece.m_b_queen.at(i).m_position.x) {
                                            reset_desk();

                                            std::swap(m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_queen.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_queen.at(i).m_position.y = y;
                                            m_piece.m_b_queen.at(i).m_position.x = x;

                                            m_b_queen_run.at(i) = false;
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
    for (int i = 0; i < m_piece.m_w_king.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_w_king.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_w_king.at(i).m_position.y - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.y + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.x - 1][m_piece.m_w_king.at(i).m_position.x] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1 and m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1 and m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1 and m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1 and m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1 and m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.y - 1 > -1 and m_piece.m_w_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.y - 1 > -1 and m_piece.m_w_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1 and m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.y + 1 < 8 and m_piece.m_w_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).m_position.y + 1 < 8 and m_piece.m_w_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_w_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                if (m_piece.m_b_pawn.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_pawn.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                if (m_piece.m_b_rook.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_rook.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                if (m_piece.m_b_knight.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_knight.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                if (m_piece.m_b_bishop.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_bishop.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                if (m_piece.m_b_queen.at(j).m_position.y == m_piece.m_w_king.at(i).m_position.y + 1 and m_piece.m_b_queen.at(j).m_position.x == m_piece.m_w_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_w_king.at(i).w_first[i]) {
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1] and m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 2] and m_piece.m_w_rook.at(1).w_castling[1]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1] and m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 2] and m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 3] and m_piece.m_w_rook.at(0).w_castling[0]) {
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                    }
                    m_w_king_run.at(i) = true;
                }
                else {
                    m_w_king_run.at(i) = false;
                }
            }
        }
        if (m_w_king_run.at(i)) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    reset_desk();
                                    if (m_desk.m_is_open[y][x]) {
                                        if (y == m_piece.m_w_king.at(i).m_position.y and x == m_piece.m_w_king.at(i).m_position.x + 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1], m_desk.m_is_open[m_piece.m_w_rook.at(1).m_position.y][m_piece.m_w_rook.at(1).m_position.x]);
                                            m_piece.m_w_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(1).m_sprite.setPosition(m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1].getPosition());
                                            m_piece.m_w_rook.at(1).m_position.y = m_piece.m_w_king.at(i).m_position.y;
                                            m_piece.m_w_rook.at(1).m_position.x = m_piece.m_w_king.at(i).m_position.x + 1;
                                            m_piece.m_w_king.at(i).m_position.y = y;
                                            m_piece.m_w_king.at(i).m_position.x = x;

                                            m_w_king_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y == m_piece.m_w_king.at(i).m_position.y and x == m_piece.m_w_king.at(i).m_position.x - 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1], m_desk.m_is_open[m_piece.m_w_rook.at(0).m_position.y][m_piece.m_w_rook.at(0).m_position.x]);
                                            m_piece.m_w_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_rook.at(0).m_sprite.setPosition(m_desk.m_board[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1].getPosition());
                                            m_piece.m_w_rook.at(0).m_position.y = m_piece.m_w_king.at(i).m_position.y;
                                            m_piece.m_w_rook.at(0).m_position.x = m_piece.m_w_king.at(i).m_position.x - 1;
                                            m_piece.m_w_king.at(i).m_position.y = y;
                                            m_piece.m_w_king.at(i).m_position.x = x;

                                            m_w_king_run.at(i) = false;
                                            queue = true;
                                        }
                                        else {

                                            std::swap(m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_w_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_w_king.at(i).m_position.y = y;
                                            m_piece.m_w_king.at(i).m_position.x = x;
                                            m_w_king_run.at(i) = false;
                                            queue = true;
                                        }
                                    }
                                    else if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_w_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_w_king.at(i).m_position.y = y;
                                        m_piece.m_w_king.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_b_pawn.size(); j++) {
                                            if (m_piece.m_b_pawn.at(j).m_sprite.getPosition() == m_piece.m_w_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_pawn.begin() + j;
                                                auto point_1 = m_b_pawn_run.begin() + j;
                                                m_piece.m_b_pawn.erase(point);
                                                m_b_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_rook.size(); j++) {
                                            if (m_piece.m_b_rook.at(j).m_sprite.getPosition() == m_piece.m_w_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_rook.begin() + j;
                                                auto point_1 = m_b_rook_run.begin() + j;
                                                m_piece.m_b_rook.erase(point);
                                                m_b_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_knight.size(); j++) {
                                            if (m_piece.m_b_knight.at(j).m_sprite.getPosition() == m_piece.m_w_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_knight.begin() + j;
                                                auto point_1 = m_b_knight_run.begin() + j;
                                                m_piece.m_b_knight.erase(point);
                                                m_b_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_bishop.size(); j++) {
                                            if (m_piece.m_b_bishop.at(j).m_sprite.getPosition() == m_piece.m_w_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_bishop.begin() + j;
                                                auto point_1 = m_b_bishop_run.begin() + j;
                                                m_piece.m_b_bishop.erase(point);
                                                m_b_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_b_queen.size(); j++) {
                                            if (m_piece.m_b_queen.at(j).m_sprite.getPosition() == m_piece.m_w_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_b_queen.begin() + j;
                                                auto point_1 = m_b_queen_run.begin() + j;
                                                m_piece.m_b_queen.erase(point);
                                                m_b_queen_run.erase(point_1);
                                            }
                                        }
                                    }
                                    m_w_king_run.at(i) = false;
                                    queue = false;
                                    m_piece.m_w_king.at(i).w_first[i] = false;
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
    for (int i = 0; i < m_piece.m_b_king.size(); i++) {
        if (m_event.type == sf::Event::MouseButtonPressed) {
            if (m_event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_piece.m_b_king.at(i).m_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    reset_desk();
                    if (m_piece.m_b_king.at(i).m_position.y - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.y + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x +! 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.y - 1 > -1 and m_piece.m_b_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y- 1][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.y - 1 > -1 and m_piece.m_b_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + !1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y - 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y- 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.y + 1 < 8 and m_piece.m_b_king.at(i).m_position.x - 1 > -1) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x - 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).m_position.y + 1 < 8 and m_piece.m_b_king.at(i).m_position.x + 1 < 8) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        else if (!m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_b_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1]) {
                            for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                if (m_piece.m_w_pawn.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_pawn.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                if (m_piece.m_w_rook.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_rook.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + !1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                if (m_piece.m_w_knight.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_knight.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                if (m_piece.m_w_bishop.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_bishop.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                            for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                if (m_piece.m_w_queen.at(j).m_position.y == m_piece.m_b_king.at(i).m_position.y + 1 and m_piece.m_w_queen.at(j).m_position.x == m_piece.m_b_king.at(i).m_position.x + 1) {
                                    m_desk.m_board[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                                }
                            }
                        }
                    }
                    if (m_piece.m_b_king.at(i).b_first[i]) {
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1] and m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 2] and m_piece.m_b_rook.at(1).b_castling[1]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                        if (m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1] and m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 2] and m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 3] and m_piece.m_b_rook.at(0).b_castling[0]) {
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].setFillColor(sf::Color(7, 111, 28, 0));
                            m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 2].setFillColor(sf::Color(7, 111, 28, 0));
                        }
                    }
                    m_b_king_run.at(i) = true;
                }
                else {
                    m_b_king_run.at(i) = false;
                }
            }
        }
        if (m_b_king_run.at(i)) {
            if (m_event.type == sf::Event::MouseButtonPressed) {
                if (m_event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                    for (int y = 0; y < 8; y++) {
                        for (int x = 0; x < 8; x++) {
                            if (m_desk.m_board[y][x].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                                if (m_desk.m_board[y][x].getFillColor() == sf::Color(7, 111, 28, 0)) {
                                    reset_desk();
                                    if (m_desk.m_is_open[y][x]) {
                                        if (y == m_piece.m_b_king.at(i).m_position.y and x == m_piece.m_b_king.at(i).m_position.x + 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1], m_desk.m_is_open[m_piece.m_b_rook.at(1).m_position.y][m_piece.m_b_rook.at(1).m_position.x]);
                                            m_piece.m_b_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(1).m_sprite.setPosition(m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1].getPosition());
                                            m_piece.m_b_rook.at(1).m_position.y = m_piece.m_b_king.at(i).m_position.y;
                                            m_piece.m_b_rook.at(1).m_position.x = m_piece.m_b_king.at(i).m_position.x + 1;
                                            m_piece.m_b_king.at(i).m_position.y = y;
                                            m_piece.m_b_king.at(i).m_position.x = x;


                                            m_b_king_run.at(i) = false;
                                            queue = true;
                                        }
                                        else if (y == m_piece.m_b_king.at(i).m_position.y and x == m_piece.m_b_king.at(i).m_position.x - 2) {
                                            std::swap(m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            std::swap(m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + -1], m_desk.m_is_open[m_piece.m_b_rook.at(1).m_position.y][m_piece.m_b_rook.at(0).m_position.x]);
                                            m_piece.m_b_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_rook.at(0).m_sprite.setPosition(m_desk.m_board[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1].getPosition());
                                            m_piece.m_b_rook.at(0).m_position.y = m_piece.m_b_king.at(i).m_position.y;
                                            m_piece.m_b_rook.at(0).m_position.x = m_piece.m_b_king.at(i).m_position.x - 1;
                                            m_piece.m_b_king.at(i).m_position.y = y;
                                            m_piece.m_b_king.at(i).m_position.x = x;


                                            m_b_king_run.at(i) = false;
                                            queue = true;
                                        }
                                        else {
                                            std::swap(m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x], m_desk.m_is_open[y][x]);
                                            m_piece.m_b_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                            m_piece.m_b_king.at(i).m_position.y = y;
                                            m_piece.m_b_king.at(i).m_position.x = x;
                                            m_b_king_run.at(i) = false;
                                            queue = true;
                                        }
                                    }
                                    else if (!m_desk.m_is_open[y][x]) {
                                        reset_desk();

                                        m_desk.m_is_open[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x] = true;
                                        m_desk.m_is_open[y][x] = false;
                                        m_piece.m_b_king.at(i).m_sprite.setPosition(m_desk.m_board[y][x].getPosition());
                                        m_piece.m_b_king.at(i).m_position.y = y;
                                        m_piece.m_b_king.at(i).m_position.x = x;
                                        for (int j = 0; j < m_piece.m_w_pawn.size(); j++) {
                                            if (m_piece.m_w_pawn.at(j).m_sprite.getPosition() == m_piece.m_b_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_pawn.begin() + j;
                                                auto point_1 = m_w_pawn_run.begin() + j;
                                                m_piece.m_w_pawn.erase(point);
                                                m_w_pawn_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_rook.size(); j++) {
                                            if (m_piece.m_w_rook.at(j).m_sprite.getPosition() == m_piece.m_b_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_rook.begin() + j;
                                                auto point_1 = m_w_rook_run.begin() + j;
                                                m_piece.m_w_rook.erase(point);
                                                m_w_rook_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_knight.size(); j++) {
                                            if (m_piece.m_w_knight.at(j).m_sprite.getPosition() == m_piece.m_b_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_knight.begin() + j;
                                                auto point_1 = m_w_knight_run.begin() + j;
                                                m_piece.m_w_knight.erase(point);
                                                m_w_knight_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_bishop.size(); j++) {
                                            if (m_piece.m_w_bishop.at(j).m_sprite.getPosition() == m_piece.m_b_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_bishop.begin() + j;
                                                auto point_1 = m_w_bishop_run.begin() + j;
                                                m_piece.m_w_bishop.erase(point);
                                                m_w_bishop_run.erase(point_1);
                                            }
                                        }
                                        for (int j = 0; j < m_piece.m_w_queen.size(); j++) {
                                            if (m_piece.m_w_queen.at(j).m_sprite.getPosition() == m_piece.m_b_king.at(i).m_sprite.getPosition()) {
                                                auto point = m_piece.m_w_queen.begin() + j;
                                                auto point_1 = m_w_queen_run.begin() + j;
                                                m_piece.m_w_queen.erase(point);
                                                m_w_queen_run.erase(point_1);
                                            }
                                        }
                                    }
                                    m_b_king_run.at(i) = false;
                                    queue = true;
                                    m_piece.m_b_king.at(i).b_first[i] = false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::w_king_desk() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m_desk.m_w_king_can[i][j] = 1;
        }
    }

    for (int i = 0; i < m_piece.m_w_pawn.size(); i++) {
        m_desk.m_w_king_can[m_piece.m_w_pawn.at(i).m_position.y][m_piece.m_w_pawn.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_w_rook.size(); i++) {
        m_desk.m_w_king_can[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_w_knight.size(); i++) {
        m_desk.m_w_king_can[m_piece.m_w_knight.at(i).m_position.y][m_piece.m_w_knight.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_w_bishop.size(); i++) {
        m_desk.m_w_king_can[m_piece.m_w_bishop.at(i).m_position.y][m_piece.m_w_bishop.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_w_queen.size(); i++) {
        m_desk.m_w_king_can[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x] = 0;
    }

    for (int i = 0; i < m_piece.m_b_pawn.size(); i++) {
        if (m_piece.m_b_pawn.at(i).m_position.x + 1 < 8 and m_piece.m_b_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1] = 0;
            m_desk.m_w_king_can[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_b_pawn.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_b_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_pawn.at(i).m_position.y + 1][m_piece.m_b_pawn.at(i).m_position.x - 1] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_b_rook.size(); i++) {
        for (int j = m_piece.m_b_rook.at(i).m_position.x + 1; j < 8; j++) {
           if (m_piece.m_w_king.at(0).m_position.x != j and m_piece.m_w_king.at(0).m_position.y != m_piece.m_b_rook.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
           }
            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_b_rook.at(i).m_position.x - 1; j > -1; j--) {
            if (m_piece.m_w_king.at(0).m_position.x != j and m_piece.m_w_king.at(0).m_position.y != m_piece.m_b_rook.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[m_piece.m_b_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_b_rook.at(i).m_position.y + 1; j < 8; j++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != m_piece.m_b_rook.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_b_rook.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
           }
            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
        }
        for (int j = m_piece.m_b_rook.at(i).m_position.y - 1; j > -1; j--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != m_piece.m_b_rook.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_b_rook.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_b_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][m_piece.m_b_rook.at(i).m_position.x] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_b_knight.size(); i++) {


        ///////////
        if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y + 2][m_piece.m_b_knight.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y - 2][m_piece.m_b_knight.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x - 2 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y + 1][m_piece.m_b_knight.at(i).m_position.x - 2] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x - 2 < -1) {
            m_desk.m_w_king_can[m_piece.m_b_knight.at(i).m_position.y - 1][m_piece.m_b_knight.at(i).m_position.x - 2] = 0;
        }
    }
    
    for (int i = 0; i < m_piece.m_b_bishop.size(); i++){
        for (int j = m_piece.m_b_bishop.at(i).m_position.y + 1, z = m_piece.m_b_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
               
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_bishop.at(i).m_position.y + 1, z = m_piece.m_b_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;

                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_bishop.at(i).m_position.y - 1, z = m_piece.m_b_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_bishop.at(i).m_position.y - 1, z = m_piece.m_b_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
    }
    //////////
    for (int i = 0; i < m_piece.m_b_queen.size(); i++) {
        for (int j = m_piece.m_b_queen.at(i).m_position.x + 1; j < 8; j++) {
            if (m_piece.m_w_king.at(0).m_position.x != j and m_piece.m_w_king.at(0).m_position.y != m_piece.m_b_queen.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.x - 1; j > -1; j--) {
            if (m_piece.m_w_king.at(0).m_position.x != j and m_piece.m_w_king.at(0).m_position.y != m_piece.m_b_queen.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_b_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_b_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[m_piece.m_b_queen.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.y + 1; j < 8; j++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != m_piece.m_b_queen.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_b_queen.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.y - 1; j > -1; j--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != m_piece.m_b_queen.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_b_queen.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_b_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
                
            }
            m_desk.m_w_king_can[j][m_piece.m_b_queen.at(i).m_position.x] = 0;
        }
        //////
        for (int j = m_piece.m_b_queen.at(i).m_position.y + 1, z = m_piece.m_b_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.y + 1, z = m_piece.m_b_queen.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.y - 1, z = m_piece.m_b_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
               
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_b_queen.at(i).m_position.y - 1, z = m_piece.m_b_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
            if (m_piece.m_w_king.at(0).m_position.y != j and m_piece.m_w_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_w_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_w_king_can[j][z] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_b_king.size(); i++){
        if (m_piece.m_b_king.at(i).m_position.y + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x] = 0;
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x + 1] = 0;
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y + 1][m_piece.m_b_king.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_b_king.at(i).m_position.y - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x] = 0;
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x + 1] = 0;
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y - 1][m_piece.m_b_king.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_b_king.at(i).m_position.x + 1 < 8) {
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_b_king.at(i).m_position.x - 1 > -1) {
            m_desk.m_w_king_can[m_piece.m_b_king.at(i).m_position.y][m_piece.m_b_king.at(i).m_position.x - 1] = 0;
        }
    }
}

void Game::b_king_desk() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m_desk.m_b_king_can[i][j] = 1;
        }
    }

    for (int i = 0; i < m_piece.m_b_pawn.size(); i++) {
        m_desk.m_b_king_can[m_piece.m_b_pawn.at(i).m_position.y][m_piece.m_b_pawn.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_b_rook.size(); i++) {
        m_desk.m_b_king_can[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_b_knight.size(); i++) {
        m_desk.m_b_king_can[m_piece.m_b_knight.at(i).m_position.y][m_piece.m_b_knight.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_b_bishop.size(); i++) {
        m_desk.m_b_king_can[m_piece.m_b_bishop.at(i).m_position.y][m_piece.m_b_bishop.at(i).m_position.x] = 0;
    }
    for (int i = 0; i < m_piece.m_b_queen.size(); i++) {
        m_desk.m_b_king_can[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x] = 0;
    }

    for (int i = 0; i < m_piece.m_w_pawn.size(); i++) {
        if (m_piece.m_w_pawn.at(i).m_position.x + 1 < 8 and m_piece.m_w_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1] = 0;
            m_desk.m_b_king_can[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_w_pawn.at(i).m_position.x + 1 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_w_pawn.at(i).m_position.x - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_pawn.at(i).m_position.y - 1][m_piece.m_w_pawn.at(i).m_position.x - 1] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_w_rook.size(); i++) {
        for (int j = m_piece.m_w_rook.at(i).m_position.x + 1; j < 8; j++) {
            if (m_piece.m_b_king.at(0).m_position.x != j and m_piece.m_b_king.at(0).m_position.y != m_piece.m_w_rook.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
               
            }
            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_w_rook.at(i).m_position.x - 1; j > -1; j--) {
            if (m_piece.m_w_king.at(0).m_position.x != j and m_piece.m_w_king.at(0).m_position.y != m_piece.m_w_rook.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_rook.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[m_piece.m_w_rook.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_w_rook.at(i).m_position.y + 1; j < 8; j++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != m_piece.m_w_rook.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_w_rook.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
        }
        for (int j = m_piece.m_w_rook.at(i).m_position.y - 1; j > -1; j--) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != m_piece.m_w_rook.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_w_rook.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_rook.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
               
            }
            m_desk.m_b_king_can[j][m_piece.m_w_rook.at(i).m_position.x] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_w_knight.size(); i++) {
        ///////////
        if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y + 2][m_piece.m_w_knight.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y - 2][m_piece.m_w_knight.at(i).m_position.x - 1] = 0;
        }

        if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x - 2 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y + 1][m_piece.m_w_knight.at(i).m_position.x - 2] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x + 2] = 0;
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x - 2 < -1) {
            m_desk.m_b_king_can[m_piece.m_w_knight.at(i).m_position.y - 1][m_piece.m_w_knight.at(i).m_position.x - 2] = 0;
        }
    }

    for (int i = 0; i < m_piece.m_w_bishop.size(); i++) {
        for (int j = m_piece.m_w_bishop.at(i).m_position.y + 1, z = m_piece.m_w_bishop.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_bishop.at(i).m_position.y + 1, z = m_piece.m_w_bishop.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_bishop.at(i).m_position.y - 1, z = m_piece.m_w_bishop.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_bishop.at(i).m_position.y - 1, z = m_piece.m_w_bishop.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
    }
    //////////
    for (int i = 0; i < m_piece.m_w_queen.size(); i++) {
        for (int j = m_piece.m_w_bishop.at(i).m_position.x + 1; j < 8; j++) {
            if (m_piece.m_b_king.at(0).m_position.x != j and m_piece.m_b_king.at(0).m_position.y != m_piece.m_w_bishop.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.x - 1; j > -1; j--) {
            if (m_piece.m_b_king.at(0).m_position.x != j and m_piece.m_b_king.at(0).m_position.y != m_piece.m_w_queen.at(i).m_position.y) {
                if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][j]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_pawn.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_rook.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_knight.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_bishop.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_w_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.y == m_piece.m_w_queen.at(i).m_position.y and m_piece.m_b_queen.at(z).m_position.x == j) {
                            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
                        }
                    }
                    break;
                }
               
            }
            m_desk.m_b_king_can[m_piece.m_w_queen.at(i).m_position.y][j] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.y + 1; j < 8; j++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != m_piece.m_w_queen.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_w_queen.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.y - 1; j > -1; j--) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != m_piece.m_w_queen.at(i).m_position.x) {
                if (!m_desk.m_is_open[j][m_piece.m_w_queen.at(i).m_position.x]) {
                    for (int z = 0; z < m_piece.m_w_pawn.size(); z++) {
                        if (m_piece.m_w_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_pawn.size(); z++) {
                        if (m_piece.m_b_pawn.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_pawn.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_rook.size(); z++) {
                        if (m_piece.m_w_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_rook.size(); z++) {
                        if (m_piece.m_b_rook.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_rook.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_knight.size(); z++) {
                        if (m_piece.m_w_knight.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_knight.size(); z++) {
                        if (m_piece.m_b_knight.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_knight.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_bishop.size(); z++) {
                        if (m_piece.m_w_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_bishop.size(); z++) {
                        if (m_piece.m_b_bishop.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_bishop.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_w_queen.size(); z++) {
                        if (m_piece.m_w_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_w_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    for (int z = 0; z < m_piece.m_b_queen.size(); z++) {
                        if (m_piece.m_b_queen.at(z).m_position.x == m_piece.m_w_queen.at(i).m_position.x and m_piece.m_b_queen.at(z).m_position.y == j) {
                            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][m_piece.m_w_queen.at(i).m_position.x] = 0;
        }
        //////
        for (int j = m_piece.m_w_queen.at(i).m_position.y + 1, z = m_piece.m_w_queen.at(i).m_position.x + 1; j < 8 and z < 8; j++, z++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.y + 1, z = m_piece.m_w_queen.at(i).m_position.x - 1; j < 8 and z > -1; j++, z--) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.y - 1, z = m_piece.m_w_queen.at(i).m_position.x + 1; j > -1 and z < 8; j--, z++) {
            if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                if (!m_desk.m_is_open[j][z]) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
            
            m_desk.m_b_king_can[j][z] = 0;
        }
        for (int j = m_piece.m_w_queen.at(i).m_position.y - 1, z = m_piece.m_w_queen.at(i).m_position.x - 1; j > -1 and z > -1; j--, z--) {

            if (!m_desk.m_is_open[j][z]) {
                if (m_piece.m_b_king.at(0).m_position.y != j and m_piece.m_b_king.at(0).m_position.x != z) {
                    for (int f = 0; f < m_piece.m_w_pawn.size(); f++) {
                        if (m_piece.m_w_pawn.at(f).m_position.y == j and m_piece.m_w_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_pawn.size(); f++) {
                        if (m_piece.m_b_pawn.at(f).m_position.y == j and m_piece.m_b_pawn.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_rook.size(); f++) {
                        if (m_piece.m_w_rook.at(f).m_position.y == j and m_piece.m_w_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_rook.size(); f++) {
                        if (m_piece.m_b_rook.at(f).m_position.y == j and m_piece.m_b_rook.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_knight.size(); f++) {
                        if (m_piece.m_w_knight.at(f).m_position.y == j and m_piece.m_w_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_knight.size(); f++) {
                        if (m_piece.m_b_knight.at(f).m_position.y == j and m_piece.m_b_knight.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_bishop.size(); f++) {
                        if (m_piece.m_w_bishop.at(f).m_position.y == j and m_piece.m_w_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_bishop.size(); f++) {
                        if (m_piece.m_b_bishop.at(f).m_position.y == j and m_piece.m_b_bishop.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_w_queen.size(); f++) {
                        if (m_piece.m_w_queen.at(f).m_position.y == j and m_piece.m_w_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    for (int f = 0; f < m_piece.m_b_queen.size(); f++) {
                        if (m_piece.m_b_queen.at(f).m_position.y == j and m_piece.m_b_queen.at(f).m_position.x == z) {
                            m_desk.m_b_king_can[j][z] = 0;
                        }
                    }
                    break;
                }
                
            }
        
            m_desk.m_b_king_can[j][z] = 0;
        }
    }
    for (int i = 0; i < m_piece.m_w_king.size(); i++) {
        if (m_piece.m_w_king.at(i).m_position.y + 1 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x] = 0;
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x + 1] = 0;
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y + 1][m_piece.m_w_king.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_w_king.at(i).m_position.y - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x] = 0;
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x + 1] = 0;
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y - 1][m_piece.m_w_king.at(i).m_position.x - 1] = 0;
        }
        if (m_piece.m_w_king.at(i).m_position.x + 1 < 8) {
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x + 1] = 0;
        }
        if (m_piece.m_w_king.at(i).m_position.x - 1 > -1) {
            m_desk.m_b_king_can[m_piece.m_w_king.at(i).m_position.y][m_piece.m_w_king.at(i).m_position.x - 1] = 0;
        }
    }
}

void Game::w_king_desk_draw() {
    b_king_desk();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << m_desk.m_b_king_can[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Game::w_check() {
    for (int i = 0; i < m_piece.m_b_pawn.size(); i++) {
        if (m_piece.m_b_pawn.at(i).m_position.y + 1 < 8) {
            if (m_piece.m_b_pawn.at(i).m_position.y + 1 == m_piece.m_w_king.at(0).m_position.y and (m_piece.m_b_pawn.at(i).m_position.x + 1 == m_piece.m_w_king.at(0).m_position.x or m_piece.m_b_pawn.at(i).m_position.x - 1 == m_piece.m_w_king.at(0).m_position.x)) {
                check = true;
            }
        }
    }
    for (int i = 0; i < m_piece.m_b_rook.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (m_piece.m_b_rook.at(i).m_position.y + j < 8) {
                if (m_piece.m_b_rook.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_rook.at(i).m_position.x == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y + n][m_piece.m_b_rook.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }

                }
            }
            if (m_piece.m_b_rook.at(i).m_position.y - j > -1) {
                if (m_piece.m_b_rook.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_rook.at(i).m_position.x == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y - n][m_piece.m_b_rook.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_rook.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_rook.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x and m_piece.m_b_rook.at(i).m_position.y == m_piece.m_w_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_rook.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_rook.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x and m_piece.m_b_rook.at(i).m_position.y == m_piece.m_w_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_rook.at(i).m_position.y][m_piece.m_b_rook.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }

        }
    }
    for (int i = 0; i < m_piece.m_b_bishop.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (m_piece.m_b_bishop.at(i).m_position.y + j < 8 and m_piece.m_b_bishop.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_bishop.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_bishop.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y + n][m_piece.m_b_bishop.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_bishop.at(i).m_position.y - j > -1 and m_piece.m_b_bishop.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_bishop.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_bishop.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y - n][m_piece.m_b_bishop.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_bishop.at(i).m_position.y + j < 8 and m_piece.m_b_bishop.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_bishop.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_bishop.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y + n][m_piece.m_b_bishop.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_bishop.at(i).m_position.y - j > -1 and m_piece.m_b_bishop.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_bishop.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_bishop.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_bishop.at(i).m_position.y - n][m_piece.m_b_bishop.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m_piece.m_b_knight.size(); i++) {
        if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
            if (m_piece.m_b_knight.at(i).m_position.y + 2 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x + 1 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 2 < 8 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
            if (m_piece.m_b_knight.at(i).m_position.y + 2 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x - 1 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x + 1 < 8) {
            if (m_piece.m_b_knight.at(i).m_position.y - 2 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x + 1 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 2 > -1 and m_piece.m_b_knight.at(i).m_position.x - 1 > -1) {
            if (m_piece.m_b_knight.at(i).m_position.y - 2 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x - 1 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
            if (m_piece.m_b_knight.at(i).m_position.y + 1 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x + 2 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y + 1 < 8 and m_piece.m_b_knight.at(i).m_position.x - 2 > -1) {
            if (m_piece.m_b_knight.at(i).m_position.y + 1 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x - 2 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x + 2 < 8) {
            if (m_piece.m_b_knight.at(i).m_position.y - 1 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x + 2 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_b_knight.at(i).m_position.y - 1 > -1 and m_piece.m_b_knight.at(i).m_position.x - 2 > -1) {
            if (m_piece.m_b_knight.at(i).m_position.y - 1 == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_knight.at(i).m_position.x - 2 == m_piece.m_w_king.at(0).m_position.x) {
                check = true;
            }
        }
    }
    ///////
    for (int i = 0; i < m_piece.m_b_queen.size(); i++) {
        for (int j = 0, z = 0; j < 8, z < 8; j++, z++) {
            if (m_piece.m_b_queen.at(i).m_position.y + j < 8) {
                if (m_piece.m_b_queen.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y + n][m_piece.m_b_queen.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }

                }
            }
            if (m_piece.m_b_queen.at(i).m_position.y - j > -1) {
                if (m_piece.m_b_queen.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y - n][m_piece.m_b_queen.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_queen.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x and m_piece.m_b_queen.at(i).m_position.y == m_piece.m_w_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_queen.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x and m_piece.m_b_queen.at(i).m_position.y == m_piece.m_w_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y][m_piece.m_b_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            ///
            if (m_piece.m_b_queen.at(i).m_position.y + j < 8 and m_piece.m_b_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_queen.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y + n][m_piece.m_b_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_queen.at(i).m_position.y - j > -1 and m_piece.m_b_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_b_queen.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x + j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y - n][m_piece.m_b_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_queen.at(i).m_position.y + j < 8 and m_piece.m_b_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_queen.at(i).m_position.y + j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y + n][m_piece.m_b_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_b_queen.at(i).m_position.y - j > -1 and m_piece.m_b_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_b_queen.at(i).m_position.y - j == m_piece.m_w_king.at(0).m_position.y and m_piece.m_b_queen.at(i).m_position.x - j == m_piece.m_w_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_b_queen.at(i).m_position.y - n][m_piece.m_b_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
        }
    }
}

void Game::b_check() {
    for (int i = 0; i < m_piece.m_w_pawn.size(); i++) {
        if (m_piece.m_w_pawn.at(i).m_position.y + 1 < 8) {
            if (m_piece.m_w_pawn.at(i).m_position.y - 1 == m_piece.m_b_king.at(0).m_position.y and (m_piece.m_w_pawn.at(i).m_position.x + 1 == m_piece.m_b_king.at(0).m_position.x or m_piece.m_w_pawn.at(i).m_position.x - 1 == m_piece.m_b_king.at(0).m_position.x)) {
                check = true;
            }
        }
    }
    for (int i = 0; i < m_piece.m_w_rook.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (m_piece.m_w_rook.at(i).m_position.y + j < 8) {
                if (m_piece.m_w_rook.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_rook.at(i).m_position.x == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y + n][m_piece.m_w_rook.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }

                }
            }
            if (m_piece.m_w_rook.at(i).m_position.y - j > -1) {
                if (m_piece.m_w_rook.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_rook.at(i).m_position.x == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y - n][m_piece.m_w_rook.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_rook.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_rook.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x and m_piece.m_w_rook.at(i).m_position.y == m_piece.m_b_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_rook.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_rook.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x and m_piece.m_w_rook.at(i).m_position.y == m_piece.m_b_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_rook.at(i).m_position.y][m_piece.m_w_rook.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }

        }
    }
    for (int i = 0; i < m_piece.m_w_bishop.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (m_piece.m_w_bishop.at(i).m_position.y + j < 8 and m_piece.m_w_bishop.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_bishop.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_bishop.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y + n][m_piece.m_w_bishop.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_bishop.at(i).m_position.y - j > -1 and m_piece.m_w_bishop.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_bishop.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_bishop.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y - n][m_piece.m_w_bishop.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_bishop.at(i).m_position.y + j < 8 and m_piece.m_w_bishop.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_bishop.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_bishop.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y + n][m_piece.m_w_bishop.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_bishop.at(i).m_position.y - j > -1 and m_piece.m_w_bishop.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_bishop.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_bishop.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_bishop.at(i).m_position.y - n][m_piece.m_w_bishop.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < m_piece.m_w_knight.size(); i++){
        if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
            if (m_piece.m_w_knight.at(i).m_position.y + 2 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x + 1 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y + 2 < 8 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
            if (m_piece.m_w_knight.at(i).m_position.y + 2 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x - 1 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x + 1 < 8) {
            if (m_piece.m_w_knight.at(i).m_position.y - 2 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x + 1 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 2 > -1 and m_piece.m_w_knight.at(i).m_position.x - 1 > -1) {
            if (m_piece.m_w_knight.at(i).m_position.y - 2 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x - 1 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
            if (m_piece.m_w_knight.at(i).m_position.y + 1 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x + 2 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y + 1 < 8 and m_piece.m_w_knight.at(i).m_position.x - 2 > -1) {
            if (m_piece.m_w_knight.at(i).m_position.y + 1 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x - 2 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x + 2 < 8) {
            if (m_piece.m_w_knight.at(i).m_position.y - 1 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x + 2 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
        if (m_piece.m_w_knight.at(i).m_position.y - 1 > -1 and m_piece.m_w_knight.at(i).m_position.x - 2 > -1) {
            if (m_piece.m_w_knight.at(i).m_position.y - 1 == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_knight.at(i).m_position.x - 2 == m_piece.m_b_king.at(0).m_position.x) {
                check = true;
            }
        }
    }
    ///////
    for (int i = 0; i < m_piece.m_w_queen.size(); i++) {
        for (int j = 0, z = 0; j < 8, z < 8; j++, z++) {
            if (m_piece.m_w_queen.at(i).m_position.y + j < 8) {
                if (m_piece.m_w_queen.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y + n][m_piece.m_w_queen.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }

                }
            }
            if (m_piece.m_w_queen.at(i).m_position.y - j > -1) {
                if (m_piece.m_w_queen.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y - n][m_piece.m_w_queen.at(i).m_position.x]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_queen.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x and m_piece.m_w_queen.at(i).m_position.y == m_piece.m_b_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_queen.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x and m_piece.m_w_queen.at(i).m_position.y == m_piece.m_b_king.at(0).m_position.y) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y][m_piece.m_w_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            ///
            if (m_piece.m_w_queen.at(i).m_position.y + j < 8 and m_piece.m_w_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_queen.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y + n][m_piece.m_w_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_queen.at(i).m_position.y - j > -1 and m_piece.m_w_queen.at(i).m_position.x + j < 8) {
                if (m_piece.m_w_queen.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x + j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y - n][m_piece.m_w_queen.at(i).m_position.x + n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_queen.at(i).m_position.y + j < 8 and m_piece.m_w_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_queen.at(i).m_position.y + j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y + n][m_piece.m_w_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
            if (m_piece.m_w_queen.at(i).m_position.y - j > -1 and m_piece.m_w_queen.at(i).m_position.x - j > -1) {
                if (m_piece.m_w_queen.at(i).m_position.y - j == m_piece.m_b_king.at(0).m_position.y and m_piece.m_w_queen.at(i).m_position.x - j == m_piece.m_b_king.at(0).m_position.x) {
                    open = true;
                    for (int n = 1; n < j; n++) {
                        if (!m_desk.m_is_open[m_piece.m_w_queen.at(i).m_position.y - n][m_piece.m_w_queen.at(i).m_position.x - n]) {
                            open = false;
                        }
                    }
                    if (open) {
                        check = true;
                    }
                }
            }
        }
    }
}
