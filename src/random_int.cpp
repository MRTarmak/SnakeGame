#include <random>

int random_int(int min, int max) {
    return (int)random() % (max - min + 1) + min;
}