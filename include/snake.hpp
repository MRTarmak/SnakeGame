#include <vector>

struct Snake {
    Snake();

    void updateSegments();

    void grow();

    void reborn();

    std::vector<std::pair<int, int>> segments;
    std::pair<int, int> growingSegment;
    char direction;
    int length;
};