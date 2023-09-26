
/*
* File: shapelist.h
* -----------------
* This file defines a ShapeList class that maintains a list of shapes.
*/
#ifndef _shapelist_h
#define _shapelist_h
#include "gwindow.h"
#include "shape.h"
/*
* Class: ShapeList
* ----------------
* This class is a vector of shapes arrached from back to front. The
* individual elements of the ShapeList are pointers to Shape objects.
*/
class ShapeList : public Vector<Shape *> {
public:
/*
* Methods: moveToFront, moveToBack, moveForward, moveBackward
* Usage: shapes.moveToFront(sp);
* shapes.moveToBack(sp);
* shapes.moveForward(sp);
* shapes.moveBackward(sp);
* --------------------------------
* Changes the position of sp in the ShapeList. The first two methods
* move the shape all the way to the specified end. The last two move
* it one position in the indicated direction, if possible. The method
* signals an error if sp is not in the ShapeList.
*/
void moveToFront(Shape *sp);
void moveToBack(Shape *sp);
void moveForward(Shape *sp);
void moveBackward(Shape *sp);
/*
* Method: draw
* Usage: shapes.draw(gw);
* -------------------------
* Draws the shapes in the ShapeList on the graphics window. The shapes
* are drawn from back to front, so that shapes closer to the front seem
* to cover those further back.
*/
void draw(GWindow & gw) const;
};
#endif
