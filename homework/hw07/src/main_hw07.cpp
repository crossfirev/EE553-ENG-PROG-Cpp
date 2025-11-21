#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

constexpr double PI = 3.14159265359;

struct Position
{
    double x;
    double y;
};

class Shape
{
private:
    Position position; // Units: pixels

public:
    Shape(double in_pos_x, double in_pos_y): position{in_pos_x, in_pos_y} {} // ctor using initializer list
    virtual ~Shape() = default;

    virtual double area() const = 0;        // Pure virtual since this is set equal to zero.
    virtual void draw(ostream& file) const = 0;   // Pure virtual since this is set equal to zero.

    Position getPosition() const
    {
        return position;
    }
    virtual string getShapeType() const = 0;
};


int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // set path to create .ps file to write postscript instructions
    Drawing d("/test.ps");
    // set color
    d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    // add FilledRect
    d.add(new FilledRect(100.0, 550.0, 200.0, 50)); // x y moveto x y lineto ... fill
    // add Rect
    d.add(new Rect(200.0, 650.0, 200.0, 50));       // x y moveto x y lineto ... stroke
    // add Circle
    d.add(new Circle(300,300, 100)); // centered in 300 , 300 pixel with radius
    // draw all shapes added to d
    d.draw();
    // print out all shapes area
    d.showArea();

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}

//please submit single c++ file (no zip file)