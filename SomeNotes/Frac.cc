#include <iostream>
#include "Frac.h"

using namespace std;

int main(){
  
  /* Constructor */
  Frac a(3,-2), b(2), c, d=c; // d(c);
  cout << "There are " << Frac::obj_no() << " objects in the set" << endl;

  /* io operator overload */
  cout << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl << "d = " << d << endl;
//cout << "Input a frac number" << endl;
//Frac e;
//cin >> e;
//cout << e << endl;

  /* operators */
  c = a;
  cout << "c = a: " << c << endl;
  c = b;
  cout << "c = b: " << c << endl;

  c = a+b;
  cout << "c = a+b: " << c << endl;
  
  c = a-b;
  cout << "c = a-b: " << c << endl;
  
  c = a*b;
  cout << "c = a*b: " << c << endl;

  c = a/b;
  cout << "c = a/b: " << c << endl;

  c += b;
  cout << "c += b: " << c << endl;

  c -= a;
  cout << "c -= a: " << c << endl;

  c *= a;
  cout << "c *= a: " << c << endl;

  c /= a;
  cout << "c /= a: " << c << endl;

  cout << "-c : " << -c << endl;

  cout << "c == a ? " << (c==a) << endl;

  cout << "c < a ? " << (c<a) << endl;

  cout << "c > a ? " << (c>a) << endl;

  cout << "c != a ? " << (c!=a) << endl;

  cout << "c <= a ? " << (c<=a) << endl;

  cout << "c >= a ? " << (c>=a) << endl;

  cout << "++c : " << ++c << endl;

  cout << "c++ : " << c++ << " => " << c << endl;

  cout << "--c : " << --c << endl;

  cout << "c-- : " << c-- << " => " << c << endl;

  cout << "static_cast<int>(c) : " << static_cast<int>(c) << endl;

  cout << "static_cast<double>(c) : " << static_cast<double>(c) << endl;

  return 0;
}
