#include <iostream>
#include <functional>

using namespace std;

template<class T>
class ChainBase{
public:
    ChainBase* handle<T>(std::function<void(T)> f){
        f();
        return this;
    };
};

class HandleOne : public ChainBase<HandleOne>{
public:
    ChainBase* handle<HandleOne>(){

    }
}

class HandleTwo : public ChainBase<HandleTwo>{

}
