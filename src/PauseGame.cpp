//
//  PauseGame.cpp
//  shmup_sfml
//
//  Created by Alexis Rodriguez on 6/15/22.
//

#include "PauseGame.hpp"
#include "GamePlay.hpp"
#include <iostream>

PauseGame::PauseGame(std::shared_ptr<Engine::Context> &context): m_context(context), m_isResumeButtonSelected(true),
m_isResumeButtonPressed(false), m_isExitButtonSelected(false), m_isExitButtonPressed(false){
    
}

PauseGame::~PauseGame(){
    
}

void PauseGame::Init(){

    m_pausedTitle.setFont(m_context->m_assest->getFont(MAIN_FONT));
    m_resumeButton.setFont(m_context->m_assest->getFont(MAIN_FONT));
    m_exitButton.setFont(m_context->m_assest->getFont(MAIN_FONT));
    //name
    m_pausedTitle.setString("Game Paused");
    m_pausedTitle.setCharacterSize(80);
    m_pausedTitle.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_pausedTitle.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_pausedTitle.getGlobalBounds().height / 2.0 - 150.0));
    //play button
    m_resumeButton.setString("Resume");
    m_resumeButton.setCharacterSize(50);
    m_resumeButton.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_resumeButton.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_resumeButton.getGlobalBounds().height / 2.0 - 30.0));
    //exit button
    m_exitButton.setString("Exit");
    m_exitButton.setCharacterSize(50);
    m_exitButton.setPosition(sf::Vector2f((m_context->m_window->getSize().x / 2.0) - m_exitButton.getGlobalBounds().width / 2.0, m_context->m_window->getSize().y / 2.0 - m_exitButton.getGlobalBounds().height / 2.0 + 30.0));
}
void PauseGame::ProcessInput(){
    sf::Event ev;
    while(m_context->m_window->pollEvent(ev)){
        if(ev.type == sf::Event::Closed){
            m_context->m_window->close();
        }else if(ev.type == sf::Event::KeyPressed){
            switch (ev.key.code) {
                case sf::Keyboard::Up:{
                    if(!m_isResumeButtonSelected){
                        m_isResumeButtonSelected = true;
                        m_isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:{
                    if(!m_isExitButtonSelected){
                        m_isResumeButtonSelected = false;
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
                    m_isResumeButtonPressed = false;
                    
                    if(m_isResumeButtonSelected){
                        m_isResumeButtonPressed = true;
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
void PauseGame::Update(sf::Time deltatime){
    if(m_isResumeButtonSelected){
        m_resumeButton.setFillColor(sf::Color::Yellow);
        m_exitButton.setFillColor(sf::Color::White);
    }else{
        m_exitButton.setFillColor(sf::Color::Yellow);
        m_resumeButton.setFillColor(sf::Color::White);
    }if(m_isResumeButtonPressed){
        m_context->m_states->popCurrent();
    }else if(m_isExitButtonPressed){
       m_context->m_window->close();
    }
}
void PauseGame::Draw(){
    sf::RectangleShape op({static_cast<float>(m_context->m_window->getSize().x), static_cast<float>(m_context->m_window->getSize().y)});
    op.setFillColor(sf::Color(173, 173, 173, 5));
    m_context->m_window->draw(op);
    m_context->m_window->draw(m_pausedTitle);
    m_context->m_window->draw(m_resumeButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}
