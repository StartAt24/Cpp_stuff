#include <iostream>
using namespace std;

class ArrayQueue{
public:
    ArrayQueue(int cap):_cap(cap),_tail(0){
        if(_cap <= 0)
            abort();
        _bag = new int[_cap]{};
    }
    ~ArrayQueue(){
        delete[] _bag;
    }

    int push(int v){
        // 证明数组满了
        if(_tail>_cap-1)
            return -1;

        _bag[_tail] = v;
        _tail+=1;
        return 0;
    }

    int pop(int& v){
        if(_tail == 0)
            return -1;

        v = _bag[0];
        // 整体向前移动一下，这样每次 pop的时间复杂度是 O(n)
        for(auto i=0;i+1<_tail;i++){
            _bag[i] = _bag[i+1];
        }
        _tail--;
        return 0;
    }

    void print(){
        cout << "====" << endl;
        for(auto i=0;i<_cap; i++){
            cout << _bag[i] << endl;
        }
        cout << "====" << endl;
    }
private:
    int _cap;
    int _tail;
    int *_bag;
};

// 循环数组 作为数组，会浪费一个空间， 所以实际存储的个数是 _capacity -1
class CircleArrayQueue{
public:
    CircleArrayQueue(int c):_capacity(c),_head(0),_tail(0){
        _bag = new int[_capacity]{};
    }

    ~CircleArrayQueue(){
        delete [] _bag;
    }

    int enqueue(int i){
        // 队列已满
        if((_tail+1)%_capacity == _head)
            return -1;

        _bag[_tail] = i;
        _tail = (_tail+1)%_capacity;
        return 0;
    }
     
    int dequeue(int& i){
        // 队列为空
        if(_head == _tail)
            return -1;
        i = _bag[_head];

        _head = (_head+1)%_capacity;
        return 0;
    }

private:
    int _head;
    int _tail;
    int _capacity;
    int* _bag;
};



class ListQueue{
struct Node{
    Node* before;
    int val;
    Node* next;
};


};

int main(int argc, char** argv){
    CircleArrayQueue q(10);
    for(auto i=0;i<15; i++){
        q.enqueue(i);
    }


    for(auto i=0;i<12; i++){
        int c=-1;
        q.dequeue(c);
        cout << c << endl;
    }
    return 0;
}