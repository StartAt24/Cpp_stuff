#include <iostream>
#include <mutex>

class Singleton
{
private:
    static Singleton *_instance;
    static std::mutex _ins_lock;

public:
    static Singleton *GetInstance()
    {
        if (_instance != nullptr) // @1
            return _instance;
        std::lock_guard<std::mutex> _(_ins_lock);
        if (_instance == nullptr)
            // 这里会产生竞态条件
            // 因为这其实是一个三步操作，
            // 1.申请内存
            // 2.初始化
            // 3.把指针赋值给_instance
            // 实际执行的时候编译器可能会将顺序变成132，这样其他线程就会在@1得到一个未完成初始化的对象，带来未定义的行为
            _instance = new Singleton();
        return _instance;
    }
};

// 使用标准库的call_once对上例进行改进
class SingletonOnce{
private:
    static std::once_flag _ins_flag;
    static SingletonOnce* _ins;
public:
    // 因为是static的，所以无法捕获this
    static SingletonOnce* GetInstance(){
        std::call_once(_ins_flag, [](){
            _ins = new SingletonOnce();
        });
        return _ins;
    }
};

int main(){
    return 0;
}