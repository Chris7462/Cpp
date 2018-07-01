#include <iostream>

using namespace std;

int main(){
  int i, j, k, foo[]={1,3,5,7};
  int size = sizeof(foo)/sizeof(int);
  cout << size << endl;

  int b[2][3] = {1,2,3,4,5,6};
  for ( i = 0 ; i < 2 ; ++i ){
    for ( j = 0 ; j < 3 ; ++j ){
      cout << b[i][j] << " ";
    }
    cout << endl;
  }

  int a[2][3] = { {1}, {2,3} };
  for ( i = 0 ; i < 2 ; ++i ){
    for ( j = 0 ; j < 3 ; ++j ){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  int bar[3] = {5,2,3};
  //int *p = &bar[0];
  int *p = bar;

  for ( i=0 ; i<3 ; ++i ){
    cout << bar[i] << " " << *(p+i) << endl;
  }

  const int R=3,C=2,D=4;
  /* one dimension array */
  int foo1[R] = {1,2,3};
  int *ptr1 = &foo1[0];
  for ( i=0 ; i<R; ++i ){
    cout << *(ptr1+i) << " ";
  }
  cout << endl;

  /* two dimension array */
  int foo2[R][C] = { {1,2},{3,4},{5,6} };
  int *ptr2 = &foo2[0][0];
  for ( i=0 ; i<R ; ++i ){
    for ( j=0 ; j<C ; ++j ){
      cout << *(ptr2+i*C+j) << " ";
    }
    cout << endl;
  }

  /* three dimenstion array */
  int foo3[R][C][D] = { { {1,2,3,4}, {5,6,7,8} }, 
                        { {9,10,11,12}, {13,14,15,16} }, 
                        { {17,18,19,20}, {21,22,23,24} } };
  int *ptr3 = &foo3[0][0][0];
  for ( i=0 ; i<R ; ++i ){
    for ( j=0 ; j<C ; ++j ){
      for ( k=0 ; k<D ; ++k ){
        //cout << foo3[i][j][k] << " ";
        cout << *(ptr3+i*C*D+j*D+k) << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
