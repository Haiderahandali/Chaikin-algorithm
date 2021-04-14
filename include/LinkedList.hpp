#pragma once
#include "Util.hpp"

//--------------------------------------//
//--------------------------------------//
class LinkedListLines
{
public:
    explicit LinkedListLines(Line Head);
    ~LinkedListLines() = default;

public:
    void addLine(Line const& line);
    void PrintLines() const;
    void Divide(unsigned int times);

public:
    LinkedLine* getHeadLink() const;
    LinkedLine* getTailLink();
    Line getTailLine();

private:
    void lineSubDivide(LinkedLine&);
    void divideTail();

private:
    HeadLine headNode {};
    TailLine tailNode {};
};
