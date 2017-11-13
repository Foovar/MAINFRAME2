//
//  StateMachine.hpp
//  PROYECTO
//
//  Created by DevJAD on 1/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include <memory>
#include <stack>

#include "State.hpp"

namespace DevJAD {
    
    typedef std::unique_ptr<State> StateRef;
    
    class StateMachine {
        std::stack<StateRef> states;
        StateRef newState;
        
        bool isRemoving;
        bool isAdding;
        bool isReplacing;
        
    public:
        StateMachine(){}
        ~StateMachine(){}
        
        void AddState(StateRef _newState, bool isReplacing = true);
        void RemoveState();
        void ProcessStateChanges();
        
        StateRef &GetActiveState();
    };
}



#endif /* StateMachine_hpp */
