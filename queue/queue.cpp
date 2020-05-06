#include <iostream>
using namespace std;

class ArrayQueue{
public:
    ArrayQueue(int _cap){
        if(_cap <= 0)
            abort();
        _bag = new int[_cap];

    }

private:
    int _cap;
    int _current;
    int *_bag;
};

class ListQueue{
struct Node{
    Node* before;
    int val;
    Node* next;
};


};

int main(int argc, char** argv){
    return 0;
}