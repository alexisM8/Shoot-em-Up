//
//  MainMenu.cpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#include "MainMenu.hpp"
#include "GamePlay.hpp"
#include <iostream>

MainMenu::MainMenu(std::shared_ptr<Engine::Context> &context): m_context(context), m_isPlayButtonSelected(true),
m_isPlayButtonPressed(false), m_isExitButtonSelected(false), m_isExitButtonPressed(false){
    
}

MainMenu::~MainMenu(){
    
}

void MainMenu::Init(){
    m_context->m_assest->AddFont(MAIN_FONT, "/Users/alexisrodriguez/code/sfml_projects/shmup_sfml/shmup_sfml/shmup_sfml/Assets/Fonts/arial.ttf");
    m_gameTitle.setFont(m_context->m_assest->getFont(MAIN_FONT));
    m_playButton.setFont(m_context->m_assest->getFont(MAIN_FONT));
    m_exitButton.setFont(m_context->m_assest->getFont(MAIN_FONT));
    //name
    m_gameTitle.setString("Shoot 'em UP!");
    m_gameTitle.setCharacterSize(80);
    m_gameTitle.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_gameTitle.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_gameTitle.getGlobalBounds().height / 2.0 - 150.0));
    //play button
    m_playButton.setString("Play");
    m_playButton.setCharacterSize(50);
    m_playButton.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_playButton.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_playButton.getGlobalBounds().height / 2.0 - 30.0));
    //exit button
    m_exitButton.setString("Exit");
    m_exitButton.setCharacterSize(50);
    m_exitButton.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_exitButton.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_exitButton.getGlobalBounds().height / 2.0 + 30.0));
}
void MainMenu::ProcessInput(){
    sf::Event ev;
    while(m_context->m_window->pollEvent(ev)){
        if(ev.type == sf::Event::Closed){
            m_context->m_window->close();
        }else if(ev.type == sf::Event::KeyPressed){
            switch (ev.key.code) {
                case sf::Keyboard::Up:{
                    if(!m_isPlayButtonSelected){
                        m_isPlayButtonSelected = true;
                        m_isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:{
                    if(!m_isExitButtonSelected){
                        m_isPlayButtonSelected = false;
                        m_isExitButtonSelected = true;
                    }
                    break;
                }
                case sf::Keyboard::Escape:{
                    m_context->m_window->close();
                    break;
                }
                case sf::Keyboard::Return:{
                    m_isExitButtonPressed = false;
                    m_isPlayButtonPressed = false;
                    
                    if(m_isPlayButtonSelected){
                        m_isPlayButtonPressed = true;
                    }else{
                        m_isExitButtonPressed = true;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}
void MainMenu::Update(sf::Time deltatime){
    if(m_isPlayButtonSelected){
        m_playButton.setFillColor(sf::Color::Yellow);
        m_exitButton.setFillColor(sf::Color::White);
    }else{
        m_exitButton.setFillColor(sf::Color::Yellow);
        m_playButton.setFillColor(sf::Color::White);
    }if(m_isPlayButtonPressed){
        m_context->m_states->add(std::make_unique<GamePlay>(m_context), true);
    }else if(m_isExitButtonPressed){
       m_context->m_window->close();
    }
}
void MainMenu::Draw(){
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}
