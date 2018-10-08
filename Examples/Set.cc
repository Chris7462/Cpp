#include <iostream>
#include "Set.h"

int main()
{
  Set foo, bar(3), qoo(2,4);
  foo.print_set();
  bar.print_set();
  qoo.print_set();

  foo.initialization();

  // insert element
  foo.insert_element(3);
  foo.insert_element(1);
  foo.insert_element(3);
  foo.insert_element(3);

  foo.print_set();

  // delete element
  //foo.delete_element(3);
  foo.print_set();

  Set *ptr = new Set(7);
  ptr->print_set();
  Set set(*ptr);
  set.print_set();
  set = foo;
  cout << "test" << endl;
  foo.print_set();
  set.print_set();
  delete ptr;

  Set *array = new Set[5];
  for ( int i = 0 ; i < 5 ; ++i ){
    array->print_set();
  }
  delete [] array;

  Set gcc[3] = { Set(3), Set(2,2), Set(6,7) };
  for ( int j = 0 ; j < 3 ; ++j ){
    gcc[j].print_set();
  }

  foo = bar;
  bar.print_set();
  foo.print_set();

  friend_print(foo);

  return 0;
}
