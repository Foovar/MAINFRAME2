

#include "TestState.hpp"

namespace DevJAD {
    
    TestState::TestState(GameDataRef data){
        this->data = data;
    }
    
    void TestState::Init(){
        
    }
    
    void TestState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void TestState::Update(float dt){
        
    }
    
    void TestState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        
        this->data->window.display();
    }
    
}
