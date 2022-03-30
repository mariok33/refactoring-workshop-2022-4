#pragma once

#include <list>

class SnakeSegments
{
public:
    bool isSegmentAtPosition(int x, int y) const;

private:

    struct Segment
    {
        int x;
        int y;
    };

    std::list<Segment> m_segments;
};