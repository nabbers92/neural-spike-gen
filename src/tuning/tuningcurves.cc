#include "tuning/tuningcurves.h"

struct BaseCurves BaseTuningCurves(const std::string& filename) {
  struct BaseCurves base_curves;
  float data[9][360];
  std::ifstream file(filename);

  for (int row = 0; row < 10; row++) {
    std::string line;
    std::getline(file, line);
    if ( !file.good() )
      break;

    std::stringstream iss(line);

    for (int col = 0; col < 360; col++) {
      std::string val;
      std::getline(iss, val, ',');
      if ( !iss.good() )
        break;

      std::stringstream convertor(val);
      convertor >> data[row][col];
    }
  }
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 360; col++) {
      base_curves.arr[row][col] = data[row+1][col];
    } 
  }
  
  return base_curves;
}