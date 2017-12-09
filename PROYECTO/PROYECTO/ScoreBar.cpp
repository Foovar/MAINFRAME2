
#include "ScoreBar.hpp"

namespace DevJAD {
    ScoreBar::ScoreBar(GameDataRef _data): data(_data){
        this->text.setFont(this->data->assets.GetFont("display"));
        this->text.setStyle(sf::Text::Style::Bold);
        
        this->text.setFillColor(sf::Color(96, 44, 3));
        this->score = 0;
        this->life = 0;
        this->time = 0;
        
        sf::Texture * scoreTexture = new sf::Texture(this->data->assets.GetTexture("scorebar"));
        scoreTexture->setSmooth(true);
        
        this->scoreSprite.setTexture(*scoreTexture);
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->scoreSprite.setScale(0.2, 0.2);
            this->text.setCharacterSize(25);
        }else{
            this->scoreSprite.setScale(0.4, 0.4);
            this->text.setCharacterSize(50);
        }
        this->scoreSprite.setTextureRect(sf::IntRect(430, 0, 460, 200));
    }
    
    void ScoreBar::Draw(){
        this->scoreSprite.setPosition(this->data->window.getView().getCenter().x - (this->scoreSprite.getGlobalBounds().width / 2), 0);
        this->data->window.draw(this->scoreSprite);
        
        this->text.setString(std::to_string(this->score));
        this->text.setPosition(this->data->window.getView().getCenter().x - 6, 4);
        this->data->window.draw(this->text);
    }
    
    void ScoreBar::AddScore(int score){
        this->score += score;
    }
    
    void ScoreBar::SetScore(int score){
        this->score = score;
    }
    
    int ScoreBar::GetScore(){
        return this->score;
    }
}
