#include "tuning/tuningcurves.h"

float** BaseTuningCurves(const std::string& filename) {
  float data[38][27];
  std::ifstream file("sheet.csv");

  for(int row = 0; row < 38; ++row) {
    std::string line;
    std::getline(file, line);
    if ( !file.good() )
      break;

    std::stringstream iss(line);

    for (int col = 0; col < 27; ++col) {
      std::string val;
      std::getline(iss, val, ',');
      if ( !iss.good() )
        break;

      std::stringstream convertor(val);
      convertor >> data[row][col];
    }
  }
  return data;
}