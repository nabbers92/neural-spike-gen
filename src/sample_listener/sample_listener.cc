#include "sample_listener.h"

SampleListener::SampleListener() {
    onConnect(controller);
    onFrame(controller);
}

void SampleListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Leap::Controller& controller) {
    std::cout << "Frame available" << std::endl;
}