#pragma once

#include <vector>

std::vector<std::vector<float>> ReadBaseCurves(const char *filename);

std::vector<std::vector<float>> CreateTuningCurves(
    std::vector<std::vector<float>> base_curves, int seed, int n_units);

void MultiplyVectorByScalar(std::vector<float> v, float k);
