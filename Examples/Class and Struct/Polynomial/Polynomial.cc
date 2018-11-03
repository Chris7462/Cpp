#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
  Polynomial foo;
  foo.print();

  int d = 3;
  double coef[d+1] = {1,-2,3,-4};
  //double coef[d+1] = {4,-3,2,-1};

  Polynomial bar(coef,d);
  bar.print();
  cout << bar.value(3) << endl;

  bar.derivative().print();
  bar.intergal().print();

  cout << bar.intergal(1,2) << endl;

  return 0;
}
