#include "printer.hpp"

Printer::Printer() : coord(), scoreLength() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Printer::overwriteCharacter(char character, WORD color) {
    setColor(color);

    SetConsoleCursorPosition(hConsole, coord);

    std::cout << character << std::flush;
}

void Printer::overwriteScore(const int &score, const int &topScore, const int &fieldHeight) {
    scoreLength = (int)(std::to_string(score).length() +
                        std::to_string(topScore).length());

    coord.X = (short)(SCORE_OFFSET - scoreLength / 2 + 1);
    coord.Y = (short)(fieldHeight);

    setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    SetConsoleCursorPosition(hConsole, coord);

    std::cout << "Score: " << score << ", " << "TopScore: " << topScore << std::endl;
}

void Printer::printField(const std::vector<std::string> &field, const int &score, const int &topScore) {
    system("cls");
    hideCursor();

    for (const std::string &str : field) {
        for (int i = 0; i < GAME_FIELD_OFFSET; i++)
            std::cout << ' ';

        for (const char &character : str) {
            if (character == '0' || character == 'o')
                setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            else if (character == '@')
                setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
            else if (character == '.')
                setColor(FOREGROUND_GREEN);
            else
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            std::cout << character;
        }

        std::cout << std::endl;
    }

    scoreLength = (int)(std::to_string(score).length() +
                        std::to_string(topScore).length());

    coord.X = (short)(SCORE_OFFSET - scoreLength / 2 + 1);
    coord.Y = (short)(field.size());
    setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetConsoleCursorPosition(hConsole, coord);
    std::cout << "Score: " << score << ", " << "TopScore: " << topScore << std::endl;
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    coord.X = (short)(CHANGE_DIRECTION_OFFSET);
    coord.Y++;
    SetConsoleCursorPosition(hConsole, coord);
    std::cout << "Change direction: UP, DOWN, RIGHT, LEFT" << std::endl;

    coord.X = (short)(RESTART_OFFSET);
    coord.Y++;
    SetConsoleCursorPosition(hConsole, coord);
    std::cout << "Restart:  R" << std::endl;

    coord.X = (short)(EXIT_OFFSET);
    coord.Y++;
    SetConsoleCursorPosition(hConsole, coord);
    std::cout << "Exit: Esc" << std::flush;
}

void Printer::printGameOver() {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo);

    coord.X = 0;
    coord.Y = (short)(consoleScreenBufferInfo.srWindow.Bottom - consoleScreenBufferInfo.srWindow.Top);

    SetConsoleCursorPosition(hConsole, coord);

    setColor(FOREGROUND_RED);

    std::cout << "Game Over. Press R to restart or Esc to exit." << std::flush;
}

void Printer::setCoord(COORD newCoord) {
    newCoord.X += GAME_FIELD_OFFSET;
    coord = newCoord;
}

void Printer::hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Printer::setColor(WORD color) {
    SetConsoleTextAttribute(hConsole, color);
}