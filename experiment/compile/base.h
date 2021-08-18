#include <iostream>

class Base{
public:
    Base() = default;
    virtual ~Base(){};
    virtual void interface() = 0;
private:
    int a;
};