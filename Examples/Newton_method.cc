#include <iostream>
#include <cmath>

int main(){
  const double SMALL = 1.0E-10;
  double a, b, n, err;
  std::cin >> n;

  a = 10.;
  do {
    //b = 0.5*(a+n/a);
    b = 4.0/5.0*a+n/(5*a*a*a*a);
    err = std::abs(a-b);
    a = b;
  } while (err>SMALL);

  std::cout << b << std::endl;

  return 0;
}
