#include <iostream>
#include "Set.h"
#include "Point2D.h"

int main(){
  Set<int> foo;
  Set<int> ifoo(5,3);

  ifoo.print();

  std::cout << ifoo << std::endl;

  Set<double> bar;
  Set<double> dbar(2.4,6);

  dbar.print();

  std::cout << dbar << std::endl;

  Point2D<int> qoo(3,5);
  std::cout << qoo << std::endl;

  Set<Point2D<int>> baz(qoo,2);
  std::cout << baz << std::endl;

  return 0;
}
