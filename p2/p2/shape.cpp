#include <string>
#include "gwindow.h"
#include "shape.h"
#include <cmath>

using namespace std;

// Implementation notes: Shape class

Shape::Shape() {
    setColor("BLACK");
}

void Shape::setLocation(double x, double y) {
    this->x = x;
    this->y = y;
}

void Shape::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Shape::setColor(const string & color) {
    this->color = color;
}

Line::Line(double x1, double y1, double x2, double y2) {
    this->x = x1;
    this->y = y1;
    this->dx = x2 - x1;
    this->dy = y2 - y1;
}

void Line::draw(GWindow & gw) {
    gw.setColor(color);
    gw.drawLine(x, y, x + dx, y + dy);
}

bool Line::contains(double x, double y) const{
    double x2 = this->x + dx;
    double y2 = this->y + dy;

    double px = x2 - this->x;
    double py = y2 - this->y;

    double norm = px*px + py*py;
    double u = ((x - this->x) * px + (y - this->y) * py) / norm;

    if (u > 1) u = 1;
    if (u < 0) u = 0;

    double x_proj = this->x + u * px;
    double y_proj = this->y + u * py;

    double dx = x_proj - x;
    double dy = y_proj - y;

    double dist = sqrt(dx*dx + dy*dy);

    return dist <= 0.5;
    
}

Square::Square(double x, double y, double size) {
    this->x = x;
    this->y = y;
    this->size = size;
}

void Square::draw(GWindow & gw) {
    gw.setColor(color);
    gw.fillRect(x, y, size, size);
}

bool Square::contains(double x, double y) const {
    return x >= this->x && x <= this->x + size &&
           y >= this->y && y <= this->y + size;
}

Rect::Rect(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::draw(GWindow& gw) {
    gw.setColor(color);
    gw.fillRect(x, y, width, height);
}

bool Rect::contains(double x, double y) const{
    return x >= this->x && x <= this->x + width &&
           y >= this->y && y <= this->y + height;
}

Oval::Oval(double x, double y, double width, double height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Oval::draw(GWindow& gw) {
    gw.setColor(color);
    gw.fillOval(x, y, width, height);
}

bool Oval::contains(double x, double y) const{
    double h = this->x + width/2;
    double k = this->y + height/2;
    double a = width/2;
    double b = height/2;

    return ((x - h)*(x - h)/(a*a) + (y - k)*(y - k)/(b*b)) <= 1;
}
/*
int main() {
    GWindow window;  

    Line line(10, 10, 200, 200);
    Square square(50, 50, 100);
    Rect rect(300, 50, 100, 200);
    Oval oval(500, 50, 150, 100);


    line.draw(window);
    square.draw(window);
    rect.draw(window);
    oval.draw(window);


    bool lineContains = line.contains(50, 50);
    bool squareContains = square.contains(70, 70);
    bool rectContains = rect.contains(310, 70);
    bool ovalContains = oval.contains(510, 70);


    cout << "Line contains (50, 50): " << (lineContains ? "True" : "False") << endl;
    cout << "Square contains (70, 70): " << (squareContains ? "True" : "False") << endl;
    cout << "Rect contains (310, 70): " << (rectContains ? "True" : "False") << endl;
    cout << "Oval contains (510, 70): " << (ovalContains ? "True" : "False") << endl;

    return 0;
}
*/