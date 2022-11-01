#include "listener/framelistener.h"

FrameListener::FrameListener() {
    void onConnect(const Leap::Controller& controller);
    void onFrame(const Leap::Controller& controller);
};

void FrameListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
    std::cout << timeStart << std::endl;
    timeStart = controller.now();
}

void FrameListener::onFrame(const Leap::Controller& controller) {
    std::cout << timeStart << std::endl;
    std::cout << time << std::endl;
    Leap::Bone::Type boneType;
    boneType = static_cast<Leap::Bone::Type>(3);

    Leap::Frame current = controller.frame(0);
    Leap::Vector current_position = current.hands()[0].fingers()[1].bone(boneType).nextJoint();
    std::cout << current_position << std::endl;
    Leap::Frame previous = controller.frame(1);
}
