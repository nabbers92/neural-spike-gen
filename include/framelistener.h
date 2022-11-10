#ifndef FRAMELISTENER_H
#define FRAMELISTENER_H

#include "Leap.h"

class FrameListener : public Leap::Listener
{
private:
  int time_start_;
  // Leap::Bone::Type bone_type_;

public:
  // FrameListener(int bone_type);
  virtual void onConnect(const Leap::Controller &){};
  virtual void onFrame(const Leap::Controller &){};
};

#endif