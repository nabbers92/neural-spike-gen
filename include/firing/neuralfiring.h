#ifndef FIRING_NEURALFIRING_H
#define FIRING_NEURALFIRING_H

#include <vector>

#include "leap/Leap.h"

int GetAngle(float vx, float vz);

std::vector<std::vector<int>> GenerateSpikes(Leap::Vector);

#endif