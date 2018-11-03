#include <iostream>
#include "Stack.h"

int main(){

  int i;
  Stack foo, bar;

  for ( i = 0 ; i < 10 ; ++i ){
    foo.push(i);
  }

  //bar.swap(foo);
  foo.swap(bar);
  cout << bar.empty() << endl;
  cout << foo.empty() << endl;

  cout << bar.top() << endl;
  cout << foo.top() << endl;

  //cout << foo.empty() << endl;
  //cout << foo.size() << endl;

  //foo.pop();

  //foo.top() += 10;
  //cout << foo.top() << endl;
  //cout << foo.size() << endl;

  //cout << "test" << endl;
  //Stack bar;

  //foo.swap(bar);
  //cout << foo.top() << endl;
  //cout << bar.top() << endl;

  return 0;
}
