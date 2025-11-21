/*
 * Author: Matthew Lepis
 * Date:   11/21/2025
 *
 * Description:
 *   Implements an object-oriented geometric drawing system in C++ using an
 *   abstract base class (`Shape`) and multiple derived classes (`Circle`,
 *   `Rect`, `FilledRect`). This program demonstrates polymorphism,
 *   inheritance, dynamic dispatch, and resource management through virtual
 *   destructors and heap-allocated shape objects.
 *
 *   The system outputs PostScript commands to generate a vector-graphics
 *   drawing containing circles and rectangles (both stroked and filled).
 *   It also computes and displays the area of each shape using overridden
 *   `area()` functions.
 *
 *   Features:
 *     • Fully abstract base class `Shape` with:
 *         – Pixel-position data stored as a `Position` struct.
 *         – Pure virtual functions `area()` and `draw()`.
 *         – Virtual destructor for safe polymorphic cleanup.
 *
 *     • Derived classes:
 *         – `Circle`
 *             ▪ Stores a radius and outputs PostScript arc commands.
 *             ▪ Computes area using πr².
 *         – `Rect`
 *             ▪ Draws via PostScript moveto/lineto/closepath + stroke.
 *             ▪ Computes area as width × height.
 *         – `FilledRect`
 *             ▪ Same geometry as `Rect` but ends with a PostScript `fill`.
 *             ▪ Computes area identically to the regular rectangle.
 *
 *     • `Drawing` class:
 *         – Maintains an `ofstream` and a vector of `Shape*` for
 *           polymorphic handling.
 *         – Provides methods to add shapes, draw them, set RGB color,
 *           and display areas to stdout.
 *         – Destructor automatically deallocates all shapes to prevent
 *           memory leaks.
 *
 *   The main() function:
 *     • Creates a PostScript output file (`/test.ps`).
 *     • Sets drawing color via `setRGB()`.
 *     • Adds one `FilledRect`, one `Rect`, and one `Circle`.
 *     • Calls `draw()` to write all PostScript instructions to file.
 *     • Calls `showArea()` to print areas for each shape.
 *     • Demonstrates polymorphism through virtual function calls on
 *       a heterogeneous collection of shape pointers.
 *
 *   Notes / Assumptions:
 *     • All shapes are stored as raw pointers but are safely cleaned up by
 *       `Drawing`’s destructor using RAII principles.
 *     • Output strictly follows PostScript syntax required by the assignment.
 *     • The `Position` struct improves readability and enforces units (pixels).
 *     • No exception safety for file I/O beyond a simple open-check, which
 *       suffices for the assignment scope.
 *
 *   References:
 *     • EE553 Homework 7: Shape Hierarchy and PostScript Drawing System.
 *     • PostScript arc/moveto/lineto documentation and provided class template.
 *     • PostScript render tested performed with https://ehubsoft.herokuapp.com/psviewer/
 */


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    Shape(double in_pos_x, double in_pos_y)
        : position { in_pos_x, in_pos_y }
    {
    } // ctor using initializer list
    virtual ~Shape() = default;

    virtual double area() const = 0; // Pure virtual since this is set equal to zero.
    virtual void draw(ostream& file) const = 0; // Pure virtual since this is set equal to zero.

    Position getPosition() const
    {
        return position;
    }
    virtual string getShapeType() const = 0;
};

class Circle : public Shape
{
private:
    double radius; // Units: pixels
    string shapeType = "Circle";

public:
    Circle(double in_pos_x, double in_pos_y, double in_radius)
        : Shape(in_pos_x, in_pos_y)
        , radius(in_radius)
    {
    }
    ~Circle() = default;

    string getShapeType() const override
    {
        return "Circle";
    }

    double area() const override
    {
        return PI * radius * radius;
    }

    void draw(ostream& file) const override
    {
        Position position = getPosition();

        file << position.x << " " << position.y << " " << radius << " 0 360 arc\n";
        file << "stroke\n";
    }
};

class Rect : public Shape
{
private:
    double width, height;
    string shapeType = "Rectangle";

public:
    Rect(double in_pos_x, double in_pos_y, double in_width, double in_height)
        : Shape(in_pos_x, in_pos_y)
        , width(in_width)
        , height(in_height)
    {
    }
    ~Rect() = default;

    string getShapeType() const override
    {
        return "Rectangle";
    }

    double area() const override
    {
        return width * height;
    }
    void draw(ostream& file) const override
    {
        Position position = getPosition();

        file << position.x << " " << position.y << " moveto\n";
        file << position.x + width << " " << position.y << " lineto\n";
        file << position.x + width << " " << position.y + height << " lineto\n";
        file << position.x << " " << position.y + height << " lineto\n";
        file << "closepath\n";
        file << "stroke\n";
    }
};

class FilledRect : public Shape
{
private:
    double width, height;
    string shapeType = "Filled Rectangle";

public:
    FilledRect(double in_pos_x, double in_pos_y, double in_width, double in_height)
        : Shape(in_pos_x, in_pos_y)
        , width(in_width)
        , height(in_height)
    {
    }
    ~FilledRect() = default;

    string getShapeType() const override
    {
        return "Filled Rectangle";
    }

    double area() const override
    {
        return width * height;
    }
    void draw(ostream& file) const override
    {
        Position position = getPosition();

        file << position.x << " " << position.y << " moveto\n";
        file << position.x + width << " " << position.y << " lineto\n";
        file << position.x + width << " " << position.y + height << " lineto\n";
        file << position.x << " " << position.y + height << " lineto\n";
        file << "closepath\n";
        file << "fill\n";
    }
};

class Drawing
{
private:
    ofstream file;
    vector<Shape*> shapes;

public:
    Drawing(string fileName)
        : file(fileName)
        , shapes()
    {
        if (!file.is_open())
        {
            cerr << "File failed to open, check path.\n";
            exit(1);
        }
    }
    ~Drawing()
    {
        for (auto* s : shapes)
        {
            delete s;
        }
    }

    void add(Shape* shape)
    {
        shapes.push_back(shape);
    }
    void draw()
    {
        for (auto* s : shapes)
        {
            s->draw(file);
        }
    }
    void showArea() const
    {
        for (auto* s : shapes)
        {
            cout << s->getShapeType() << ": " << s->area() << "\n";
        }
    }
    void setRGB(double red, double green, double blue)
    {
        file << red << " " << green << " " << blue << " setrgbcolor\n";
    }
};

int main()
{
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // set path to create .ps file to write postscript instructions
    Drawing d("/test.ps");
    // set color
    d.setRGB(1, 0, 0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    // add FilledRect
    d.add(new FilledRect(100.0, 550.0, 200.0, 50)); // x y moveto x y lineto ... fill
    // add Rect
    d.add(new Rect(200.0, 650.0, 200.0, 50)); // x y moveto x y lineto ... stroke
    // add Circle
    d.add(new Circle(300, 300, 100)); // centered in 300 , 300 pixel with radius
    // draw all shapes added to d
    d.draw();
    // print out all shapes area
    d.showArea();

    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}