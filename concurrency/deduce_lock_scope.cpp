#include <iostream>
#include <mutex>
using namespace std;

class Y
{
private:
    int some_detail;
    mutable std::mutex m;
    int get_detail()const{
        std::lock_guard<std::mutex> _(m);
        return some_detail;
    }
public:
    Y(int sd):some_detail(sd){}
    friend bool operator==(Y const& lhs, Y const& rhs){
        // only when they are the same obj this stutation return ture;
        // same obj means the have the same memory address;
        if(&lhs == &rhs)
            return true;
        int const lhs_value = lhs.get_detail();
        int const rhs_value = rhs.get_detail();
        return lhs_value == rhs_value;
    }
};