//
//  GamePlay.hpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 6/12/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#ifndef GamePlay_hpp
#define GamePlay_hpp
#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <memory>
#include <array>
#include <stdio.h>
#include <list>




class GamePlay : public Engine::State {
    private:
        std::shared_ptr<Engine::Context> m_context;
        //player
        sf::Sprite m_player;
        sf::Vector2f m_playerDir;
        float m_playerVelocity;

        //player missile
        sf::Sprite m_missile;
        bool m_seeMissile;
        float m_missileVelocity;
        sf::Vector2f m_missileDir;
    
        //enemy
        std::array<Enemy, 10> m_enemies;
        float m_enemyVelocity;
        sf::Vector2f m_enemyDir;
        
        
        sf::Text m_scoreTxt;
        int m_score;
        bool m_isPasued;
    
    public:
    GamePlay(std::shared_ptr<Engine::Context> &context);
    ~GamePlay();
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltatime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
    
};



#endif /* GamePlay_hpp */
