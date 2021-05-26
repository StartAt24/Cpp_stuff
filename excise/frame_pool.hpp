// target:
// 1. fix size
// 2. sync and async api
// 3. buffer retrive.
#include <list>
class Frame{
private:

public:

};

class FramePool{
private:
    int capacity_;
    std::list<Frame> container_;

public:
    FramePool(int cap):capacity_(cap){

    };


};