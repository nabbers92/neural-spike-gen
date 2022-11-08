#include "firing/tuningcurves.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<float>> ReadBaseCurves(const char* filename) {
  std::string line;
  std::vector<std::vector<float>> base_curves;
  std::ifstream datafile (filename);

  if (!datafile.is_open()) {     /* validate file open for reading */
        perror (("error while opening file " + std::string(filename)).c_str());
    }

  while (std::getline(datafile, line)) {
    std::string val;
    std::vector<float> row;
    std::stringstream s (line);

    while (std::getline(s, val, ',')) {
      row.push_back(std::stof(val));
    }

    base_curves.push_back(row);
  }

  datafile.close();
  base_curves.erase(base_curves.begin());  // remove indexing row (values 0-359)
  
  return base_curves;
}

std::vector<std::vector<float>> CreateTuningCurves(
    std::vector<std::vector<float>> base_curves,
    int seed,
    int n_units) {
  std::vector<std::vector<float>> tuning_curves;
  std::default_random_engine generator;
  generator.seed(seed);
  std::uniform_int_distribution<int> int_distribution(0, base_curves.size());
  std::uniform_real_distribution<float> real_distribution(0.8, 1.2);
  
  for (int i=0; i < n_units; i++) {
    int index = int_distribution(generator);
    float scalar = real_distribution(generator);
    std::vector<float> temp = base_curves[index];
    int shift_val = (2*index)*(360/n_units);
    std::rotate(temp.begin(), temp.begin()+shift_val, temp.end());
    MultiplyVectorByScalar(temp, scalar);
    tuning_curves.push_back(temp);
  }
  std::cout << tuning_curves.size() << std::endl;
  return tuning_curves; 
}

void MultiplyVectorByScalar(std::vector<float> vector, float scalar){
    std::transform(vector.begin(), vector.end(), vector.begin(), 
                   [scalar](float v){ return v*scalar;});
}
