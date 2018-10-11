#include <iostream>
#include "Geometric.h"

int main(){

  Point o, a(1,0), b(0,1), c(1,1);
  //std::cout << o << std::endl;

  Circle circ1(o,2);
  std::cout << circ1 << std::endl;

  Triangle tri1(o,a,b);
  std::cout << tri1 << std::endl;

  Rectangle rect1(o,a,c,b);
  std::cout << rect1 << std::endl;

  return 0;
}
