#include <iostream>

using namespace std;

int abs( int );
int square( int );
int cube( int );

int sum_by( int (*fn)(int), int, int );

int main(){

  int x = 3;
  int (*f)(int);
  f = square;
  cout << f(x) << endl;
  f = cube;
  cout << f(x) << endl;

  cout << sum_by(square, 3,5) << endl;

  return 0;
}

int abs( int x ){
  return  x > 0 ? x : -x;
}

int square( int x ){
  return x*x;
}

int cube( int x ){
  return x*x*x;
}

int sum_by( int (*fn)(int), int a, int b ){
  int s=0;
  for ( int i=a ; i<=b ; ++i ){
    s += fn(i);
  }
  return s;
}
