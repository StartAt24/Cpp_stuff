#include <iostream>
using namespace std;

struct node{
    node* next;
    char  s;
};

// make a list which length is len
string makeList(int len, node** list){
    if(len <=0){
        *list =  nullptr;
        return string("Len <= 0");
    }

    node* head = new node{nullptr, ' '};
    node** next = &head->next;
    len--;

    while(len >0){
       *next = new node{nullptr, ' '};
       next = &((*next)->next);
       len--;
    }
    *list = head;
    return string("ok");
}

void cleanList(node** list){
    if(*list == nullptr)
        return;

    node** next = &(*list)->next;
    while(*next){
        node* temp =  (*next)->next;
        delete *next;
        *next = nullptr;
        next = &temp;
    }

    *list = nullptr;
}


int main(int argc, char** argv){
    node* list=nullptr;
    auto ret = makeList(3, &list);
}