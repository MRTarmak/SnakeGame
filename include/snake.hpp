#include <vector>

struct Snake {
    Snake();

    void updateSegments();

    void grow();

    void reborn();

    std::vector<std::pair<short, short>> segments;
    std::pair<short, short> growingSegment;
    char direction;
    int length;
};