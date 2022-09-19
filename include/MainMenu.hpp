//
//  MainMenu.hpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp
#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "State.hpp"
#include "Game.hpp"

class MainMenu : public Engine::State{
    private:
        std::shared_ptr<Engine::Context> m_context;
        sf::Text m_gameTitle;
        sf::Text m_playButton;
        sf::Text m_exitButton;
        bool m_isPlayButtonSelected;
        bool m_isPlayButtonPressed;
    
        bool m_isExitButtonSelected;
        bool m_isExitButtonPressed;
    public:
    MainMenu(std::shared_ptr<Engine::Context> &m_context);
        ~MainMenu();
    
        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltatime) override;
        void Draw() override;
    
    
};


#endif /* MainMenu_hpp */
