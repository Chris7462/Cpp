#include <iostream>

using namespace std;

int length( const char * );
void swap( int &, int &);
int sum( const int *, int);
//int sum( int [], int n);
int sum( const int [][3], int, int);

int main(){

  const char *p = "APTIV";
  cout << length(p) << endl;

  const char * &q = p;
  cout << length(q) << endl;

  int a=3, b=2;
  cout << a << " " << b << endl;

  swap(a,b);
  cout << a << " " << b << endl;

  int vec[3] = {1,2,3};
  cout << sum(vec,3) << endl;

  int mat[2][3] = {{1,2,3},{2,3,4}};
  cout << sum(mat,2,3) << endl;

  return 0;
}

int length( const char *str ){
  int len=0;
  while( *(str+len) != '\0' ) ++len;
  return len;
}

void swap(int &tmpa, int &tmpb){
  int tmp = tmpa;
  tmpa = tmpb;
  tmpb = tmp;
}

int sum( const int *vec, int n ){
//int sum( int vec[], int n ){
  int total=0;
  for( int i=0; i<n ; ++i ){
    total += *(vec+i);
  }
  return total;
}

int sum( const int mat[][3], int r, int c){
  int i, j, total=0;
  for ( i=0 ; i<r ; ++i ){
    for ( j=0 ; j<c ; ++j ){
      total += mat[i][j];
    }
  }
  return total;
}
