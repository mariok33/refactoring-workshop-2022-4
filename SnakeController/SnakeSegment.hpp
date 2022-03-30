#pragma once

#include <list>

class SnakeSegment
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