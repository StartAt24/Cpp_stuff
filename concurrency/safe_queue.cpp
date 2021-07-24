#pragma once
#include <queue>
//  Queue 的接口
template <class T, class Container=std::dequeue<T>>
class queue{
    public:
    using size_type = Container::Size;
    // 从一个container构造出来
    explict queue(const Container&);
    explict queue(Container&& = Container());
    template <class Alloc> explict queue(const Alloc&);
    template <class Alloc> queue(const Container&, const Alloc&);
    template <class Alloc> queue(Container&&, const Alloc&);
    template <class Alloc> queue(queue&&, const Alloc&);
    
    void swap(queue& q);
    bool empty() const;
    size_type size() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push(const T& x);
    void push(T&& x);
    void pop();
    template <class... Args> void emplace(Args&&... args);
};

#include <memory>

template<typename T>
class ThreadSafeQueue
{
    public:
    ThreadSafeQueue();
    ThreadSafeQueue(const ThreadSafeQueue&);
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) =delete;
    void push(T new_value);
    bool try_pop(T& value);
    std::shared_ptr<T> try_pop();
    void wait_and_pop(T& value);
    std::shared_ptr<T> wait_and_pop();

    bool empty() const;
};

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue{
    private:
    std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
    public:
    void push(T new_value){
        std::lock_guard<std::mutex> _(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    void wait_and_pop(T& value){
        std::unique_lock<std::mutex> _(mut);
        data_cond.wait(_, [this]{return !data_queue.empty();});
        value = data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop(){
        std::unique_lock<std::mutex> _(mut);
        data_cond.wait(_, [this]{return !data_queue.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool try_pop(T& value){
        std::lock_guard<std::mutex> _(mut);
        if(data_queue.empty())
            return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    std::shared_ptr<T> try_pop(){
        std::lock_guard<std::mutex> _(mut);
        if(data_queue.empty())
            return nullptr;
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front());
        data_queue.pop();
        return res;
    }
    bool empty() const{
        std::lock_guard<std::mutex> _(mut);
        return data_queue.empty();
    }
};
