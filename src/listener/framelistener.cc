#include "listener/framelistener.h"

FrameListener::FrameListener() {
    void onConnect(const Leap::Controller& controller);
    void onFrame(const Leap::Controller& controller);
};

void FrameListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void FrameListener::onFrame(const Leap::Controller& controller) {
    std::cout << "Frame available" << std::endl;
    Leap::Frame current = controller.frame(0);
    Leap::Frame previous = controller.frame(1);
}
