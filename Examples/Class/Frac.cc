#include <iostream>
#include "Frac.h"

int main(){
  
  /* Constructor */
  Frac a(3,-2), b(2), c, d=c; // d(c);
  std::cout << "There are " << Frac::obj_no() << " objects in the set" << std::endl;

  /* io operator overload */
  std::cout << "a = " << a << std::endl << "b = " << b << std::endl << "c = " << c << std::endl << "d = " << d << std::endl;
//std::cout << "Input a frac number" << std::endl;
//Frac e;
//cin >> e;
//std::cout << e << std::endl;

  /* operators */
  c = a;
  std::cout << "c = a: " << c << std::endl;
  c = b;
  std::cout << "c = b: " << c << std::endl;

  c = a+b;
  std::cout << "c = a+b: " << c << std::endl;
  
  c = a-b;
  std::cout << "c = a-b: " << c << std::endl;
  
  c = a*b;
  std::cout << "c = a*b: " << c << std::endl;

  c = a/b;
  std::cout << "c = a/b: " << c << std::endl;

  c += b;
  std::cout << "c += b: " << c << std::endl;

  c -= a;
  std::cout << "c -= a: " << c << std::endl;

  c *= a;
  std::cout << "c *= a: " << c << std::endl;

  c /= a;
  std::cout << "c /= a: " << c << std::endl;

  std::cout << "-c : " << -c << std::endl;

  std::cout << "c == a ? " << (c==a) << std::endl;

  std::cout << "c < a ? " << (c<a) << std::endl;

  std::cout << "c > a ? " << (c>a) << std::endl;

  std::cout << "c != a ? " << (c!=a) << std::endl;

  std::cout << "c <= a ? " << (c<=a) << std::endl;

  std::cout << "c >= a ? " << (c>=a) << std::endl;

  std::cout << "++c : " << ++c << std::endl;

  std::cout << "c++ : " << c++ << " => " << c << std::endl;

  std::cout << "--c : " << --c << std::endl;

  std::cout << "c-- : " << c-- << " => " << c << std::endl;

  std::cout << "static_cast<int>(c) : " << static_cast<int>(c) << std::endl;

  std::cout << "static_cast<double>(c) : " << static_cast<double>(c) << std::endl;

  return 0;
}
