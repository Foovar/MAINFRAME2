
#include "BranchesController.hpp"

namespace DevJAD {
    BranchesController::BranchesController(GameDataRef _data): data(_data){
        
    }
    
    void BranchesController::SpawnBranches(){
        sf::Sprite branch(this->data->assets.GetTexture("branch"));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            branch.setScale(0.3, 0.3);
        
        branch.setPosition(this->branches.size() * branch.getGlobalBounds().width / 1.5, this->data->window.getSize().y - branch.getGlobalBounds().height/1.2);
        this->branches.push_back(branch);
    }
    
    void BranchesController::Draw(){
        for(unsigned int i = 0; i < this->branches.size(); i++){
            this->data->window.draw(this->branches.at(i));
        }
    }
    
    void BranchesController::Update(float dt){
        
    }
    
    void BranchesController::SetPosition(int i, sf::Vector2f p){
        this->branches.at(i).setPosition(p);
    }
    
    sf::Vector2f BranchesController::GetPosition(int i){
        return this->branches.at(i).getPosition();
    }
}
