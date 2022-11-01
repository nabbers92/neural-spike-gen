#ifndef FRAMELISTENER_H
#define FRAMELISTENER_H

#include "leap/Leap.h"

class FrameListener : public Leap::Listener {
    public:
        FrameListener();
        virtual void onConnect(const Leap::Controller&);
        virtual void onFrame(const Leap::Controller&);
};

#endif