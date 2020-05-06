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
            delete _bag;
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

public:
    int _ability;
    int _size;
    int *_bag;
};

int main(int argc, char** argv){
    ArrayStack s(10);

    for(auto i=0; i<10; i++){
        cout<< i << ":" <<s.push(i) << endl;
    }

    for(auto i=0; i<10; i++){
        int content;
        int v = s.pop(content);
        cout << v <<":" << content << endl;
    }
    return 0;
}