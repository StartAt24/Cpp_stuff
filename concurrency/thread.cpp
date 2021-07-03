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

void s1_func(){

}
void s2_func(){

}

int main(){
    #if 0
    BackgroundTask b;
    // it will copy or move b.
        cout << "11111\n";
    thread t(b); // it will copy twice??
        cout << "22222\n";
    {
        cout << "---\n";
        ThreadGuard tt(t);
    }
    int a=0,c=0;
    thread t2(RefParam, a, std::ref(c));
    t2.join();
    Test tt;
    thread t3(&Test::say, &tt);
    t3.join();

    thread tfc1(s1_func);
    thread tfc2(s2_func);
    tfc2 = std::move(tfc1);
    #endif

    thread t1([](){
        this_thread::sleep_for(2s);
        cout << " t1 ...after sleep 2s" << endl;
    });

    cout<<"before assign\n";
    t1 = thread([](){
        this_thread::sleep_for(3s);
        cout << " t1 ...after sleep 2s" << endl;
    });
    cout<<"after assign\n";

    t1.join();
}