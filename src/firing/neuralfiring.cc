#include "firing/neuralfiring.h"

#include <math.h>

#include <iostream>
#include <vector>

#include "firing/tuningcurves.h"
#include "leap/Leap.h"

int GetAngle(float vx, float vz) {
  const float kPi = 3.14159265;
  int angle = atan2(vz, vx) * 180 / kPi;
  angle = angle % 360;

  return angle;
}
