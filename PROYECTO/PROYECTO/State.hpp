
#ifndef State_h
#define State_h

namespace DevJAD
{
    
    class State
    {
    public:
        virtual void Init() = 0;
        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0; // fix
        virtual void Draw(float dt) = 0;
        virtual void Pause(){};
        virtual void Resume(){};
    };
    
}

#endif /* State_h */
