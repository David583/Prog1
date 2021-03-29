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

    int xmax = 1280;
    int ymax = 720;

    Simple_window win {Point{100,100}, xmax, ymax, "Sample Window"};

	class B1 {
		public:
			void f() {std::cout<<"Most a B1 nem virtualba vagyunk"<<endl;}
			void virtual vf() {std::cout<<"Most a B1 virtualba vagyunk"<<endl;}
			void virtual pvf() = 0;
	};
	class D1 : public B1 {
		public:
			void vf() override {std::cout<<"Most a D1 virtualban vagyunk"<<endl;}
			void f() {std::cout<<"Most a D1 nem virtualban vagyunk"<<endl;};
			void pvf() override {std::cout<<"Most a D1 pure virtualban vagyunk"<<endl;}
	};
	class D2 : public D1 {
		public:
			void pvf() override {std::cout<<"Most a D2 pure virtualban vagyunk"<<endl;}
	};
	class B2 {
		public:
			void virtual pvf() = 0; 
	};
	class D21 : public B2 {
		public:
			string cic;
			void pvf() override {std::cout<<cic<<endl;}
	};
	class D22 : public B2 {
		public:
			int cic;
			void pvf() override {std::cout<<cic<<endl;}
			void f(B2& lol) {lol.pvf();}
	};

	//B1 cica1;
	//cica1.f();
	//cica1.vf();
	D1 cica2;
	cica2.f();
	cica2.vf();
	B1& cica3 = cica2;
	cica3.f();
	cica3.vf();
	D2 cica4;
	cica4.f();
	cica4.vf();
	cica4.pvf();
	D22 a;
	D21 v;
	a.cic = 3;
	v.cic = "string lol";
	a.f(v);
	a.f(a);
    win.wait_for_button();
}
