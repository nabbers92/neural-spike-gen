#include "event_listener.h"

EventListener::EventListener() {
    EventListener();
}

void EventListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void EventListener::onFrame(const Leap::Controller& controller) {
    std::cout << "Frame available" << std::endl;
    Leap::Frame frame = controller.frame();
}

// void EventListener::helloWorld() {
//     std::cout << "This is a new frame" << std::endl;
// }