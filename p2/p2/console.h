/*
 * File: console.h
 * ---------------
 * This file redirects the cin, cout, and cerr channels to use a console
 * window.  This file must be included in the source file that contains the
 * main method, although it may be included in other source files as well.
 */

#ifndef _console_h
#define _console_h

#include <string>

/*
 * Function: clearConsole
 * Usage: clearConsole();
 * ----------------------
 * Erases the contents of the console window.
 */

void clearConsole();

/*
 * Function: setConsoleFont
 * Usage: setConsoleFont(font);
 * ----------------------------
 * Changes the font used for the console.  The font parameter is typically
 * a string in the form family-style-size.  In this string, family is the
 * name of the font family; style is either missing (indicating a plain
 * font) or one of the strings Bold, Italic, or BoldItalic; and size is an
 * integer indicating the point size.  If any of these components is
 * specified as an asterisk, the existing value is retained.  The font
 * parameter can also be a sequence of such specifications separated by
 * semicolons, in which case the first available font on the system is
 * used.
 */

void setConsoleFont(const std::string & font);

/*
 * Function: setConsoleSize
 * Usage: setConsoleSize(width, height);
 * -------------------------------------
 * Changes the size of the console to the specified dimensions, measured in
 * pixels.
 */

void setConsoleSize(double width, double height);

#endif