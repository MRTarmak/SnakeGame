#include "field.hpp"

Field::Field(Snake &snake, Printer &printer) : field(), snake(snake), printer(printer), availableCoords() {
    apple = {-1, -1};
    score = 0;
    topScore = 0;
}

void Field::initField() {
    readField();

    for (int x = 0; x < fieldHeight; x++) {
        for (int y = 0; y < fieldWidth; y++) {
            if (field[x][y] != '#')
                availableCoords.emplace_back(x, y);
        }
    }

    int i = randomInt(0, (int)availableCoords.size() - 1);
    snake.growingSegment = availableCoords[i];

    snake.grow();
    int x = snake.growingSegment.first;
    int y = snake.growingSegment.second;
    field[x][y] = '0';
    availableCoords.erase(availableCoords.cbegin() + i);

    updateApple();
    x = apple.first;
    y = apple.second;
    field[x][y] = '@';

    printer.printField(field, score, topScore);
}

int Field::updateField() {
    short x, y;
    bool ate_apple = false;

    for (int i = 0; i < snake.length; i++) {
        x = snake.segments[i].first;
        y = snake.segments[i].second;
        printer.setCoord({y, x});

        if (i == 0) {
            if (field[x][y] == '@')
                ate_apple = true;
            if (field[x][y] == '#' || field[x][y] == 'o')
                return 1;

            field[x][y] = '0';
            removeCoords({x, y});
            printer.overwriteCharacter('0', FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        } else {
            field[x][y] = 'o';
            printer.overwriteCharacter('o', FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
    }

    if (ate_apple) {
        score++;
        printer.overwriteScore(score, topScore, fieldHeight);
        snake.grow();
        updateApple();

        x = apple.first;
        y = apple.second;
        printer.setCoord({y, x});

        field[x][y] = '@';
        printer.overwriteCharacter('@', FOREGROUND_RED | FOREGROUND_INTENSITY);
    } else {
        x = snake.growingSegment.first;
        y = snake.growingSegment.second;
        printer.setCoord({y, x});

        field[x][y] = '.';
        availableCoords.emplace_back(x, y);
        printer.overwriteCharacter('.', FOREGROUND_GREEN);
    }

    return 0;
}

void Field::restart() {
    field.clear();
    fieldWidth = 0;
    fieldHeight = 0;
    snake.reborn();
    topScore = std::max(score, topScore);
    score = 0;
    availableCoords.clear();

    initField();
}

void Field::readField() {
    std::ifstream inputFile("../FIELD");

    if (!inputFile) {
        exit(-1);
    }

    inputFile >> fieldWidth >> fieldHeight;

    std::string str;

    for (int i = 0; i < fieldHeight; i++) {
        inputFile >> str;
        field.push_back(str);
    }

    inputFile.close();
}

void Field::updateApple() {
    int i = randomInt(0, (int)availableCoords.size() - 1);\

    apple = availableCoords[i];
}

void Field::removeCoords(std::pair<short, short> coords) {
    availableCoords.erase(std::remove(availableCoords.begin(),
                                      availableCoords.end(),
                                      coords), availableCoords.end());
}