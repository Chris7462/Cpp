#include <iostream>

using namespace std;

int& f(int& a){
  return a;
}

int main(){

  int a = 3;
  int b = 5;

  cout << f(a) << endl;

  f(a) = b;
  cout << b << endl;
  b = 4;
  cout << a << endl;


  int c = 3;
  int d = 5;

  c = d;
  cout << d << endl;
  d = 4;
  cout << c << endl;

  return 0;
}
