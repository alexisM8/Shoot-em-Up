//
//  Game.hpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "AssetManager.hpp"
#include "StateManager.hpp"

struct Enemy{
    sf::Sprite enemy;
    bool isSeen;
    
    void move(sf::Vector2f dir){
        this->enemy.move(dir);
    }
};

enum AssetID{
    MAIN_FONT = 0,
    PLAYER,
    MISSILE,
    ENEMY
};

namespace  Engine{
    struct Context{
        std::unique_ptr<Engine::AssetManager> m_assest;
        std::unique_ptr<Engine::StateManager> m_states;
        std::unique_ptr<sf::RenderWindow> m_window;
        
        Context(){
            m_assest = std::make_unique<Engine::AssetManager>();
            m_states = std::make_unique<Engine::StateManager>();
            m_window = std::make_unique<sf::RenderWindow>();
        }
    };
}

class Game{
    private:
        std::shared_ptr<Engine::Context> m_context;
        const sf::Time timePerFrame = sf::seconds(1/500.0f);
        
    public:
        Game();
        ~Game();
        void run();

};


#endif /* Game_hpp */
