//
//  AssetManager.hpp
//  SnakeV2
//
//  Created by Alexis Rodriguez on 2/18/22.
//  Copyright © 2022 Alexis Rodriguez. All rights reserved.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <map>
#include <string>

namespace Engine{
    class AssetManager{
        private:
            std::map<int, std::unique_ptr<sf::Texture>> m_Textures;
            std::map<int, std::unique_ptr<sf::Font>> m_Fonts;
        public:
            AssetManager();
            ~AssetManager();
            void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
            void AddFont(int id, const std::string &filePath);
            const sf::Texture& getTexture(int id) const;
            const sf::Font& getFont(int id) const;
    };
}

#endif /* AssetManager_hpp */
