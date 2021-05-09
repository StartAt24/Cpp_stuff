#include <iostream>
#include <memory>
#include <fstream>

using namespace std;
enum class State{
    a,
    b,
    c,
};

class StateMachine{
public:
    State currentState() {
        return state_->getState();
    }
    BaseState* state_;
};

class BaseState{
public:
    virtual State getState() = 0;
    virtual void A_thing();
    virtual void B_thing();
    virtual void C_thing();
};

class State_A: public BaseState{
public:
    State_A(shared_ptr<StateMachine> s_m){
        s_m_ = s_m;
    }
    State getState(){
        return State::a;
    }

    void A_thing(){
    }
    void B_thing(){
        s_m_->state_ = new State_B(s_m_);
    }
    void C_thing(){
    }

private:
    shared_ptr<StateMachine> s_m_;
};

class State_B: public BaseState{
public:
    State_B(shared_ptr<StateMachine> s_m){
        s_m_ = s_m;
    }
    State getState(){
        return State::b;
    }

    void A_thing(){
    }
    void B_thing(){
    }
    void C_thing(){
    }

private:
    shared_ptr<StateMachine> s_m_;
};