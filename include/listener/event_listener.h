#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H
#include "leap/Leap.h"

class EventListener : public Leap::Listener {
    public:
        EventListener();
        virtual void onConnect(const Leap::Controller&);
        virtual void onFrame(const Leap::Controller&);
};

#endif