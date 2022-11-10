#include "firing/neuralfiring.h"

#include <math.h>

#include <iostream>
#include <random>
#include <vector>

#include "firing/tuningcurves.h"
#include "leap/Leap.h"

int GetAngle(float vx, float vz) {
  const float kPi = 3.14159265;
  int angle = atan2(vz, vx) * 180 / kPi;
  angle = angle % 360;

  return angle;
}

std::vector<int> ExtractColumn(const std::vector<std::vector<float>>& matrix, 
                               int col_idx) {
  std::vector<int> result;

  for(const auto& row : matrix) {
    result.push_back(row[col_idx]);
  }

 return result;
}

std::vector<int> GenerateSpikes(Leap::Vector velocity, float dt, int n_units,
                                std::vector<std::vector<float>> tuning_curves,
                                int seed) {
  std::vector<int> spikes;
  std::default_random_engine generator;
  generator.seed(seed);
  std::uniform_real_distribution<float> real_distribution(0.0, 1.0);
  float vx = velocity[0];
  float vz = velocity[2];
  int phi = GetAngle(vx, vz);
  std::vector<int> firing_rate = ExtractColumn(tuning_curves, phi);
  
  for (int i = 0; i < firing_rate.size(); i++) {
    if (real_distribution(generator) < firing_rate[i]*dt) {
      spikes[i] = 1;
    }
  }

  return spikes;
}
