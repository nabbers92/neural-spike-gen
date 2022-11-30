#include <cerrno>
#include <iostream>
#include <string>

#include "spikes/firing.h"
#include "spikes/tuning.h"

int main() {
  std::vector<float> velocity = {0.5, 0.5};
  float dt = 0.008;
  int n_units = 192;
  int seed = 10050;

  // std::cout << "Hello, world!" << std::endl;
  std::vector<std::vector<float>> base =
      ReadBaseCurves("../../data/basecurves.csv");
  // for (auto row_obj : base) {
  //   for (auto elem : row_obj) {
  //     std::cout << elem << ", ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  std::vector<std::vector<float>> tuningcurves =
      CreateTuningCurves(base, seed, n_units);

  // for (auto row_obj : tuningcurves) {
  //   for (auto elem : row_obj) {
  //     std::cout << elem << ", ";
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  std::vector<int> spikesarray =
      GenerateSpikes(velocity, dt, n_units, tuningcurves, seed);

  return 0;
}
