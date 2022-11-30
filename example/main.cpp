#include <cerrno>
#include <iostream>
#include <string>

#include "spikes/firing.h"
#include "spikes/tuning.h"

int main() {
  std::cout << "Hello, world!" << std::endl;
  std::vector<std::vector<float>> base =
      ReadBaseCurves("../../data/basecurves.csv");
  for (auto row_obj : base) {
    for (auto elem : row_obj) {
      std::cout << elem << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::vector<std::vector<float>> tuningcurves =
      CreateTuningCurves(base, 10050, 192);

  for (auto row_obj : tuningcurves) {
    for (auto elem : row_obj) {
      std::cout << elem << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
