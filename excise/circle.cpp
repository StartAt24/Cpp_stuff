#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

// 单向链表
class list{
struct node{
    node(int a):v(a){};
    node* next   = nullptr;
    node* before = nullptr;
    int v;
};

public:
    list()=default;

    ~list(){
        if(!head_)
            return;
        auto temp = head_;
        while(temp&&temp->next){
            delete temp;
            temp = temp->next;
        }
        head_ = nullptr;
        current_ = nullptr;
    }

    size_t size(){
        return size_;
    }

    node* find(int v){
        auto temp = head_;
        while(temp){
            if(temp->v == v)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void erase(node* node){
        auto temp = head_;
        while(temp){
            if(temp == node){
                if(temp->before)
                    temp->before->next = temp->next;
                else
                    head_ = temp->next;

                delete temp;
                --size_;
            }
            temp = temp->next;
        }
    }

    void append_front(int v){
        node* new_node = new node(v);
        ++size_;
        if(!head_){
            head_ = new_node;
            current_ = head_;
            return;
        }
        head_->before = new_node; 
        new_node->next = head_;
        head_ = new_node;
        return;
    }

    void append_back(int v){
        node* new_node = new node(v);
        ++size_;
        if(!head_){
            head_ = new_node;
            current_ = head_; 
            return;
        }
        current_->next = new_node;
        new_node->before = current_;
        current_ = new_node;
        return;
    }

    void pop_front(){
        if(!head_)
            return;
        --size_;
        if(head_ && !head_->next){
            delete head_;
            head_ = nullptr;
            current_ = nullptr;
            return;
        }
        auto temp = head_;
        temp->next->before = nullptr;
        head_ = temp->next;
        delete temp;
    }

    void pop_back(){
        if(!head_)
            return;
        --size_;
        auto temp = head_;
        // 这样的方式获取到的就是最后一个
        while(temp && temp->next){
            temp = temp->next;
        }
        if(temp == head_){
            delete head_;
            head_ = nullptr;
            current_ = nullptr;
            return;
        }
        current_ = temp->before;
        temp->before->next = nullptr;
        delete temp;
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
    l.append_back(3);
    l.append_front(4);
    l.append_front(2);
    l.print();
}