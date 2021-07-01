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

void RefParam(int a, int& b){

}

class Test{
    public:
    void say(){
        cout << "hello" <<endl;
    }
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
    cout << "++++++\n";
    int a=0,c=0;
    thread t2(RefParam, a, std::ref(c));
    t2.join();
    Test tt;
    thread t3(&Test::say, &tt);
    t3.join();
}