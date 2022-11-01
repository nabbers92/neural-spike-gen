#include "listener/framelistener.h"

FrameListener::FrameListener(int bone_type) {
    void onConnect(const Leap::Controller& controller);
    void onFrame(const Leap::Controller& controller);
    bone_type_ = static_cast<Leap::Bone::Type>(bone_type);
};

void FrameListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
    time_start_ = controller.now();    
}

void FrameListener::onFrame(const Leap::Controller& controller) {
    int time = controller.now() - time_start_;
    std::cout << time << std::endl;
    // Leap::Bone::Type boneType;
    // boneType = static_cast<Leap::Bone::Type>(3);

    Leap::Frame current = controller.frame(0);
    Leap::Vector current_position = current.hands()[0].fingers()[1].bone(bone_type_).nextJoint();
    std::cout << current_position << std::endl;
    Leap::Frame previous = controller.frame(1);
}