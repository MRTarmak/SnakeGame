#include <iostream>
#include <algorithm>
#include <vector>
#include <windows.h>

#define GAME_FIELD_OFFSET 10
#define SCORE_OFFSET 12
#define CHANGE_DIRECTION_OFFSET 3
#define RESTART_OFFSET 17
#define EXIT_OFFSET 18

class Printer {
public:
    Printer();

    void overwriteCharacter(TCHAR newChar, WORD color);

    void overwriteScore(const int &score, const int &topScore, const int &fieldHeight);

    void printField(const std::vector<std::string> &field, const int &score, const int &topScore);

    void printGameOver();

    void setCoord(COORD newCoord);

private:
    void hideCursor();

    void setColor(WORD color);

    HANDLE hConsole;
    COORD coord;
    int scoreLength;
};