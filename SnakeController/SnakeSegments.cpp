#include "SnakeSegments.hpp"

#include <algorithm>
#include <memory>

namespace Snake
{

namespace
{
bool isHorizontal(Direction direction)
{
    return Direction_LEFT == direction or Direction_RIGHT == direction;
}

bool isVertical(Direction direction)
{
    return Direction_UP == direction or Direction_DOWN == direction;
}

bool isPositive(Direction direction)
{
    return (isVertical(direction) and Direction_DOWN == direction)
        or (isHorizontal(direction) and Direction_RIGHT == direction);
}

} // namespace

Segment SnakeSegments::calculateNewHead() const // ctr c
{
    Segment const& currentHead = m_segments.front();

    Segment newHead;
    newHead.x = currentHead.x + (isHorizontal(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);
    newHead.y = currentHead.y + (isVertical(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);

    return newHead;
}

void SnakeSegments::addHeadSegment(Segment const& newHead) 
{
    m_segments.push_front(newHead);
}

Segment SnakeSegments::removeTailSegment()
{
    auto tail = m_segments.back();
    m_segments.pop_back();

    return tail;
}

bool SnakeSegments::isSegmentAtPosition(int x, int y) const
{
    return m_segments.end() != std::find_if(m_segments.cbegin(), m_segments.cend(),
                                            [x, y](auto const &segment)
                                            { return segment.x == x and segment.y == y; });
}
} // namespace