/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


double one (double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x) {return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{
	using namespace Graph_lib;

	Simple_window win(Point(100,100),600,600,"Function graphs");
	int xorig=300;
	int yorig=300;
	Axis x(Axis::x,Point{100,yorig},400,400/20,"1 = = 20 pixels");
	Axis y(Axis::y,Point{xorig,400+100},400,400/20,"1 = = 20 pixels");
	win.attach(x);
	win.attach(y);
	x.set_color(Color::red);
	y.set_color(Color::red);
	
	int minrange=-10;
	int maxrange=11;	
	Point origo{xorig,yorig};
	Function f_one(one,minrange,maxrange,origo,400);
	win.attach(f_one);
		
	int xscale=20;
	int yscale=20;	
	Function f_slope(slope,minrange,maxrange,origo,400,xscale,yscale);
		win.attach(f_slope);
	

	
	Text slope_label(Point{90,390},"x/2");
	win.attach(slope_label);
	


	Function f_square(square,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_square);

	Function f_cos(cos,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_cos);

	f_cos.set_color(Color::blue);

	Function f_slopingcos(sloping_cos,minrange,maxrange,origo,400,xscale,yscale);
	win.attach(f_slopingcos);
	win.wait_for_button();
}	
