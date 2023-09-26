#include <iostream>
#include "gwindow.h"
#include "shape.h"
#include "vector.h"

using namespace std;

int main() {
    GWindow gw;
    double width = gw.getWidth();
    double height = gw.getHeight();

    Rect *rp = new Rect(width / 4, height / 4, width / 2, height / 2);
    Oval *op = new Oval(width / 4, height / 4, width / 2, height / 2);
    
    rp->setColor("BLUE");
    op->setColor("GRAY");

    Vector<Shape *> shapes;
    shapes.add(new Line(0, height / 2, width / 2, 0));
    shapes.add(new Line(width / 2, 0, width, height / 2));
    shapes.add(new Line(width, height / 2, width / 2, height));
    shapes.add(new Line(width / 2, height, 0, height / 2));
    shapes.add(rp);
    shapes.add(op);

    for (Shape *sp : shapes) {
        sp->draw(gw);
    }

    for (Shape *sp : shapes) {
        delete sp;
    }

    shapes.clear();

    return 0;
}
