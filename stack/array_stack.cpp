#include <iostream>
using namespace std;

class ArrayStack{
public:
    ArrayStack(int ability):_ability(ability), _size(0){
        // 初始化
        _bag = new int[_ability];
    };

    ~ArrayStack(){
        if(_bag!=nullptr)
        {
            delete []_bag;
            _bag = nullptr;
        }
    };

    int push(int a){
       if(_size > _ability-1) 
            return -1;
        
        _bag[_size] = a;
        _size+=1;
        return 0;
    };

    int pop(int& element){
        if(_size-1 < 0)
            return -1;

        element =  _bag[_size-1];
        _size -=1;
        return 0;
    }

private:
    int _ability;
    int _size;
    int *_bag;
};

// 与arrayStack不一样，先不限制大小
class listStack{
struct Node{
    int v;
    Node* next;
    Node* before;
    Node(int value):v(value){};
};

public:
    listStack():_current(nullptr),_head(nullptr){};
    ~listStack(){
        while(_current){
            auto temp = _current->before;
            delete(_current);
            _current = temp;
        }
    }

    int push(int value){
        if(_head == nullptr){
            _head = new Node(value);
            _head->before = nullptr;
            _current = _head;
            return 0;
        }

        Node * n = new Node(value);
        n->before = _current;
        _current->next = n;
        _current = n;

        return 0;
    }

    int pop(int& value){
        if(!_current){
            return -1;
        }

        value = _current->v;
        auto temp = _current->before;
        delete _current;
        _current = temp;
        return 0;
    }

private:
    Node* _current;
    Node* _head;
};

int main(int argc, char** argv){
    ArrayStack s(10);
    listStack  s2;

    for(auto i=0; i<10; i++){
        cout<< i << ":" <<s2.push(i) << endl;
    }

    for(auto i=0; i<17; i++){
        int content;
        int v = s2.pop(content);
        cout << v <<":" << content << endl;
    }
    return 0;
}