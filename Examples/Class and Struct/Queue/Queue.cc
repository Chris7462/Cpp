#include <iostream>
#include "Queue.h"

using namespace std;

int main(){

  Queue foo, bar;
  //cout << foo.empty() << endl;

  foo.push(1);
  foo.push(2);
  foo.pop();

  bar.push(4);
  bar.push(5);
  bar.push(6);
  bar.pop();

  bar.swap(foo);

  return 0;
}
