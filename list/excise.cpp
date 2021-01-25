#include <iostream>
using namespace std;

template<typename T>
class MList{
    // 单向链表
    struct Node{
        Node(T v){
            this->val = v;
        }
        T val;
        Node* next{nullptr};
    };
public:
    MList() = default;
    ~MList(){
        auto temp = head_;
        while(temp){
            auto temp_copy = temp;
            temp = temp->next;
            delete temp_copy; 
        }
        reset_pointer();
        size_ = 0;
    }

    // 反转
    void reverse(){
        // 没有或者只有一个元素 不需要反转
        if(!head_ || !head_->next)
            return;
        current_ = head_;

        // 反转其实需要三个指针
        Node* temp{nullptr}, *cur{nullptr}, *pre{nullptr};
        cur = head_->next;
        pre = head_;
        head_->next = nullptr;

        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head_ = pre;
    }

    void r_reverse_wrap(){
        head_ = r_reverse(head_);
    }

    Node* r_reverse(Node* node){
        if(!node || !node->next)
            return node;
        Node* ret_node = r_reverse(node->next);
        node->next->next = node;
        node->next = nullptr;
        return ret_node;
    }

    bool isCircle(){
        Node* slow=nullptr, *fast=nullptr;
        slow = head_;
        fast = head_;
        while(slow){
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }

    void push_back(const T& t){
        Node* temp = new Node(t);
        if(!head_){
            head_ = temp;
            current_ = head_;
            ++size_;
            return;
        }
        current_->next = temp;
        current_ = temp;
        ++size_;
    }
    
    T& front(){
        return head_->val;
    }

    T& back(){
        return current_->val;
    }

    bool empty(){
        return size_ == 0;
    }

    size_t size(){
        return size_;
    }

    void pop_front(){
        if(!head_)
            return;

        if(head_ && !head_->next){
            delete head_;
            reset_pointer();
            --size_;
            return;
        }

        auto temp = head_;
        head_ = head_->next;
        delete temp;
        --size_;
        return;
    }

    void pop_back(){
        if(!head_)
            return;

        if(head_ && !head_->next) {
            delete head_;
            reset_pointer();
            --size_;
            return;
        }

        auto temp = head_;
        while(temp->next->next){
            temp = temp->next;
        }
        current_ = temp;
        delete temp->next;
        temp->next = nullptr;
        --size_;
        return;
    }

    void print(){
        cout << "[++++]\n";
        auto temp = head_;
        while(temp){
            cout << temp->val <<" ";
            temp = temp->next;
        }
        cout << "\n";
    }

private:
    void reset_pointer(){
        head_=nullptr;
        current_=nullptr;
    }

private:
    Node* head_{nullptr};
    Node* current_{nullptr};
    size_t size_{0};
};



int main(){
    MList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.print();
    l.reverse();
    l.print();
    l.push_back(33);
    l.print();
    l.r_reverse_wrap();
    l.print();
    return 0;
}