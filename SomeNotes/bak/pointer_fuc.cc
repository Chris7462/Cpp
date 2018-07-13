#include <iostream>

using namespace std;

void setup( int * &p, int s, int val ){
  p = new int[s];
  for ( int i=0; i<s; ++i ){
    p[i]=val;
  }
}

void setup2( int *p, int s, int val ){
  p = new int[s];
  for( int i=0; i<s; ++i ){
    p[i]=val;
  }
}

void setup_2d( int ** &p, int r, int c, int val ){
  int i, j;
  p = new int * [r];
  for ( i=0 ; i<r ; ++i ){
    p[i] = new int [c];
    for ( j=0 ; j<c ; ++j ){
      p[i][j] = val;
    }
  }
}

int main(){

  int *ptr, i, j, n=3;
  setup(ptr, n, 1);
  for ( i=0; i<n ; ++i ){
    cout << *(ptr+i) << " ";
  }

  int *ptr2;
  setup2(ptr2, n, 2);
  for ( i=0; i<n ; ++i ){
    cout << *(ptr2+i) << " ";
  }
  cout << endl;

  int **ptr3;
  setup_2d(ptr3, 3, 2, 3);
  for ( i=0; i<3; ++i ){
    for ( j=0; j<2; ++j ){
      cout << ptr3[i][j] << " ";
    }
    cout << endl;
  }

  const char* argv[] = {"animal", "cat", "dog", "fish"};
  cout << argv[0] << endl;

  return 0;
}
