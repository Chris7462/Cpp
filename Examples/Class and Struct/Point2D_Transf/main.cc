#include <iostream>
#include <string>
#include <sstream>
#include "transf.h"

int main()
{
  Point point;
  std::vector<Geometric_Transformation*> gt;

  int i, no;
  Distance dx, dy;
  Angle angle;

  std::string line, transformation;
  std::istringstream istr;

  do {
    std::cout << "Enter point, transf no, transf ways:" << std::endl;

    getline(std::cin, line);
    istr.str(line);

    istr >> point >> no;
    std::cout << point << std::endl;

    for ( i = 0 ; i < no ; ++i ){
      istr >> transformation;

      if ( transformation == "TRA" ){
        istr >> dx >> dy;
        gt.push_back( new Translation(dx,dy) );
      } else if ( transformation == "ROT" ){
        istr >> angle;
        gt.push_back( new Rotation(angle) );
      } else if ( transformation == "REF" ){
        istr >> angle;
        gt.push_back( new Reflection(angle) );
      }
    }
    istr.clear();

    std::cout << " " << point << " --> " << point.transformation(gt) << std::endl;
  } while ( no != 0 );

  return 0;
}
