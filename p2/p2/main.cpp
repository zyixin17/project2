//
//  main.cpp
//  p2
//
//  Created by Yixin Zhang on 2023/9/25.
//

#include <iostream>

//#include "../../StanfordCPPLib/graphics/gwindow.h"
//#include "../../stanford-cpp-library-master/StanfordCPPLib/graphics/gwindow.h"
//#include "../../stanford-cpp-library-master/cpplib_old_eroberts/cpplib/include/gwindow.h"
#include "gwindow.h"

   int main() {
      GWindow gw;
      std::cout << "This program draws a diamond, rectangle, and oval." << std::endl;
      double width = gw.getWidth();
      double height = gw.getHeight();
      gw.drawLine(0, height / 2, width / 2, 0);
      gw.drawLine(width / 2, 0, width, height / 2);
      gw.drawLine(width, height / 2, width / 2, height);
      gw.drawLine(width / 2, height, 0, height / 2);
      gw.setColor("BLUE");
      gw.fillRect(width / 4, height / 4, width / 2, height / 2);
      gw.setColor("GRAY");
      gw.fillOval(width / 4, height / 4, width / 2, height / 2);
      return 0;
   }
