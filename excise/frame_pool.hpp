// target:
// 1. fix size
// 2. sync and async api
// 3. buffer retrive.
#include <chrono>
#include <list>
#include <memory>
#include <atomic>
#include <mutex>
#include <thread>

using namespace std;
class Frame{
private:

public:

};

class FramePool{
private:
    int capacity_;
    atomic<int> in_use_{0};
    list<Frame> container_;
    std::mutex  lock_;

public:
    FramePool(int cap):capacity_(cap){
        container_.resize(capacity_);
        for(auto i=0; i<capacity_; i++)
            container_.push_back(Frame{});
    };

    shared_ptr<Frame> get_sync(){
       while(in_use_>=capacity_) {
            lock_.lock();
            this_thread::sleep_for(chrono::milliseconds(2));
       }
       in_use_++;
       return 
    }

    shared_ptr<Frame> get_async(){
        if(in_use_>=capacity_)
            return {};
        
        return 
    }

    void release(shared_ptr<Frame>& frame){
        frame.reset();
    }

};