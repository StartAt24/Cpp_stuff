#include <iostream>
using namespace std;

class QQueue{
public:
    QQueue(size_t n):capacity_(n){
        head_ = new int[n];
        tail_ = head_;
        root_ = head_;
    }

    ~QQueue(){
        delete root_;
        root_ = nullptr;
    }

    // 有两种情况。第一种是 满了。第二种是没有满，但是需要转移位置了。
    int push_back(int n){
        // full
        if(size_ == capacity_)
            return -1;
        
        if(tail_== root_+n){
            // 拷贝。
            int* temp = root_;
            while(head_ != tail_){
                *temp = *head_;
                temp++;
                head_++;
            }
            head_ = root_;
            tail_ = root_+size_;
            *tail_ = n;
            ++size_; 
            return 0;
        }

        *tail_ = n;
        ++size_;
        ++tail_;
        return 0;
    }

    int pop_front(int* out){
        if(size_ == 0)
            return -1;
        *out = *head_;
        ++head_;
        --size_;
        return 0;
    }

    void print(){
        int* temp = head_;
        while(temp != tail_){
            cout << *temp  << " ";
            temp++;
        }
        cout << "\n";
    }

private:
    size_t size_{0};
    size_t capacity_{0};
    int*   head_{nullptr};
    int*   tail_{nullptr};
    int*   root_{nullptr};
};

class CircleQueue{
public:
    CircleQueue(size_t n):capacity_(n){
        container_ = new int[capacity_];
    }
    ~CircleQueue(){
        delete container_;
        container_ = nullptr;
    }

    // 入队列
    int enqueue(int n){
        if(full())
            return -1;
        container_[tail_] = n;
        tail_ = ++tail_%capacity_;
        return 0;
    }

    // 出队列
    int dequeue(){
        if(empty())
            return -1;
        head_ = ++head_%capacity_;
        return 0;
    }

    void print(){
        if(empty())
            return;
        int temp = head_;
        while(1){
            cout << container_[temp] << " ";
            temp = ++temp % capacity_;
            if(temp == tail_)
                break;
        }
        cout << endl;
    }

private:
    bool empty(){
        return head_==tail_;
    }
    bool full(){
        return ((tail_+1)%capacity_ == head_);
    }
    size_t capacity_=0;
    int    head_=0;
    int    tail_=0;
    int*   container_=nullptr;
};

int main(){
    QQueue l(3);
    // l.push_back(1);
    // l.push_back(2);
    // l.push_back(3);
    // int out;
    // l.pop_front(&out);
    // l.pop_front(&out);
    // l.push_back(4);
    // l.push_back(5);
    // l.print();
    CircleQueue s(4);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.dequeue();
    s.dequeue();
    s.dequeue();
    s.enqueue(4);
    s.enqueue(5);
    s.print();
}