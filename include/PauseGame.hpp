//
//  PauseGame.hpp
//  shmup_sfml
//
//  Created by Alexis Rodriguez on 6/15/22.
//

#ifndef PauseGame_hpp
#define PauseGame_hpp

#include <SFML/Graphics/Text.hpp>
#include <memory>
#include "State.hpp"
#include "Game.hpp"

class PauseGame : public Engine::State{
    private:
        std::shared_ptr<Engine::Context> m_context;
        sf::Text m_pausedTitle;
        sf::Text m_resumeButton;
        sf::Text m_exitButton;
        bool m_isResumeButtonSelected;
        bool m_isResumeButtonPressed;
    
        bool m_isExitButtonSelected;
        bool m_isExitButtonPressed;
    public:
        PauseGame(std::shared_ptr<Engine::Context> &m_context);
        ~PauseGame();
    
        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltatime) override;
        void Draw() override;
    
    
};


#endif /* PauseGame_hpp */
