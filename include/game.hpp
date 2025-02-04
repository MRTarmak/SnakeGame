#include "field.hpp"

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
    Printer printer;
    Snake snake;
};