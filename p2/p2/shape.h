#ifndef SHAPE_H
#define SHAPE_H

#include "gwindow.h"
#include <string>

class Shape {
public:
    virtual void setLocation(double x, double y);
    virtual void move(double x, double y);
    virtual void setColor(const std::string& color);
    virtual void draw(GWindow& gw) = 0;
    virtual bool contains(double x, double y) const= 0;

protected:
    Shape();
    std::string color;
    double x, y;
};

class Line : public Shape {
public:
    Line(double x1, double y1, double x2, double y2);
    virtual void draw(GWindow& gw);
    virtual bool contains(double x, double y) const ;
private:
    double dx;
    double dy;
};


class Square : public Shape {
public:
    // Constructor for Square which takes x, y coordinates of the upper left corner and size
    Square(double x, double y, double size);
    virtual void draw(GWindow& gw);
    virtual bool contains(double x, double y) const ; 

private:
    // Side length of the square
    double size;
};

class Rect : public Shape {
public:
    // Constructor for Rect which takes x, y coordinates of the upper left corner and size
    Rect(double x, double y, double width, double height);
    virtual void draw(GWindow& gw);
    virtual bool contains(double x, double y) const ;

private:
    // Side length of the square
    double width;
    double height;
};

class Oval : public Shape {
public:
    // Constructor for Oval which takes x, y coordinates of the upper left corner and size
    Oval(double x, double y, double width, double height);
    virtual void draw(GWindow& gw);
    virtual bool contains(double x, double y) const ;
private:
    // Side length of the square
    double width;
    double height;
}; 

#endif // SHAPE_H
