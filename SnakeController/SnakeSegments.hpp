#pragma once

#include <list>

#include "SnakeInterface.hpp"

namespace Snake
{

struct Segment
{
    int x;
    int y;
};

class SnakeSegments
{
public:
    bool isSegmentAtPosition(int x, int y) const;

    Segment calculateNewHead() const;
    void addHeadSegment(Segment const& newHead);
    Segment removeTailSegment();

private:
    std::list<Segment> m_segments;
    Direction m_currentDirection;
};

}// namespace