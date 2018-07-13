#include <iostream>

using namespace std;

int main(){

  int foo = 5;
  int *p = &foo;
  int **q = &p;

  cout << "foo = " << foo << "  &foo = " << &foo << endl;
  cout << " *p = " <<  *p << "     p = " << p << "  &p = " << &p << endl;
  cout << "**q = " << **q << "    *q = " << *q << "   q = " << q << "  &q = " << &q << endl;

  int i,j;
  const int m=4, n=3;
  int **ptr = new int * [m];
  for ( i = 0 ; i < m ; ++i ){
    *(ptr+i) = new int [n];
  }

  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      *(*(ptr+i)+j) = n*i+j+1;
      cout << ptr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
