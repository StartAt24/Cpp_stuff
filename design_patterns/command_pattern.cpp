#include <iostream>
using namespace std;

class Receiver{
public:
    void act(){
        cout << "receiver act" << endl;
    }
};

class Command{
public:
    Command(){
    }
    virtual ~Command(){

    }

    virtual void excute() = 0;

private:
    Receiver* recv_;
};

class Invoker{
public:
    Invoker(Command* cmd){
        cmd_ = cmd;
    }
    virtual ~Invoker(){}
    void call(){
        cmd_->excute();
    }
private:
    Command* cmd_;
};

class ConcreteCommand :public Command{
public:
    ConcreteCommand(Receiver* recv):receiver_(recv){
    }
    void excute() override{
        receiver_->act();
    }
private:
    Receiver* receiver_;
};

int main(){
    Receiver* recv = new Receiver();
    Command * cmd = new ConcreteCommand(recv);
    Invoker* inv = new Invoker(cmd);
    inv->call();
    return 0;
}