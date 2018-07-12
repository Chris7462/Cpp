#include <iostream>

using namespace std;

int main(){

  int foo=4;
  int &bar = foo;

  bar = foo +4;
  cout << bar << endl;
  cout << foo << endl;

  int *ptr = &foo;
  int * &q = ptr;
  cout << &q << " " << q << " " << *q << endl;
  cout << & ptr << " " << ptr << " " << *ptr << endl;

  return 0;
}
