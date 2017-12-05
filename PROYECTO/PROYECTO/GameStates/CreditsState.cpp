

#include "CreditsState.hpp"
#include "iostream"

namespace DevJAD {
    
    CreditsState::CreditsState(GameDataRef data){
        this->data = data;
    }
    
    void CreditsState::Init(){
        this->text.setFont(this->data->assets.GetFont("credits"));
        this->team.setFont(this->data->assets.GetFont("credits"));
        this->title1.setFont(this->data->assets.GetFont("credits"));
        this->title2.setFont(this->data->assets.GetFont("credits"));
        this->logo.setTexture(this->data->assets.GetTexture("splash_logo"));
        
        this->text.setFillColor(sf::Color(215,25,65));
        this->text.setString("UNIVERSIDAD PRIVADA ANTENOR ORREGO");
        this->text.setPosition(this->data->window.getView().getCenter().x - this->text.getGlobalBounds().width / 2, 30);
        
        this->title1.setFillColor(sf::Color(255,126,0));
        this->title1.setString("DEVELOPER TEAM\n\n\n\n\nDOCENTE\n\n\nCURSO");
        this->title1.setPosition(this->data->window.getView().getCenter().x - this->title1.getGlobalBounds().width / 2, 80);
        
        this->team.setFillColor(sf::Color(44, 44, 44));
        this->team.setString(" - Layza Quiroz Diego\n - Paredes Enriquez Alex\n - Requejo Velasquez Jordan\n\n\n \t- Walter Cueva\n\n\n \t-Mainframe 2");
        this->team.setPosition(this->data->window.getView().getCenter().x - this->team.getGlobalBounds().width/2, 130);
        
        this->logo.setOrigin(this->logo.getLocalBounds().width / 2, this->logo.getLocalBounds().height / 2);
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->logo.setScale(0.5, 0.5);
            this->logo.setPosition(this->data->window.getView().getCenter().x + this->logo.getGlobalBounds().width,this->data->window.getSize().y - this->logo.getLocalBounds().height/2);
            this->logo.setRotation(-45);
        }
        
        
        this->musicBackground.openFromFile(CREDITS_MUSIC_BACKGROUND);
        this->musicBackground.setLoop(true);
        this->musicBackground.play();
    }
    
    void CreditsState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                this->musicBackground.setLoop(false);
                this->musicBackground.stop();
                this->data->machine.AddState(StateRef(new MainMenuState(this->data)), true);
            }
        }
    }
    
    void CreditsState::Update(float dt){
        this->logo.rotate(dt * 20);
    }
    
    void CreditsState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->data->window.draw(this->logo);
        this->data->window.draw(this->text);
        this->data->window.draw(this->title1);
        this->data->window.draw(this->team);
        this->data->window.display();
    }
    
}
