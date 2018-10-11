#include <iostream>
#include "Inherit.h"

int main(){

  int a=3, b=2;

  B bar;

  std::cout << bar.cubic(a) << std::endl;
  std::cout << bar.square(a) << std::endl;
//std::cout << bar.abs(a) << std::endl;


  C foo;

  std::cout << foo.cubic(a) << std::endl;
  std::cout << foo.square(a) << std::endl;
//std::cout << foo.abs(a) << std::endl; // wrong can't call the protected function in class A

  std::cout << foo.abs_sum(a,b) << std::endl;
  std::cout << foo.square_sum(a,b) << std::endl;
  std::cout << foo.cubic_sum(a,b) << std::endl;

  return 0;
}
