//
//  GamePlay.cpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 6/12/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#include "GamePlay.hpp"
#include "PauseGame.hpp"
#include "WinOrLose.hpp"
#include <time.h>
#include <iostream>
#include <cmath>

GamePlay::GamePlay(std::shared_ptr<Engine::Context> &context)
: m_context(context), m_score(0), m_playerDir({0.0f,0.0f}),m_enemyVelocity(0.2f), m_enemyDir({m_enemyVelocity, 0.0f}), m_isPasued(false), m_playerVelocity(0.5f), m_missileVelocity(1.5f), m_seeMissile(false){
    srand(time(nullptr));
}

GamePlay::~GamePlay(){
    
}

void GamePlay::Init(){
    //Player Info
    m_context->m_assest->AddTexture(PLAYER, "/Users/alexisrodriguez/code/sfml_projects/shmup_sfml/shmup_sfml/shmup_sfml/Assets/Textures/spaceship.png");
    m_player.setTexture(m_context->m_assest->getTexture(PLAYER));
    m_player.setScale(0.1f, 0.1f);
    m_player.setPosition(m_context->m_window->getSize().x / 2 - m_player.getGlobalBounds().width, m_context->m_window->getSize().y / 2 - m_player.getGlobalBounds().height);
    //missile
    m_context->m_assest->AddTexture(MISSILE, "/Users/alexisrodriguez/code/sfml_projects/shmup_sfml/shmup_sfml/shmup_sfml/Assets/Textures/missile.png");
    m_missile.setTexture(m_context->m_assest->getTexture(MISSILE));
    m_missile.setScale(0.05, 0.05);
    m_missile.setPosition(m_context->m_window->getSize().x / 2 - m_missile.getGlobalBounds().width, m_context->m_window->getSize().y / 2 - m_missile.getGlobalBounds().height);
    m_missileDir = {0.0f, -m_missileVelocity};
    
    //enemies
    m_context->m_assest->AddTexture(ENEMY, "/Users/alexisrodriguez/code/sfml_projects/shmup_sfml/shmup_sfml/shmup_sfml/Assets/Textures/enemy.png");
    for(auto &e : m_enemies){
        e.isSeen = true;
        e.enemy.setTexture(m_context->m_assest->getTexture(ENEMY));
        e.enemy.setScale(0.03f, 0.03f);
        e.enemy.setPosition(rand() % static_cast<int>((m_context->m_window->getSize().x - e.enemy.getGlobalBounds().width)) + 1, rand() % static_cast<int>(((m_context->m_window->getSize().y / 2) - e.enemy.getGlobalBounds().height)) + 1);
    }
    //score
    m_scoreTxt.setFont(m_context->m_assest->getFont(MAIN_FONT));
    m_scoreTxt.setPosition({0.0f, 0.0f});
    m_scoreTxt.setString("Score : " + std::to_string(m_score));
    
    
}
void GamePlay::ProcessInput(){
    sf::Event ev;
    while(m_context->m_window->pollEvent(ev)){
        if(ev.type == sf::Event::Closed){
            m_context->m_window->close();
        }else if(ev.type == sf::Event::KeyPressed){
            switch(ev.key.code){
                case sf::Keyboard::W:
                    m_playerDir = {0.0f, -m_playerVelocity};
                    break;
                case sf::Keyboard::S:
                    m_playerDir = {0.0f, m_playerVelocity};
                    break;
                case sf::Keyboard::D:
                    m_playerDir = {m_playerVelocity, 0.0f};
                    break;
                case sf::Keyboard::A:
                    m_playerDir = {-m_playerVelocity, 0.0f};
                    break;
                case sf::Keyboard::Space:
                    if(!m_seeMissile){
                        m_seeMissile = true;
                        m_missile.setPosition(m_player.getPosition().x + m_player.getGlobalBounds().width/2,m_player.getPosition().y + m_player.getGlobalBounds().height/2 );
                    }
                    break;
                case sf::Keyboard::Escape:
                    m_context->m_states->add(std::make_unique<PauseGame>(m_context), false);
                    break;
                default: break;
            }
        }
    }
}
void GamePlay::Update(sf::Time deltatime){
    if(m_score >= 400){
        m_context->m_states->add(std::make_unique<WinOrLose>(m_context, true, m_score, 1), true);
    }
    auto ph = m_player.getGlobalBounds().height;
    auto pw = m_player.getGlobalBounds().width;
   
    if(m_player.getPosition().x > m_context->m_window->getSize().x){
        m_player.setPosition(0.0f-pw, m_player.getPosition().y);
    }else if(m_player.getPosition().y > m_context->m_window->getSize().y){
        m_player.setPosition(m_player.getPosition().x, 0.0f-ph);
    }else if(m_player.getPosition().x + pw < 0){
        m_player.setPosition(m_context->m_window->getSize().x ,m_player.getPosition().y);
    }else if(m_player.getPosition().y + ph < 0){
        m_player.setPosition(m_player.getPosition().x, m_context->m_window->getSize().y);
    }else{
            ;
    }
    m_player.move(m_playerDir);
    if(m_missile.getPosition().y - m_missile.getGlobalBounds().height < 0){
        m_seeMissile = false;
        m_missileVelocity = 0.0f;
    }
    if(m_seeMissile){
        m_missile.move(m_missileDir);
    }
    for(auto &e : m_enemies){
        if(e.enemy.getGlobalBounds().intersects(m_missile.getGlobalBounds())){
            m_score += 10;
            m_scoreTxt.setString("Score : " + std::to_string(m_score));
            e.isSeen = false;
        }
            if(e.isSeen && e.enemy.getPosition().x < m_context->m_window->getSize().x){
                e.move(m_enemyDir);
            }else{
                e.enemy.setPosition(-e.enemy.getGlobalBounds().width,rand() % static_cast<int>(((m_context->m_window->getSize().y / 2) - e.enemy.getGlobalBounds().height)) + 1);
                e.isSeen = true;
            }
            
    }
    
}
void GamePlay::Draw(){
    m_context->m_window->clear();
    m_context->m_window->draw(m_player);
    for(auto &e: m_enemies){
        if(e.isSeen)
            m_context->m_window->draw(e.enemy);
    }
    if(m_seeMissile)
        m_context->m_window->draw(m_missile);
    m_context->m_window->draw(m_scoreTxt);
    
    m_context->m_window->display();
}

void GamePlay::Pause(){
    m_isPasued = true;
}
void GamePlay::Start(){
    m_isPasued = false;
}
