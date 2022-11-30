#pragma once

#include <vector>

int GetAngle(float vx, float vz);

std::vector<int> ExtractColumn(const std::vector<std::vector<float>> &matrix,
                               int col_idx);

std::vector<int> GenerateSpikes(std::vector<float> velocity, float dt,
                                int n_units,
                                std::vector<std::vector<float>> tuning_curves,
                                int seed);
