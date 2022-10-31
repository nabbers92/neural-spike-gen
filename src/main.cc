#include <iostream>
#include <string.h>
#include "Leap.h"
#include "sample_listener.h"

// using namespace Leap;

// class SampleListener : public Leap::Listener {
//     public:
//     virtual void onConnect(const Leap::Controller&);
//     virtual void onFrame(const Leap::Controller&);
// };

// void SampleListener::onConnect(const Leap::Controller& controller) {
//     std::cout << "Connected" << std::endl;
// }

// void SampleListener::onFrame(const Leap::Controller& controller) {
//     std::cout << "Frame available" << std::endl;
// }

int main(int argc, char** argv) {

    SampleListener listener;
    Leap::Controller controller;

    controller.addListener(listener);

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

    // Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}