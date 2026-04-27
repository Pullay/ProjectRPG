#ifndef STATE_H_
#define STATE_H_

class State
{
    public:
        virtual ~State() {}
        virtual void update(float deltaTime) = 0;
        virtual void render() = 0;
};
#endif