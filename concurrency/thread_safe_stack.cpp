#include <memory>
#include <mutex>
#include <exception>
#include <stack>

struct empty_stack: std::exception{
    const char* what() const noexcept{
        return "empty stack!";
    };
};

template<typename T>
class threadsafe_stack{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack(): data(std::stack<T>()){}

    threadsafe_stack(const threadsafe_stack& other)
    {
        // 这是构造函数 所以不需要用自己的锁，因为自己尚未存在，所以是安全的
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack& ) = delete;

    void push(T new_val){
        std::lock_guard<std::mutex> lock(m);
        data.push(new_val);
    }

    std::shared_ptr<T> pop(){
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        // 修改栈之前分配出返回值的空间，防止分配不了出现异常 导致栈被破坏
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    void pop(T& val){
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();

        val = data.top();
        data.pop();
    }

    bool empty() const{
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};