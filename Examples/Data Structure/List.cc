#include <iostream>
#include "List.h"

using namespace std;

int main(){
  List a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_front(5);

  cout << a.node_no() << endl;
  cout << a << endl;

  a.pop_back();

  cout << a.node_no() << endl;
  cout << a << endl;

  a.pop_front();

  cout << a.node_no() << endl;
  cout << a << endl;

  //List b(a);

  //cout << b << endl;

  return 0;
}
