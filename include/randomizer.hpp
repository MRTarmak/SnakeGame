#include <random>

class Randomizer {
    inline static std::mt19937 gen{std::random_device{}()};

public:
    Randomizer();

    static int randomInt(int min, int max);
};