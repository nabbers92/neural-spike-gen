#include "tuning/tuningcurves.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<float>> ReadBaseCurves(const std::string& filename) {
  std::string line;
  std::vector<std::vector<float>> base_curves;
  std::ifstream datafile (filename);

  while (std::getline (datafile, line)) {
    std::string val;
    std::vector<float> row;
    std::stringstream s (line);

    while (std::getline (s, val, ',')) {
      row.push_back (stof(val));
    }
    
    base_curves.push_back (row);
    }

  datafile.close();
  std::cout << "parsing complete" << std::endl;
  return base_curves;
}