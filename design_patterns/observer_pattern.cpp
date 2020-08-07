#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Observer{
public:
    typedef shared_ptr<Observer> ptr;

    Observer(){};
    virtual ~Observer(){};
    virtual void update(const string& msg){};
};

class EventManager{
public:
    EventManager(){};
    ~EventManager(){};

    void addObserver(shared_ptr<Observer> obser){
       _buddies.push_back(obser);
    };

    void notify(const string& msg){
        for(const auto& i: _buddies){
            i->update(msg);
        }
    };

private:
    vector<shared_ptr<Observer>> _buddies;
};

class Person :public Observer{
public:
    Person(const string& name){
        _name = name;
    };
    ~Person(){

    };
    void update(const string& msg) override{
        cout << _name << " received: " << msg << endl;
        return;
    };
private:
    string _name;
};

int main(){
    Observer::ptr Observer1 = make_shared<Person>("dai");
    Observer::ptr Observer2 = make_shared<Person>("jj");
    EventManager manager;
    manager.addObserver(Observer1);
    manager.addObserver(Observer2);
    manager.notify("hello");
    return 0;
}