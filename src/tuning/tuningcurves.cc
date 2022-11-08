#include "tuning/tuningcurves.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<float>> ReadBaseCurves(const char* filename) {
  std::string line;
  std::vector<std::vector<float>> base_curves;
  std::ifstream datafile (filename);
  // std::cout << filename << std::endl;

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
    std::cout << row[0] << std::endl;
    base_curves.push_back(row);
  }

  datafile.close();
  // std::cout << "parsing complete" << std::endl;
  return base_curves;
}