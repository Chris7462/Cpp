#include <iostream>
#include "Set.h"

int main(){
  Set<int> foo;
  Set<int> ifoo(5,3);

  ifoo.print();

  std::cout << ifoo << std::endl;

  Set<double> bar;
  Set<double> dbar(2.4,6);

  dbar.print();

  std::cout << dbar << std::endl;

  return 0;
}
