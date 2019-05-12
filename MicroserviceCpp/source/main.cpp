#include <iostream>

#include <usr_interrupt_handler.hpp>
#include <runtime_utils.hpp>

#include "microsvc_controller.hpp"

using namespace web;
using namespace cfx;

int main(int argc, const char * argv[]) {
    InterruptHandler::hookSIGINT();

    MicroserviceController server;
    server.setEndpoint("http://locahlost:6502/api");
    
    try {
        // wait for server initialization...
        server.accept().wait();
        std::cout << "C++ service now listening for requests at: " << server.endpoint() << '\n';
        
        InterruptHandler::waitForUserInterrupt();

        server.shutdown().wait();
    }
    catch(std::exception & e) {
        std::cerr << "somehitng went wrong" << '\n';
    }
    catch(...) {
        RuntimeUtils::printStackTrace();
    }

    return 0;
}
