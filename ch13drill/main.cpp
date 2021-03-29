/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib;

    Simple_window win(Point(100,100),800,1000,"drill13");
  win.wait_for_button();
  
  Vector_ref<Rectangle> grid;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      grid.push_back(new Rectangle(Point(i*100,j*100),100,100));
      win.attach(grid[grid.size()-1]);
    }
  }
  win.wait_for_button();
  
  Vector_ref<Rectangle> atlo;
  for(int i=0;i<8;i++)
  {
    atlo.push_back(new Rectangle(Point(i*100,i*100),100,100));
    atlo[i].set_fill_color(Color::red);
    win.attach(atlo[i]);
  }
  win.wait_for_button();
 
  Image kep1(Point(0,200),"pic.jpeg");
  Image kep2(Point(400,400),"pic.jpeg");
  Image kep3(Point(600,200),"pic.jpeg");
  win.attach(kep1);
  win.attach(kep2);
  win.attach(kep3);
  win.wait_for_button();

  Image kiskep(Point{0,0},"pic.jpeg");
  kiskep.set_mask(Point{50,50},100,100);
  win.attach(kiskep);
 win.wait_for_button();
  for(int i=1;i<8;i++)
  {
    kiskep.move(100,100);
    
     win.wait_for_button();
   }
  win.wait_for_button();
}