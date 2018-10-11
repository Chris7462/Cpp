#include <iostream>

using namespace std;

int main(){

  int a=3, b=2, c=1;
  int *p[3];   // a vector that contain 3 pointers
  p[0] = &a;
  p[1] = &b;
  p[2] = &c;

  cout << *p[0] << endl;

  int i,j;
  int **ptr = new int* [3];
  for ( i=0 ; i<3 ; ++i ){
    ptr[i] = new int [2];
  }

  for ( i=0 ; i<3 ; ++i ){
    for ( j=0 ; j<2 ; ++j ){
      cout << ptr[i][j] << " ";
    }
    cout << endl;
    //cout << *(*(ptr+i)) << endl;
    //cout << *ptr[i] << endl;
    //cout << (*ptr)[i] << endl;
  }

  for ( i=0 ; i<3 ; ++i ){
    delete ptr[i];
  }

  delete [] ptr;

  const char *pt = "I was wrong.";
  cout << pt[0] << endl;

  const char *pt2 = "tiger";
  pt = pt2;

  for ( i=0 ; pt[i]!= '\0'; ++i ){
    cout << pt[i];
  }
  cout << endl;
  cout << pt << endl;

  char array[] = "APTIV";
  cout << array << endl;

  char *pch = &array[0];
  cout << pch << endl;

  return 0;
}
