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

int main(){
    BackgroundTask b;
    // it will copy or move b.
    thread t(b);
    t.join();
}