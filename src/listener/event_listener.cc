#include "listener/event_listener.h"

EventListener::EventListener() {
    void onConnect(const Leap::Controller& controller);
    void onFrame(const Leap::Controller& controller);
};

void EventListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void EventListener::onFrame(const Leap::Controller& controller) {
    std::cout << "Frame available" << std::endl;
    Leap::Frame current = controller.frame(0);
    Leap::Frame previous = controller.frame(1);
}
