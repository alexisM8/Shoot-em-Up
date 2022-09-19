//
//  leveltwo.hpp
//  shmup_sfml
//
//  Created by Alexis Rodriguez on 6/21/22.
//

#ifndef leveltwo_hpp
#define leveltwo_hpp

#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <memory>
#include <array>
#include <stdio.h>
#include <list>

class LevelTwo : public Engine::State {
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
    LevelTwo(std::shared_ptr<Engine::Context> &context, int score);
    ~LevelTwo();
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltatime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
    
};

#endif /* leveltwo_hpp */
