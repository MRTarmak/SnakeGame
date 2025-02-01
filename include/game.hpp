#include "field.hpp"

class Game {
public:
    Game();

    void start();

private:
    int changeDirection();

    void waitingForStart();

    void waitingForRestart();

    Field field;
    Snake snake;
};