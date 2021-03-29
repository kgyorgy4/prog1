/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
{
    Lines_window win {Point{100,100}, 1000, 600, "Lines"};
    
    return gui_main();
}