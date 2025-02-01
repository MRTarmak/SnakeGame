#include "field.hpp"
#include "randomInt.hpp"

Field::Field(Snake &snake) : snake(snake) {
    apple = {-1, -1};
    score = 0;
    topScore = 0;
}

void Field::initField() {
    int x = randomInt(1, HEIGHT - 2);
    int y = randomInt(1, WIDTH - 2);
    snake.growingSegment = {x, y};

    snake.grow();
    x = snake.growingSegment.first;
    y = snake.growingSegment.second;
    field[x][y] = '0';

    updateApple();
    x = apple.first;
    y = apple.second;
    field[x][y] = '@';

    printField(true);
}

int Field::updateField() {
    int x, y;
    bool ate_apple = false;

    for (int i = 0; i < snake.length; i++) {
        x = snake.segments[i].first;
        y = snake.segments[i].second;

        if (i == 0) {
            if (field[x][y] == '@')
                ate_apple = true;
            if (field[x][y] == '#' || field[x][y] == 'o')
                return 1;

            field[x][y] = '0';
        } else {
            field[x][y] = 'o';
        }
    }

    if (ate_apple) {
        score++;
        snake.grow();
        updateApple();
        x = apple.first;
        y = apple.second;
        field[x][y] = '@';
    } else {
        x = snake.growingSegment.first;
        y = snake.growingSegment.second;
        field[x][y] = '.';
    }

    return 0;
}

void Field::restart() {
    std::string new_field[HEIGHT] = FIELD;

    for (int i = 0; i < HEIGHT; i++)
    {
        field[i] = new_field[i];
    }

    snake.reborn();
    topScore = std::max(score, topScore);
    score = 0;

    initField();
}

void Field::printField(bool show_hint) {
    if (show_hint) {
        std::cout << "Hint:" << std::endl;
        std::cout << "Change direction: UP, DOWN, RIGHT, LEFT" << std::endl;
        std::cout << "Restart: R" << std::endl;
        std::cout << "Exit: Esc" << std::endl;
    }

    std::cout << "Score: " << score << ", " << "Top score: " << topScore << std::endl;
    for (const std::string &str : field) {
        std::cout << str;
    }
    std::cout << std::endl;
}

void Field::updateApple() {
    int x, y;
    do {
        x = randomInt(1, HEIGHT - 2);
        y = randomInt(1, WIDTH - 2);
    } while (field[x][y] == '0' || field[x][y] == 'o');
    apple = {x, y};
}