#ifndef LISTENER_FRAMELISTENER_H
#define LISTENER_FRAMELISTENER_H

#include "leap/leap.h"

class FrameListener : public Leap::Listener {
    public:
        FrameListener();
        virtual void onConnect(const Leap::Controller&);
        virtual void onFrame(const Leap::Controller&);
};

#endif