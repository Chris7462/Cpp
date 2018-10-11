#include <iostream>

using namespace std;

struct Complex {
  double re, im;
};

int main(){

  Complex a;
  a.re = 10;
  a.im = 5;

  Complex *pa = &a;
  cout << (*pa).re << endl;
  cout << pa->im << endl;

  return 0;
}
