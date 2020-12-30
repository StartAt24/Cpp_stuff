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
    list()=default;

    ~list(){
        if(!head_)
            return;
        auto temp = head_;
        auto next = temp->next;
        while(temp){
            cout << "delete once" <<endl;
            delete temp;
            temp = next;
            if(next) 
                next = temp->next;
        }
    }

    size_t size(){
        return size_;
    }

    void append(int v){
        node* new_node = new node(v);
        size_+=1;
        if(!head_){
            head_ = new_node;
            current_ = head_; 
            return;
        }
        current_->next = new_node;
        current_ = current_->next;
    }

    void pop(){
        if(!head_)
            return;

        if(head_ && !head_->next){
            delete head_;
            head_ = nullptr;
            current_ = nullptr;
            size_ -=1;
            return;
        }

        auto temp = head_;
        while(temp->next){
            if(temp->next == current_){
                delete current_;
                current_ = temp;
                current_->next = nullptr;
                size_ -=1;
                return;
            }
            temp = temp->next;
        }
    }

    void print(){
        auto temp = head_;
        while(temp){
            cout << temp->v << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

private:
    size_t   size_{0};
    node* head_{nullptr};
    node* current_{nullptr};
};

int main(){
    list l;
    for(auto i=0;i<3;i++){
        l.append(i);
    }
    l.print();
    cout << l.size() << endl;
    l.pop();
    l.print();
    cout << l.size() << endl;
}