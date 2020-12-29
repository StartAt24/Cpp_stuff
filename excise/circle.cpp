#include <iostream>
#include <stdlib.h>
#include <assert.h>
// #include <list>

using namespace std;

// 单向链表
class list{

struct node{
    node(int a):v(a){};
    node* next;
    int v;
};

public:
    list(size_t size):head_(nullptr){
        assert(size>=0);
        for(auto i=0;i<size;i++) {
            node* new_node = new node(0);
        }
    };

    ~list(){
        while(head_->next){

        }
    }

private:
    node* head_;
};

int main(){



}