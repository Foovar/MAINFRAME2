//
//  AssetsManager.cpp
//  PROYECTO
//
//  Created by DevJAD on 2/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

#include "AssetsManager.hpp"

namespace DevJAD {
    
    void AssetsManager::LoadTexture(std::string name, std::string filename){
        sf::Texture texture;
        if(texture.loadFromFile(filename)){
            this->textures[name] = texture;
        }
    }
    
    sf::Texture &AssetsManager::GetTexture(std::string name){
        return this->textures.at(name);
    }
    
    void AssetsManager::LoadFont(std::string name, std::string filename){
        sf::Font font;
        if(font.loadFromFile(filename)){
            this->fonts[name] = font;
        }
    }
    
    sf::Font &AssetsManager::GetFont(std::string name){
        return this->fonts.at(name);
    }
    
    void AssetsManager::LoadSoundBuffer(std::string name, std::string filename){
        sf::SoundBuffer buffer;
        if(buffer.loadFromFile(filename)){
            this->soundsBuffer[name] = buffer;
        }
    }
    
    sf::SoundBuffer &AssetsManager::GetSoundBuffer(std::string name){
        return this->soundsBuffer.at(name);
    }
    
}
