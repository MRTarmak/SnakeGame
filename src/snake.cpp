#include <vector>

struct Snake {
    Snake() {
        direction = 'u';
        length = 0;
    }

    void update_segments() {
        for (int i = length - 1; i > 0; i--)
        {
            segments[i].first = segments[i - 1].first;
            segments[i].second = segments[i - 1].second;
        }
        switch (direction) {
            case 'u':
                segments[0].first -= 1;
            case 'd':
                segments[0].first += 1;
            case 'r':
                segments[0].second += 1;
            case 'l':
                segments[0].second -= 1;
        }
    }

    std::vector<std::pair<int, int>> segments;
    char direction;
    int length;
};