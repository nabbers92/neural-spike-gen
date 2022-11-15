#pragma once

#include <vector>

int GetAngle(float vx, float vz);

std::vector<int> GenerateSpikes(std::vector<float> velocity, float dt,
                                int n_units,
                                std::vector<std::vector<float>> tuning_curves,
                                int seed);
