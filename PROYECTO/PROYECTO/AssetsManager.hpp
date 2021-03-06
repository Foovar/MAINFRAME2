

#ifndef AssetsManager_hpp
#define AssetsManager_hpp

#include <stdio.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace DevJAD {
    
    class AssetsManager{
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
        std::map<std::string, sf::SoundBuffer> soundsBuffer;
        
    public:
        AssetsManager(){}
        ~AssetsManager(){}
        
        void LoadTexture(std::string name, std::string filename);
        sf::Texture &GetTexture(std::string name);
        
        void LoadFont(std::string name, std::string filename);
        sf::Font &GetFont(std::string name);
        
        void LoadSoundBuffer(std::string name, std::string filename);
        sf::SoundBuffer &GetSoundBuffer(std::string name);
    };
    
}


#endif /* AssetsManager_hpp */
