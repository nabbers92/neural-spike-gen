#include <string.h>

#include <iostream>

#include "leap/Leap.h"
#include "listener/framelistener.h"

int main(int argc, char** argv) {
  int bone_idx = 3; 

  FrameListener listener(bone_idx);
  Leap::Controller controller;

  controller.addListener(listener);

    // Keep this process running until Enter is pressed
  std::cout << "Press Enter to quit..." << std::endl;
  std::cin.get();

    // Remove the sample listener when done
  controller.removeListener(listener);

  return 0;
}