#include <futrue>
#include <iostream>

int find_the_answer_to_ltuae();
void do_other_stuff();

struct Y{
    double operator()(double);
};

int main(){
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout<< "The answer is: "<< the_answer.get() << std::endl;
    auto f6 = std::async(std::launch::async, Y(), 12);//在新线程执行
    auto f7 = std::async(std::launch::deferred, Y(), 123);//在wait()时执行
    auto f8= std::async(std::launch::deferred | std::launch::async, Y(), 3); // 自行选择实现方式
}