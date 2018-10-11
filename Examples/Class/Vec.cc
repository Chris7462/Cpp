#include <iostream>
#include "Vec.h"

int main(){

  /* constructor */
  Vec a(3,2), b(2), c, d(b);
  
  /* io operator overload */
  std::cout << "a(3,2) = " << a << std::endl;
  std::cout << "b(2) = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d(b) = " << d << std::endl;
//std::cin >> b;
//std::cout << b << std::endl;

  const Vec e(3,4);
  std::cout << "e(3,4) = " << e << std::endl;
  std::cout << "a[2] = " << a[2] << std::endl;
  std::cout << "e[1] = " << e[1] << std::endl;

  c = a+e;
  std::cout << "c = a+e : " << c << std::endl;

  c = a-e;
  std::cout << "c = a-e : " << c << std::endl;

  std::cout << "a*c = " << a*c << std::endl;

  Vec vec[2] = {a,c};

  vec[1][1] = 2;
  std::cout << "vec[1][1] = " << vec[1].operator[](1) << std::endl;

  std::cout << "vec[0] = " << vec[0] << std::endl;
  std::cout << "vec[1] = " << vec[1] << std::endl;
  std::cout << "vec[0]*vec[1] = " << vec[0]*vec[1] << std::endl;

  return 0;
}
