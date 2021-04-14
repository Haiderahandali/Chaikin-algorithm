#include "curveDraw.hpp"

curveDraw::curveDraw()
{
    renderer = Window::instance().getRenderer();
}

void curveDraw::Render()
{
    for (auto& x : lines) //each Line contain 2 points A, B
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(renderer, x.A.x, x.A.y, x.B.x, x.B.y);
    }
}

void curveDraw::getLinesFromLinkedList(LinkedListLines const& LLL)
{
    auto h = LLL.getHeadLink();

    //traversing the LinkedList
    while (h->nextLine != nullptr)
    {
        lines.emplace_back(h->data);
        h = h->nextLine;
    }
    lines.emplace_back(h->data);
}

void curveDraw::eventLoop()
{
}

void curveDraw::Update()
{
}