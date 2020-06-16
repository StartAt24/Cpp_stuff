#include <iostream>

// 以 1/2 为超链接的 skiplist
class SkipList{

struct Node{
    Node* next;
    int   v;
};

public:
    SkipList(int n):_head(nullptr){
        _layers = n/2;
    }

    Node* head(){
        return _head;
    }

private:
    Node* _head;
    // skipList 超链接的层数
    int   _layers;
};
