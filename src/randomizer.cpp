#include "randomizer.hpp"

int Randomizer::randomInt(int min, int max) {
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}