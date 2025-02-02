#include <iostream>
#include "snake.hpp"
#include "randomInt.hpp"

#define HEIGHT 25
#define WIDTH 25
#define FIELD {"#########################", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#.......................#", \
               "#########################"};

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN   "\033[32m"

class Field {
public:
    Field(Snake &);

    void initField();

    int updateField();

    void restart();

    void printField(bool = false);

private:
    void updateApple();

    std::string field[HEIGHT] = FIELD;
    std::pair<int, int> apple;
    Snake &snake;
    int score;
    int topScore;
};