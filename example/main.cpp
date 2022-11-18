#include <iostream>

#include "spikes/firing.h"
#include "spikes/tuning.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    std::vector<std::vector<float>> base;
    base = ReadBaseCurves("../../data/basecurves.csv");

    return 0;
}