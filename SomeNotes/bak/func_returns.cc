#include <iostream>

using namespace std;

int* max(int *p, int *q){
  cout << q << endl;
  return *p > *q ? p : q;
}

int* max(int &m, int &n){
  cout << n << endl;
  return m > n ? &m : &n;
}

char* char_srt( char a, int n ){
  char *s = new char[n+1];
  for ( int i=0 ; i<n ; ++i ){
    *(s+i) = a;
  }
  s[n] ='\0';

  return s;
}
//char* char_srt( char a, int n ){
//  char s[10] = {'\0'};
//  for ( int i=0 ; i<n ; ++i ){
//    s[i] = a;
//  }
//  return s; // return local variable. Not good.
//}

int main(){

  int a=3, b=5;
  int *c = max(&a,&b);
  cout << &a << " " << a << endl;
  cout << &b << " " << b << endl;
  cout << c << " " << *c << endl;

  int *p = max(a,b);
  cout << p << " " << *p << endl;

  char *ptr;
  ptr = char_srt('x',9);
  cout << ptr << endl;
  delete [] ptr;

  return 0;
}
