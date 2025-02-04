#include "game.hpp"

Game::Game() : field(snake, printer), printer(), snake() {}

void Game::initGame() {
    field.initField();

    waitingForStart();
}

void Game::start() {
    while (true) {
        changeDirection();
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
            exit(0);
        if (GetAsyncKeyState('R') & 0x8001) {
            field.restart();
            return;
        }

        snake.updateSegments();
        if (field.updateField()) {
            printer.printGameOver();
            waitingForRestart();
            return;
        } else {
            Sleep(150);
        }
    }
}

int Game::changeDirection() {
    if (GetAsyncKeyState(VK_UP) & 0x8001) {
        if (snake.direction == 'l' || snake.direction == 'r' || snake.direction == 0) {
            snake.direction = 'u';
            return 1;
        }
    } else if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
        if (snake.direction == 'l' || snake.direction == 'r' || snake.direction == 0) {
            snake.direction = 'd';
            return 1;
        }
    } else if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
        if (snake.direction == 'u' || snake.direction == 'd' || snake.direction == 0) {
            snake.direction = 'r';
            return 1;
        }
    } else if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
        if (snake.direction == 'u' || snake.direction == 'd' || snake.direction == 0) {
            snake.direction = 'l';
            return 1;
        }
    }

    return 0;
}

void Game::waitingForStart() {
    while (true) {
        if (changeDirection())
            start();

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
            exit(0);
        if (GetAsyncKeyState('R') & 0x8001) {
            field.restart();
        }

        Sleep(500);
    }
}

void Game::waitingForRestart() {
    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
            exit(0);
        if (GetAsyncKeyState('R') & 0x8001) {
            field.restart();
            return;
        }
    }
}