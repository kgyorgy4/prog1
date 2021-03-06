/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
double one(double) {return 1;}
double square(double x) {return x*x;}
int main()
{
    using namespace Graph_lib;
    int xmax = 1280;
    int ymax=720;
int x_origo = xmax/2;
int y_origo = ymax/2;
 int rmax = 11;
 int rmin =-11;
 int n_points=400;

   Simple_window win {Point {100,100}, xmax, ymax, "Canvas"};

    Point origo {x_origo, y_origo};
    
    int xlen=xmax-40;
    int ylen=ymax-40;
    int xscale=30;
    int yscale=30;
    

    Function s (one,rmin,rmax,origo,n_points,xscale,yscale);
    Function sq (square,rmin,rmax,origo,n_points,xscale,yscale);
Function cos_func ( [] (double x) { return cos(x); },
            rmin, rmax, origo, n_points, xscale, yscale);
cos_func.set_color(Color::blue);

Axis x {Axis::x, Point{20,y_origo},xlen,xlen/xscale, "x"};
    Axis y {Axis::y, Point{x_origo,ylen+20},ylen ,ylen/yscale, "y"};

Image p {Point{20,20},"badge.jpg"};

Polygon poly;
poly.add(Point(300,500));
poly.add(Point(1,700));
poly.add(Point(1200,600));
poly.set_color(Color::blue);
poly.set_style(Line_style(Line_style::dash, 5));



Rectangle r {Point{200,200},100,50 };
  r.set_fill_color(Color::yellow); 
  r.set_style(Line_style(Line_style::dash, 4));

Circle c {Point{500,500},100};
c.set_style(Line_style(Line_style::dot, 4));

Text t {Point{1200,200},"Udv!"};
t.set_font(Font::times_bold);
t.set_font_size(20);

  Ellipse e {Point{500,500}, 100, 50};
  e.set_fill_color(Color::red);
   
   win.attach(e);
   win.attach(x);
   win.attach(p);
   win.attach(y);
   win.attach(s);
   win.attach(sq);
   win.attach(r);
   win.attach(t);
   win.attach(c);
   win.attach(cos_func);
   win.attach(poly);
   
    win.wait_for_button();
}
