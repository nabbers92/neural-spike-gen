#ifndef TUNING_TUNINGCURVES_H
#define TUNING_TUNINGCURVES_H

#include <fstream>
#include <sstream>

struct BaseCurves {
  float arr[8][360];
};

struct BaseCurves BaseTuningCurves(const std::string& filename);

#endif