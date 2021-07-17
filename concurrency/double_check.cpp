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
    int a;
public:
    // 因为是static的，所以无法捕获this, 如果是nostatic应该需要捕获this来访问成员
    static SingletonOnce* GetInstance(){
        std::call_once(_ins_flag, [](){
            _ins = new SingletonOnce();
        });
        return _ins;
    }
    void test_capture(){
        [this](){
            a = 3;
        }();
    }
};

// call_once 延迟调用
class ConnectionInfo{
};
class ConnectionHandle{
};
class ConnectionManager{
    public:
    ConnectionHandle open(ConnectionInfo);
};
class X{
private:
    ConnectionInfo _connection_info;
    ConnectionHandle _connection;
    ConnectionManager _conn_manager;
    std::once_flag _conn_init_flag;
    void open_connection(){
        _connection = _conn_manager.open(_connection_info);
    }
public:
    X(ConnectionInfo const& info):_connection_info(info){

    }

    void send(){
        std::call_once(_conn_init_flag, &X::open_connection, this);
        // do some send job here;
    }
    void receive(){
        std::call_once(_conn_init_flag, &X::open_connection, this);
        // do some receive job here;
    }
};
// 通过 静态变量来实现单例(c++11之后才行，11之前因为静态变量初始化存在竞态所以不行)
class MyClass{
public:
static MyClass& GetInstance(){
    static MyClass instance;
    return instance;
}
};

int main(){
    return 0;
}