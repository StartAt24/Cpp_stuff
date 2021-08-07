#include <future>

class connection_set;
bool done(connection_set&);
void process_con(connection_set& connections){
    while(!done(connections)){
        for(connection_iter con = connections.begin(),
        end=connections.end(); con!=end; ++con){
            if(connection->has_incoming_data()){
                data_packet data = connection->incoming();
                std::promise<payload_type>& p =connection->get_promise(data.id);
                p.set_value(data.payload);
            }

            if(connection->has_outgoing_data()){
                outgoing_packet data=connection->top_of_outgoing_queue();
                connection->send(data.payload);
                data.promise.set_value(true);
            }
        }
    }
}

extern std::promise<double> some_promise;

try{
    some_promise.set_value(calculate_value());
}
catch(...){
    some_promise.set_exception(std::current_exception());
}