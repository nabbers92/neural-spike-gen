#include <iostream>
#include <string.h>
#include "leap/Leap.h"
#include "listener/event_listener.h"

int main(int argc, char** argv) {

    EventListener listener;
    Leap::Controller controller;
    // if( controller.isConnected()) {
    controller.addListener(listener);
    // }

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}