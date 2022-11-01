#ifndef LISTENER_FRAMELISTENER_H
#define LISTENER_FRAMELISTENER_H

#include "leap/leap.h"

class FrameListener : public Leap::Listener {
    private:
        int time_start_;
        Leap::Bone::Type bone_type_;

    public:
        FrameListener(int bone_type);
        virtual void onConnect(const Leap::Controller&);
        virtual void onFrame(const Leap::Controller&);
};

#endif