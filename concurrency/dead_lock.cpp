#include <iostream>
#include <mutex>

void swap(float &lhs, float& rhs){
    std::swap(lhs, rhs);
};

class X{
    private:
    float _big_obj;
    std::mutex m;
    public:
    X(const float& big_obj):_big_obj(big_obj){

    }
    friend void swap(X&lhs, X&rhs){
        if(&lhs == &rhs)
            return;
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs._big_obj, rhs._big_obj);
    }
};

int main(){
    X x1(3);
    X x2(4);
    swap(x1, x2);
}