#include <iostream>

int main()
{
  int foo[2][3] = {{1,2,3},{4,5,6}};
  int (*ptr)[3] = foo;

  return 0;
}
