#include "field.hpp"
#include <windows.h>

class Game {
public:
    Game();

    void initGame();

    void start();

private:
    int changeDirection();

    void waitingForStart();

    void waitingForRestart();

    Field field;
    Snake snake;
};