#pragma once
#include "LinkedList.hpp"
#include "Window.hpp"

class curveDraw : public WindowWidget
{
public:
    curveDraw();
    ~curveDraw() = default;

public:
    void Render() override;
    void Update() override;
    void eventLoop() override;

public:
    void getLinesFromLinkedList(LinkedListLines const& LLL);

private:
    SDL_Renderer* renderer;

private:
    std::vector<Line> lines;
};