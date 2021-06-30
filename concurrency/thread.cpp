#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
class BackgroundTask{
    public:
    void operator()() const{
        cout <<"Test" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Awake and Exit" << endl;
        return;
    };
    BackgroundTask(const BackgroundTask& other){
        cout << "Copy constructor;\n";
    }
    BackgroundTask(){
        cout << "Constructor\n";
    }
};

class ThreadGuard{
    public:
    explicit ThreadGuard(thread& other):_thread(other){
    }
    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
    ~ThreadGuard(){
        if(_thread.joinable())
            _thread.join();
    }
    private:
    thread& _thread;
};

int main(){
    BackgroundTask b;
    // it will copy or move b.
        cout << "11111\n";
    thread t(b); // it will copy twice??
        cout << "22222\n";
    {
        cout << "---\n";
        ThreadGuard tt(t);
    }
    cout << "endl\n";
}