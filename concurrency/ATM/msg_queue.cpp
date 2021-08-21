#include <mutex>
#include <iostream>
#include <condition_variable>
#include <queue>
#include <memory>
using namespace std;
namespace messaging{
    struct message_base{
        virtual ~message_base(){}
    };

    template<typename Msg>
    struct wrapped_message : private message_base{//每个消息都要特例化
        Msg contents;
        explicit wrapped_message(Msg const& contents_):
            contents(contents_){}
    };


class queue{
    std::mutex m;
    std::condition_variable c;
    std::queue<std::shared_ptr<message_base>> q; // pointer to base class
public:
    template<typename T>
    void push(T const& msg){
        std::lock_guard<std::mutex> lk(m);
        q.push(std::make_shared<wrapped_message<T>>(msg)); //包装已传递的信息，存储指针
        c.notify_all();
    }
    std::shared_ptr<message_base> wait_and_pop(){
        std::unique_lock<std::mutex> lk(m);
        c.wait(lk, [&]{return !q.empty();});
        auto res = q.front();
        q.pop();
        return res;
    }
};

// class receiver;
class sender{
    queue* q;
    public:
    sender():q(nullptr){}
    explicit sender(queue *q_):q(q_){}
    template<typename Message>
    void send(Message const&msg){
        if(!q)
            return;
        q->push(msg);
    }
};

class receiver{
    queue q; // 接受者拥有对应的队列
    public:
    operator sender()//允许将队列隐式转换为一个sender队列
    {
        cout << "call convert..." << endl;
        return sender(&q);
    }
    // dispatcher wait(){
    //     return dispatcher(&q);
    // }
};
}

int main(){
    messaging::receiver r;
    messaging::sender s  = messaging::sender(r);
    return 0;
}