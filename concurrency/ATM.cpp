#include <string>
struct card_inserted
{
    std::string accound;
};

class atm{
    messaging::receiver incoming;
    messaging::sender bank;
    messaging::sender interface_hardware;
    void(atm::*state)();
    std::string account;
    std::string pin;

    void waiting_for_card(){
        interface_hardware.send(display_enter_card());
        incomming.wait().handle<card_inserted>(
            [&](card_inserted const& msg){
                accound=msg.account;
                pin="";
                interface_hardware.send(display_enter_pin());
                state=&atm::getting_pin;
            }
        );
    }
    void getting_pin();

    public:
    void run(){
        state = &atm::waiting_for_card;
        try{
            while(1){
                (this->*state)();
            }
        }
        catch(messaging::close_queue const&){}
    }
}