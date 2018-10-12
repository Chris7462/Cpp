#include <iostream>
#include "Queue_dyn.h"

using namespace std;

int main(){

  Queue foo, bar;
//cout << foo.empty() << endl;

  foo.push(1);
  foo.push(2);
  foo.push(3);
  foo.pop();
  foo.push(4);
  foo.push(5);

  bar.push(11);
  bar.push(12);
  bar.push(13);
  bar.pop();

  cout << foo.front() << endl;
  cout << foo.back() << endl;
  cout << foo.size() << endl;

  cout << bar.front() << endl;
  cout << bar.back() << endl;
  cout << bar.size() << endl;

  bar.swap(foo);

  cout << foo.front() << endl;
  cout << foo.back() << endl;
  cout << foo.size() << endl;

  cout << bar.front() << endl;
  cout << bar.back() << endl;
  cout << bar.size() << endl;

  return 0;
}
