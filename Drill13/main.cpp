/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "grid.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    Simple_window win {Point{200,200}, xmax, ymax, "Drill 13"};
    Grid myGrid {5, 5, 100, 100, Graph_lib::Color::black};
    win.attach(myGrid);
    Vector_ref<Rectangle> rects;
    for (int i = 0; i < myGrid.GetTheNumberOfCellsY(); i++) {
        rects.push_back(new Rectangle {{0, i * myGrid.GetTheCellSizeY()}, myGrid.GetTheCellSizeX(), myGrid.GetTheCellSizeY()});
        rects[rects.size() - 1].set_color(Graph_lib::Color::red);
    }
    for (int i = 0; i < rects.size(); i++)
        win.attach(rects[i]);
    
    Image iii {Point{100, 0}, "badge.jpg"};
    Image iv {Point{100, 200}, "badge.jpg"};
    Image v {Point{100, 400}, "badge.jpg"};
    win.attach(iii);
    win.attach(iv);
    win.attach(v);
    Image img {Point{0,0}, "kep.jpg"};
    win.attach(img);
    int movesX = 0;
    int movesY = 0;
    while (true)
    {
        win.wait_for_button();
        img.move(100, 0);
        movesX++;
        if (movesX == myGrid.GetTheNumberOfCellsX()) {
            img.move(myGrid.GetTheNumberOfCellsX() * myGrid.GetTheCellSizeX() * -1, 100);
            movesX = 0;
            movesY++;
        }
        if (movesY == myGrid.GetTheNumberOfCellsY()) {
            img.move(0, myGrid.GetTheNumberOfCellsY() * myGrid.GetTheCellSizeY() * -1);
            movesY = 0;
        }
    }
}
