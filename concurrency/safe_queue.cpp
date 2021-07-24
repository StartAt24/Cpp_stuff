#pragma once
#include <queue>

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

