#ifndef SAMPLE_LISTENER_H
#define SAMPLE_LISTENER_H
#include "Leap.h"

class SampleListener : public Leap::Listener {
    public:
        virtual void onConnect(const Leap::Controller&);
        virtual void onFrame(const Leap::Controller&);
};

#endif