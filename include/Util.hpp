struct Point
{
    int x = 0;
    int y = 0;
};

struct Line
{
    Point A;
    Point B;
};

struct LinkedLine
{
    Line data;
    LinkedLine* nextLine {};
};
struct HeadLine //----- the Head of the LinkedList
{
    LinkedLine* head;
};
struct TailLine //---- The Tail of LinkedList
{
    LinkedLine* tail;
};

//---------------- Points Overloading -----------------//
Point operator+(Point const& lhs, Point const& rhs);
Point operator-(Point const& lhs, Point const& rhs);
Point operator*(Point const& lhs, double const& p);

//----------------------------------------------------//
inline Point operator+(Point const& lhs, Point const& rhs)
{
    return Point { lhs.x + rhs.x, lhs.y + rhs.y };
}

inline Point operator*(Point const& lhs, double const& p)
{
    return Point { static_cast<int>(lhs.x * p), static_cast<int>(lhs.y * p) };
}

inline Point operator-(Point const& lhs, Point const& rhs)
{
    return Point { lhs.x - rhs.x, lhs.y - rhs.y };
}
