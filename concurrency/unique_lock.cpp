#include <iostream>
#include <mutex>

using namespace std;
class some_big_object{

};
void swap(some_big_object& lhs, some_big_object& rhs);

class X{
    private:
    some_big_object some_detail;
    std::mutex m;
    public:
    X(some_big_object const& sd):some_detail(sd){}
    friend void swap(X& lhs, X& rhs){
        if(lhs == rhs)
            return;
        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
        std::lock(lock_a, lock_b);
        swap(lhs.some_detail, rhs.some_detail);
    }
}

std::unique_lock<std::mutex> get_lock(){
    extern std::mutex some_mutex;
    std::unique_lock<std::mutex> lk(some_mutex);
    prepare_data();
    return lk;
}

void process_data(){
    std::unique_lock<std::mutex> lk(get_lock());
    do_something();
}