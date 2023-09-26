/*
 * File: gwindow.h
 * ---------------
 * This file defines the GWindow class which supports drawing graphical
 * objects on the screen.
 */

#ifndef _gwindow_h
#define _gwindow_h

#include <string>
#include "gtypes.h"
#include "vector.h"
class GCompound;
class GInteractor;
class GLabel;
class GObject;

/*
 * Friend type: GWindowData
 * ------------------------
 * This block contains all data pertaining to the window.  Shallow copying
 * of the GWindow object ensures that all copies refer to the same onscreen
 * window.
 */

struct GWindowData {
   double windowWidth;
   double windowHeight;
   std::string windowTitle;
   std::string color;
   bool visible;
   GCompound *top;
};

/*
 * Class: GWindow
 * --------------
 * This class represents a graphics window that supports simple graphics. 
 * Each GWindow consists of two layers.  The background layer provides a
 * surface for drawing static pictures that involve no animation. 
 * Graphical objects drawn in the background layer are persistent and do
 * not require the client to update the contents of the window.  The
 * foreground layer contains graphical objects that are redrawn as
 * necessary.
 *
 * The GWindow class includes several methods that draw lines, rectangles,
 * and ovals on the background layer without making use of the facilities
 * of the gobjects.h interface.  For example, the following program draws a
 * diamond, rectangle, and oval at the center of the window.
 *
 *    int main() {
 *       GWindow gw;
 *       cout << "This program draws a diamond, rectangle, and oval." << endl;
 *       double width = gw.getWidth();
 *       double height = gw.getHeight();
 *       gw.drawLine(0, height / 2, width / 2, 0);
 *       gw.drawLine(width / 2, 0, width, height / 2);
 *       gw.drawLine(width, height / 2, width / 2, height);
 *       gw.drawLine(width / 2, height, 0, height / 2);
 *       gw.setColor("BLUE");
 *       gw.fillRect(width / 4, height / 4, width / 2, height / 2);
 *       gw.setColor("GRAY");
 *       gw.fillOval(width / 4, height / 4, width / 2, height / 2);
 *       return 0;
 *    }
 *
 * A GWindow object may be freely copied, after which all copies refer to
 * the same window.
 */

class GWindow {

public:

/*
 * Constructor: GWindow
 * Usage: GWindow gw;
 *        GWindow gw(width, height);
 * ---------------------------------
 * Creates a window, either of the specified size or a default size.
 */

   GWindow();
   GWindow(double width, double height);

/*
 * Destructor: ~GWindow
 * --------------------
 * Reclaims the internal storage for the window.  Note that the window is
 * not closed by this operation, but persists until it is closed by the
 * client or the user exits the program.
 */

   virtual ~GWindow();

/*
 * Method: close
 * Usage: gw.close();
 * ------------------
 * Deletes the window from the screen.
 */

   void close();

/*
 * Method: requestFocus
 * Usage: gw.requestFocus();
 * -------------------------
 * Asks the system to assign the keyboard focus to the window, which brings
 * it to the top and ensures that key events are delivered to the window. 
 * Clicking in the window automatically requests the focus.
 */

   void requestFocus();

/*
 * Method: clear
 * Usage: gw.clear();
 * ------------------
 * Clears the contents of the window.
 */

   void clear();

/*
 * Method: setVisible
 * Usage: gw.setVisible(flag);
 * ---------------------------
 * Determines whether the window is visible on the screen.
 */

   void setVisible(bool flag);

/*
 * Method: isVisible
 * Usage: if (gw.isVisible()) ...
 * ------------------------------
 * Tests whether the window is visible.
 */

   bool isVisible();

/*
 * Method: drawLine
 * Usage: gw.drawLine(p0, p1);
 *        gw.drawLine(x0, y0, x1, y1);
 * -----------------------------------
 * Draws a line connecting the specified points.
 */

   void drawLine(const GPoint & p0, const GPoint & p1);
   void drawLine(double x0, double y0, double x1, double y1);

/*
 * Method: drawPolarLine
 * Usage: GPoint p1 = gw.drawPolarLine(p0, r, theta);
 *        GPoint p1 = gw.drawPolarLine(x0, y0, r, theta);
 * ------------------------------------------------------
 * Draws a line of length r in the direction theta from the initial point. 
 * The angle theta is measured in degrees counterclockwise from the +x
 * axis.  The method returns the end point of the line.
 */

   GPoint drawPolarLine(const GPoint & p0, double r, double theta);
   GPoint drawPolarLine(double x0, double y0, double r, double theta);

/*
 * Method: drawOval
 * Usage: gw.drawOval(bounds);
 *        gw.drawOval(x, y, width, height);
 * ----------------------------------------
 * Draws the frame of a oval with the specified bounds.
 */

   void drawOval(const GRectangle & bounds);
   void drawOval(double x, double y, double width, double height);

/*
 * Method: fillOval
 * Usage: gw.fillOval(bounds);
 *        gw.fillOval(x, y, width, height);
 * ----------------------------------------
 * Fills the frame of a oval with the specified bounds.
 */

   void fillOval(const GRectangle & bounds);
   void fillOval(double x, double y, double width, double height);

/*
 * Method: drawRect
 * Usage: gw.drawRect(bounds);
 *        gw.drawRect(x, y, width, height);
 * ----------------------------------------
 * Draws the frame of a rectangle with the specified bounds.
 */

   void drawRect(const GRectangle & bounds);
   void drawRect(double x, double y, double width, double height);

/*
 * Method: fillRect
 * Usage: gw.fillRect(bounds);
 *        gw.fillRect(x, y, width, height);
 * ----------------------------------------
 * Fills the frame of a rectangle with the specified bounds.
 */

   void fillRect(const GRectangle & bounds);
   void fillRect(double x, double y, double width, double height);

/*
 * Method: setColor
 * Usage: gw.setColor(color);
 * --------------------------
 * Sets the color used for drawing.  The color parameter is usually one of
 * the predefined color names:
 *
 *    BLACK,
 *    BLUE,
 *    CYAN,
 *    DARK_GRAY,
 *    GRAY,
 *    GREEN,
 *    LIGHT_GRAY,
 *    MAGENTA,
 *    ORANGE,
 *    PINK,
 *    RED,
 *    WHITE, and
 *    YELLOW.
 *
 * The case of the individual letters in the color name is ignored, as are
 * spaces and underscores, so that the color DARK_GRAY can be written as
 * "Dark Gray".
 *
 * The color can also be specified as a string in the form "#rrggbb" where
 * rr, gg, and bb are pairs of hexadecimal digits indicating the red,
 * green, and blue components of the color.
 */

   void setColor(std::string color);
   void setColor(int color);

/*
 * Method: getColor
 * Usage: string color = gw.getColor();
 * ------------------------------------
 * Returns the current color as a string in the form "#rrggbb".  In this
 * string, the values rr, gg, and bb are two-digit hexadecimal values
 * representing the red, green, and blue components of the color,
 * respectively.
 */

   std::string getColor();

/*
 * Method: getWidth
 * Usage: double width = gw.getWidth();
 * ------------------------------------
 * Returns the width of the graphics window in pixels.
 */

   double getWidth();

/*
 * Method: getHeight
 * Usage: double height = gw.getHeight();
 * --------------------------------------
 * Returns the height of the graphics window in pixels.
 */

   double getHeight();

/*
 * Method: repaint
 * Usage: gw.repaint();
 * --------------------
 * Schedule a repaint on this window.
 */

   void repaint();

/*
 * Method: setWindowTitle
 * Usage: gw.setWindowTitle(title);
 * --------------------------------
 * Sets the title of the graphics window.
 */

   void setWindowTitle(std::string title);

/*
 * Method: getWindowTitle
 * Usage: string title = gw.getWindowTitle();
 * ------------------------------------------
 * Returns the title of the graphics window.
 */

   std::string getWindowTitle();

/*
 * Method: draw
 * Usage: gw.draw(gobj);
 *        gw.draw(gobj, x, y);
 * ---------------------------
 * Draws the GObject on the background layer.  For convenience, the gobj
 * parameter may be passed either as a constant reference or as a pointer. 
 * If the x and y parameters are included, the object is moved to that
 * location before drawing.
 */

   void draw(const GObject & gobj);
   void draw(GObject *gobj);
   void draw(const GObject *gobj);
   void draw(GObject & gobj, double x, double y);
   void draw(GObject *gobj, double x, double y);

/*
 * Method: add
 * Usage: gw.add(gobj);
 *        gw.add(gobj, x, y);
 * --------------------------
 * Adds the GObject to the foreground layer of the window.  The second form
 * of the call sets the location of the object to (x, y) first.
 *
 * In terms of memory management, adding a GObject pointer to a GWindow
 * transfers control of that object from the client to the window manager. 
 * Deleting a GWindow automatically deletes any GObjects it contains.
 */

   void add(GObject *gobj);
   void add(GObject *gobj, double x, double y);

/*
 * Method: remove
 * Usage: gw.remove(gobj);
 * -----------------------
 * Removes the object from the window.
 */

   void remove(GObject *gobj);

/*
 * Method: addToRegion
 * Usage: gw.addToRegion(interactor, region);
 * ------------------------------------------
 * Adds the interactor (which can also be a GLabel) to the control strip
 * specified by the region parameter.  The region parameter must be one of
 * the strings "NORTH", "EAST", "SOUTH", or "WEST".
 */

   void addToRegion(GInteractor *gobj, std::string region);
   void addToRegion(GLabel *gobj, std::string region);

/*
 * Method: removeFromRegion
 * Usage: gw.removeFromRegion(interactor, region);
 * -----------------------------------------------
 * Adds the interactor (which can also be a GLabel) to the control strip
 * specified by the region parameter.  The region parameter must be one of
 * the strings "NORTH", "EAST", "SOUTH", or "WEST".
 */

   void removeFromRegion(GInteractor *gobj, std::string region);
   void removeFromRegion(GLabel *gobj, std::string region);

/*
 * Method: getGObjectAt
 * Usage: GObject *gobj = getGObjectAt(x, y);
 * ------------------------------------------
 * Returns a pointer to the topmost GObject containing the point (x, y), or
 * NULL if no such object exists.
 */

   GObject *getGObjectAt(double x, double y);

/*
 * Method: setRegionAlignment
 * Usage: gw.setRegionAlignment(region, align);
 * --------------------------------------------
 * Sets the alignment of the specified side region as specified by the
 * string align.  The region parameter must be one of the strings "NORTH",
 * "EAST", "SOUTH", or "WEST" and the align parameter must be "LEFT",
 * "RIGHT", or "CENTER".  By default, side panels use CENTER alignment.
 */

   void setRegionAlignment(std::string region, std::string align);

/*
 * Operator: ==
 * Usage: if (w1 == w2) ...
 * ------------------------
 * Checks whether the two objects refer to the same window.
 */

   bool operator==(GWindow w2);

/*
 * Operator: !=
 * Usage: if (w1 != w2) ...
 * ------------------------
 * Checks whether the two objects refer to different windows.
 */

   bool operator!=(GWindow w2);

/* Private section */

/**********************************************************************/
/* Note: Everything below this point in the file is logically part    */
/* of the implementation and should not be of interest to clients.    */
/**********************************************************************/

   explicit GWindow(bool visible);
   GWindow(double width, double height, bool visible);
   GWindow(GWindowData *gwd);

private:

/* Instance variables */

   GWindowData *gwd;

/* Private methods */

   void initGWindow(double width, double height, bool visible);

   friend class Platform;
   friend class GKeyEvent;
   friend class GMouseEvent;
   friend class GWindowEvent;

};

/*
 * Function: repaint
 * Usage: repaint();
 * -----------------
 * Issues a request to update all graphics windows.  This function is
 * called automatically when the program pauses, waits for an event, waits
 * for user input on the console, or terminates.  As a result, most clients
 * never need to call repaint explicitly.
 */

void repaint();

/*
 * Function: pause
 * Usage: pause(milliseconds);
 * ---------------------------
 * Pauses for the indicated number of milliseconds.  This function is
 * useful for animation where the motion would otherwise be too fast.
 */

void pause(double milliseconds);

/*
 * Function: getScreenWidth
 * Usage: width = getScreenWidth();
 * --------------------------------
 * Returns the width of the entire display screen.
 */

double getScreenWidth();

/*
 * Function: getScreenHeight
 * Usage: height = getScreenHeight();
 * ----------------------------------
 * Returns the height of the entire display screen.
 */

double getScreenHeight();

/*
 * Function: convertColorToRGB
 * Usage: int rgb = convertColorToRGB(colorName);
 * ----------------------------------------------
 * Converts a color name into an integer that encodes the red, green, and
 * blue components of the color.
 */

int convertColorToRGB(std::string colorName);

/*
 * Function: convertRGBToColor
 * Usage: int colorName = convertRGBToColor(rgb);
 * ----------------------------------------------
 * Converts an rgb value into a color name in the form "#rrggbb".  Each of
 * the rr, gg, and bb values are two-digit hexadecimal numbers indicating
 * the intensity of that component.
 */

std::string convertRGBToColor(int rgb);

/*
 * Function: waitForClick
 * Usage: waitForClick();
 * ----------------------
 * Waits for a mouse click to occur anywhere in any window.
 */

void waitForClick();

/*
 * Function: exitGraphics
 * Usage: exitGraphics();
 * ----------------------
 * Closes all graphics windows and exits from the application without
 * waiting for any additional user interaction.
 */

void exitGraphics();

#include "console.h"

#endif