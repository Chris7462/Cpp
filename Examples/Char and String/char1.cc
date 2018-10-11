#include <iostream>

using namespace std;

int main(){

  char a[3] = {'c', 'a', 't'};
  cout << a << endl;

  char *p = a;
  cout << p[0] << endl;
  cout << *(p+1) << endl;
  return 0;
}
