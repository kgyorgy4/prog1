#include "Graph.h"
#include "Simple_window.h"

namespace dussz
{
    struct Rechtangle : Shape {
        Rechtangle(Point topleft, int width, int height): m_width(width), m_height(height) {
            add(topleft);
        }
        Rechtangle(Point topleft, Point botttomright):
        m_width(botttomright.x-topleft.x), m_height(botttomright.y-topleft.y) {
add(topleft);
        }
    
    void draw_lines() const {
if (fill_color().visibility()){
fl_color(fill_color().as_int());
fl_rectf(point(0).x, point(0).y,m_width,m_height);
fl_color(color().as_int());
}
if (color().visibility()){
    fl_color(color().as_int());
fl_rect(point(0).x, point(0).y,m_width,m_height);

}

    }
    int get_width() const {
        return m_width;
    }
    int get_height() const {

        return m_height;
    }
    
    private:
    int m_width;
    int m_height;
    };
   
    template<class T>
    class vector_ref {
public:
vector_ref() {}
vector_ref(T *elem){
if (elem)
push_back(elem);


}


~Vector_ref(){
for (int i=0; i<owned.size();++i)
delete owned[i];

}

void push_back(T *elem) {
elements.push_back(elem);
owned.push_back(elem);

}
void push_back(T &elem){
elements.push_back(&elem);

}
T &operator[](int i){
return *elements[i];

}
const T&operator[](int i) const{
    return *elements[i];

}

int size() const {
return elements.size();

}

private:
std::vector<T *> elements;
std::vector<T *> owned;
    };

    
    
    
} // namespace düssz


int main() {
Simple_window win {{0,0}, 1200, 800, "valami"};
dussz::Rechtangle rect{{0,0},400,600 };
rect.set_fill_color(Color::dark_magenta);
rect.move(100,20);
win.attach(rect);
win.wait_for_button();
}