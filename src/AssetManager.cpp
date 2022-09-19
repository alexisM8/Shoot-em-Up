//
//  AssetManager.cpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#include "AssetManager.hpp"

Engine::AssetManager::AssetManager(){
    
}
Engine::AssetManager::~AssetManager(){
    
}
void Engine::AssetManager::AddTexture(int id, const std::string &filePath, bool wantRepeated){
    auto texture = std::make_unique<sf::Texture>();
    if(texture->loadFromFile(filePath)){
        texture->setRepeated(wantRepeated);
        m_Textures[id] = std::move(texture);
    }
}
void Engine::AssetManager::AddFont(int id, const std::string &filePath){
    auto font = std::make_unique<sf::Font>();
    if(font->loadFromFile(filePath)){
        m_Fonts[id] = std::move(font);
    }
}
const sf::Texture& Engine::AssetManager::getTexture(int id) const{
    return *(m_Textures.at(id).get());
}
const sf::Font& Engine::AssetManager::getFont(int id) const{
    return *(m_Fonts.at(id).get());
}
