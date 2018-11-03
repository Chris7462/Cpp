#include <iostream>
#include "Hotel.h"

using namespace std;

int main()
{

  Hotel foo(8);

  cout << foo.get_empty_room_no() << endl;

  return 0;
}
