#include <iostream>
#include <string>
using namespace std;

class Iterator{
public:
    virtual bool hasNext() = 0;
    virtual string current() = 0;
    virtual void next() = 0;
};

class Container{
public:
    virtual int count() = 0;
    virtual string pop() = 0;
    virtual string push() = 0;
    virtual string get(int) = 0;
    virtual Iterator* iter() = 0;
};

class ConcreteIterator: public Iterator{
public:
    ConcreteIterator(Container* container): container_(container){
    }
    bool hasNext(){
        return current_idx_ != container_->count();
    }
    void next(){
        current_idx_++;
    }
    string current(){
        return container_->get(current_idx_);
    }

private:
    int current_idx_=0;
    Container* container_=nullptr;
};

class ConcreteContainer : public Container{
public:
    ConcreteContainer(){

    }
    Iterator* iter(){
        if(!iter_){
            return new ConcreteIterator(this);
        }
        return iter_;
    }
private:
    Iterator* iter_;
};

int main(){

}