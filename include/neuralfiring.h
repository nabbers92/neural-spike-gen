#ifndef NEURALFIRING_H
#define NEURALFIRING_H

#include <vector>

#include "Leap.h"

int GetAngle(float vx, float vz);

std::vector<std::vector<int>> GenerateSpikes(Leap::Vector);

#endif