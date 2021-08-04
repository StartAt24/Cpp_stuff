#include <future>

void process_connection(connection_set& connections){
    while(!done(connections)){
        for(connection_iter connection=connections.begin(), end=connections.end(); connection != end; ++connection){
            if(connection->has_incomming_data()){
                data_packet data = connection->incomming();
                std::promise<payload_type>& p=connection->get_promise(data.id);
                p.set_value(data.payload);
            }
            if(connection->has_outgoing_data()){
                outgoing_packet data= connection->top_of_outgoing_queue();
                connection->send(data.payload);
                data.promise.set_value(true);
            }
        }
    }
}