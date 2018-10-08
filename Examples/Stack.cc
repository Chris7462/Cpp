#include <iostream>
#include "Stack.h"

int main(){

  int i;
  Stack foo;
  cout << foo.empty() << endl;

  for ( i = 0 ; i < 10 ; ++i ){
    foo.push(i);
  }

  cout << foo.empty() << endl;
  cout << foo.size() << endl;

  foo.pop();

  foo.top() += 10;
  cout << foo.top() << endl;

  return 0;
}
