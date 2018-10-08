#include <iostream>
#include "DynSet.h"

int main(){

  int i;
  DynSet foo;

  for ( i = 0 ; i < 10 ; ++i ){
    foo.insert_element( i%10 );
  }
  foo.print_set();

  for ( i = 0 ; i < 10 ; ++i ){
    foo.insert_element( i%10 );
  }
  foo.print_set();

  DynSet qoo;
  qoo = foo;
  qoo.print_set();

  foo.delete_element(3);
  foo.print_set();

  DynSet bar(foo);
  bar.print_set();

  qoo.print_set();

  cout << "Number of object: " << DynSet::obj_no() << endl;
  return 0;
}
