#include "complex.h"

using namespace std;

int main(){

  Complex a(3,2), b(2,-1), c;
  c = b = a;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  Complex d(3,2), e(2,-1), f;
  (f = e) = d;
  cout << d << endl;
  cout << e << endl;
  cout << f << endl;

  c = -c;
  cout << c << endl;

  a += b;
  cout << a << endl;

  c -= e;
  cout << c << endl;

  cout << (c==c) << endl;

  cout << ++c << endl;
  cout << --c << endl;

//Complex a(3,2), b(2,-1), c;
//a.print();  //3,2
//c = a;
//c.print();  //3,2

//c = b = a;
//a.print();  //3,2
//b.print();  //3,2
//c.print();  //3,2

//c = b+a;
//c.print();

//c = a-b;
//print2(c);

//c = 3+a;
//c.print();

//cout << "There are " << Complex::obj_no() << " complex numbers in the dataset." << endl;

//print2(c);

  return 0;
}
