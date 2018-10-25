#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
  Vector a, b(3,5);
  Vector c(b);

  cout << b << endl;
  cout << c << endl;

  a = b;
  cout << a << endl;

  Vector d(5,3), e(2,2);
  cout << d << endl;
  cout << e << endl;
  cout << d+e << endl;
  cout << d-e << endl;
  cout << d*e << endl;
  cout << d/e << endl;

  return 0;
}
