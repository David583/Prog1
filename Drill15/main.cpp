/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    Simple_window win {Point{100,100}, xmax, ymax, "Function Graph"};

	Axis x {Axis::x, Point{0, 300}, 400, 20, "x"};
	Axis y {Axis::y, Point{300, 400}, 400, 20, "y"};
	x.set_color(Graph_lib::Color::red);
	y.set_color(Graph_lib::Color::red);
	x.label.set_label("1==20");
	y.label.set_label("1==20");

	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}
