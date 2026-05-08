#pragma once
#include "printer.hpp"
#include "snake.hpp"
#include "randomizer.hpp"

#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25
#define FIELD {"#########################",\
               "#.......................#",\
               "#.............#####.....#",\
               "#.......................#",\
               "#.......................#",\
               "#.......................#",\
               "#.......................#",\
               "#.....#.................#",\
               "#.....#.................#",\
               "#.....#.................#",\
               "#.....#.................#",\
               "#.......................#",\
               "#.......................#",\
               "#.......................#",\
               "#.......................#",\
               "#.................#.....#",\
               "#.................#.....#",\
               "#.................#.....#",\
               "#.......................#",\
               "#.......................#",\
               "#.......................#",\
               "#.....##................#",\
               "#.......................#",\
               "#.......................#",\
               "#########################"}

class Field {
public:
    Field(Snake &snake, Printer &printer);

    void initField();

    int updateField();

    void restart();

private:
    void readField();

    void updateApple();

    void removeCoords(std::pair<short, short> coords);

    std::vector<std::string> field;
    int fieldWidth;
    int fieldHeight;
    Snake &snake;
    Printer &printer;
    std::pair<short, short> apple;
    int score;
    int topScore;
    std::vector<std::pair<short, short>> availableCoords;
};