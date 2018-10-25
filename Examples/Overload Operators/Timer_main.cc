#include <iostream>
#include "Timer.h"

using namespace std;

int main(){
  Timer foo;
  foo = foo + 100;
  cout << foo << endl;

  foo = 100 + foo;
  cout << foo << endl;

  for ( int i = 0 ; i < 100 ; ++i ){
    cout << ++foo << endl;
  }

  foo = 10;
  for ( int i = 0 ; i <= 10 ; ++i ){
    cout << foo-- << endl;
  }

  return 0;
}
