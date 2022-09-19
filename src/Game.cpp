//
//  Game.cpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#include "Game.hpp"
#include "MainMenu.hpp"
Game::Game(): m_context(std::make_shared<Engine::Context>()){
    m_context->m_window->create(sf::VideoMode(1920, 1080), "Shoot em Up - SFML");
    //to do:
    m_context->m_states->add(std::make_unique<MainMenu>(m_context));
}
Game::~Game(){
    
}
void Game::run(){
    
    //sf::Clock clock;
    //sf::Time timeSinceLastFrame = sf::Time::Zero;
    
    while(m_context->m_window->isOpen()){
        //timeSinceLastFrame += clock.restart();
       // while(timeSinceLastFrame > timePerFrame){
         //   timeSinceLastFrame -= timePerFrame;

            m_context->m_states->processStateChange();
            m_context->m_states->getCurrentState()->ProcessInput();
            m_context->m_states->getCurrentState()->Update(timePerFrame);
            m_context->m_states->getCurrentState()->Draw();
                    
            
        //}
    }
    
}
