// This is an example file for pointer & address //
#include <iostream>

using namespace std;

int main(){

  /* Some basic idea */
  int foo = 30;
  int bar = 20;

  // pointer
  int *ptr;             // ptr is a integer pointer
  ptr = &foo;           // point to the adress of foo
  // int *ptr = &foo;   // the same way

  cout << ptr << endl;  // out put the address of foo
  cout << *ptr << endl;

  // constant pointer
  const int *p = &foo;
  cout << *p << endl;
  // *p += 1;           // wrong. *p is a constant. Can not be changed

  p = &bar;             // It's okay, the pointer value can be change
  cout << *p << endl;
  // *p += 1;           // wrong again.

  bar = 10;
  cout << *p << endl;


  // pointer constant
  int *const q = &foo;  // the ptr q is always point to foo and can not be changed
  *q += 1;              // it okay.
  cout << *q << endl;

  // q = &foo;          // wrong. Since q is a const pointer.

  const int *const r = &foo;  
  // *r += 1;           // wrong
  // r = &bar;          // wrong. Can't change anything
  

  /* swap two values by changing the pointer */
  int a = 3, b = 10;
  int *pa = &a, *pb = &b;
  int tmp = 0;

  cout << *pa << " " << *pb << " " << endl;

  tmp = *pa;
  *pa = *pb;
  *pb = tmp;
  cout << *pa << " " << *pb << " " << endl;

  /* swap two values by changing the address */
  int *pr = pa;
  pa = pb;
  pb = pr;
  cout << *pa << " " << *pb << endl;

  /* dynamic assign memory */
  int *pt;
  pt = new int;
  *pt = 10;
  *pt += 1;
  cout << *pt << endl;
  delete pt;

  int *pt2 = new int(10);
  cout << *pt2 << endl;
  delete pt2;

  /* dynamic assign memory array */
  int n = 20;
  int *ptr_array = new int [n];
  for ( int i = 0 ; i < n ; ++i ){
    *(ptr_array+i) = i+1; // or ptr_array[i] = i+1;
    cout << *(ptr_array+i) << " ";
  }
  delete [] ptr_array;

  return 0;
}
