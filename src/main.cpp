// #include "Window.hpp"
#include "LinkedList.hpp"
#include "curveDraw.hpp"
int main()
{
    auto& window = Window::instance();

    Line l1 = { { 100, 100 }, { 50, 150 } };
    Line l2 = { { 50, 150 }, { 100, 200 } };
    Line l3 = { { 100, 200 }, { 150, 150 } };
    Line l4 = { { 150, 150 }, { 100, 100 } };

    auto curve  = new curveDraw();
    auto curve2 = new curveDraw();

    LinkedListLines LLL = LinkedListLines(l1);

    LLL.addLine(l2);
    LLL.addLine(l3);
    LLL.addLine(l4);

    curve->getLinesFromLinkedList(LLL);

    l1 = { { 100 + 200, 100 }, { 50 + 200, 150 } };
    l2 = { { 50 + 200, 150 }, { 100 + 200, 200 } };
    l3 = { { 100 + 200, 200 }, { 150 + 200, 150 } };
    l4 = { { 150 + 200, 150 }, { 100 + 200, 100 } };

    LinkedListLines LLL2 = LinkedListLines(l1);
    LLL2.addLine(l2);
    LLL2.addLine(l3);
    LLL2.addLine(l4);

    LLL2.Divide(18);
    curve2->getLinesFromLinkedList(LLL2);
    window.addWindowWidget(curve);
    window.addWindowWidget(curve2);
    while (window.isRunning())
    {
        window.eventLoop();
        window.Render();
        window.Update();
    }
}