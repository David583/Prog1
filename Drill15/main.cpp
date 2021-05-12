/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include <iostream>

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

struct Person {
	public:
		string fname;
		string lname;
		int age;
	Person(string n, string l, int a);
	Person() { };
};
Person::Person(string f, string l, int a) {
	this->fname = f;
	this->lname = l;
	this->age = a;
	if (a < 0 || a > 150)
		error("Invalid age!");
	string name = f + l;
	string invalid = ";:'[]*&^%$#@!";
	for (int i = 0; i < name.length; i++)
	{
		for (int j = 0; j < invalid.length; j++)
			if (name[i] == invalid[j] || name[i] == '"')
				error("Invalid character in name!");
	}
};
vector<Person> PersonList;

istream& operator >> (istream& is, Person& pers) {
	string f;
	string l;
	int x;
	is >> f >> l >> x;
	if (!is) error ("Invalid person data!");
	pers = Person(f, l ,x);
	PersonList.push_back(pers);
} 
ostream& operator << (ostream& os, Person& pers) {
	return os << pers.fname << ' ' << pers.lname << ' ' << pers.age << endl;
}

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

	
    Function grapha {one, -10, 11, {300, 300}, 400, 20, 20};
    Function graphb {slope, -10, 11, {300, 300}, 400, 20, 20};
    Function graphc {[](double x) { return x * x; }, -10, 11, {300,300}, 400, 20, 20};
    Function graphd {cos, -10, 11, {300, 300}, 400, 20, 20};
    graphd.set_color(Color::blue);
    Function graphe {[](double x) { return cos(x) + slope(x); }, -10, 11, {300, 300}, 400, 20, 20};

	win.attach(x);
	win.attach(y);
	win.attach(grapha);
	win.attach(graphb);
	win.attach(graphc);
	win.attach(graphd);
	win.attach(graphe);
	Person Goofy("Goofy", "", 63);
	cout << "Write person data. Terminate with 'stop'" << endl;
	while (true) {
		Person p;
		cin >> p;
		if (p.fname == "stop")
			break;
		PersonList.push_back(p);
	}
	for (Person p : PersonList)
		cout << p << endl;

    win.wait_for_button();
}
