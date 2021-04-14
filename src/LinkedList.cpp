#include "LinkedList.hpp"
#include <stdio.h>

LinkedListLines::LinkedListLines(Line Head)
{
    headNode.head = new LinkedLine();
    tailNode.tail = new LinkedLine();

    headNode.head->data     = Head;
    tailNode.tail           = headNode.head;
    tailNode.tail->nextLine = nullptr;
}

/*

            the Original Line was from (A to B)       p3 lines on the next line

             25%                   50%                    75%
    <----------------------p1----------------------p2-------------------->     <--------
Point A     1st Line           second_line              third_line      B     p3
        (from A to p1).       from (p1 to p2)           from (p2 to p3)

*/
void LinkedListLines::lineSubDivide(LinkedLine& current)
{

    Point p1 = current.data.A + (current.data.B - current.data.A) * 0.25;
    Point p2 = current.data.A + (current.data.B - current.data.A) * 0.75;

    auto nextLine = current.nextLine;

    Point p3 = nextLine->data.A + (nextLine->data.B - nextLine->data.A) * 0.25;

    auto second_line = Line { p1, p2 };
    auto third_line  = Line { p2, p3 };

    current.data     = second_line;
    current.nextLine = new LinkedLine({ third_line, nextLine });
}

void LinkedListLines::addLine(Line const& line)
{
    auto newLink            = new LinkedLine { line, nullptr };
    tailNode.tail->nextLine = newLink;
    tailNode.tail           = newLink;
}

void LinkedListLines::PrintLines() const
{
    printf("\n\n\n");
    auto h = headNode.head;
    while (h->nextLine != nullptr) //traversing the linkedList
    {
        printf("(%d,%d) , (%d,%d)  \n", h->data.A.x, h->data.A.y, h->data.B.x, h->data.B.y);
        h = h->nextLine;
    }
    printf("(%d,%d) , (%d,%d)  \n", h->data.A.x, h->data.A.y, h->data.B.x, h->data.B.y);
}

Line LinkedListLines::getTailLine()
{
    //if the Tail is not pointing at the end (for whatever reason!)
    //get the end
    if (tailNode.tail->nextLine == nullptr)
    {
        return tailNode.tail->data;
    }
    else
        while (tailNode.tail->nextLine != nullptr)
            tailNode.tail = tailNode.tail->nextLine;

    return tailNode.tail->data;
}

void LinkedListLines::Divide(unsigned int times)
{
    for (unsigned int i = 1; i <= times; ++i)

    {
        auto h = headNode.head;
        while (h->nextLine != nullptr) //traversing the linkedList
        {
            auto t = h->nextLine;
            lineSubDivide(*h);
            h = t;
        }
        divideTail();
    }
}
void LinkedListLines::divideTail()
{
    auto tail = getTailLink();

    Point p1 = tail->data.A + (tail->data.B - tail->data.A) * 0.25;
    Point p2 = tail->data.A + (tail->data.B - tail->data.A) * 0.75;

    tail->data.A = p1;
    tail->data.B = p2;
}

LinkedLine* LinkedListLines::getHeadLink() const
{
    return headNode.head;
}

LinkedLine* LinkedListLines::getTailLink()
{
    if (tailNode.tail->nextLine == nullptr)
    {
        return tailNode.tail;
    }
    else
        while (tailNode.tail->nextLine != nullptr)
            tailNode.tail = tailNode.tail->nextLine;

    return tailNode.tail;
}
