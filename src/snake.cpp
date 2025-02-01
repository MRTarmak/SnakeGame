#include "snake.hpp"

Snake::Snake() : segments() {
    growingSegment = {-1, -1};
    direction = 0;
    length = 0;
}

void Snake::updateSegments() {
    growingSegment = segments[length - 1];

    for (int i = length - 1; i > 0; i--) {
        segments[i].first = segments[i - 1].first;
        segments[i].second = segments[i - 1].second;
    }
    switch (direction) {
        case 'u':
            segments[0].first -= 1;
            break;
        case 'd':
            segments[0].first += 1;
            break;
        case 'r':
            segments[0].second += 1;
            break;
        case 'l':
            segments[0].second -= 1;
            break;
    }
}

void Snake::grow() {
    segments.push_back(growingSegment);
    length++;
}

void Snake::reborn() {
    segments.clear();
    growingSegment = {-1, -1};
    direction = 0;
    length = 0;
}