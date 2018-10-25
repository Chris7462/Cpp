#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  List a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  cout << a << endl;

  //a.push_front(4);
  a.push_front(4);
  cout << a << endl;

  a.pop_back();
  cout << a << endl;
  cout << a.node_no() << endl;

  a.pop_front();
  cout << a << endl;

  a.pop_front();
  cout << a << endl;

  cout << a.node_no() << endl;
  return 0;
}
