#include <iostream>

using namespace std;

int& min( int &i, int &j ){
  return ( i < j ? i : j );
}

int main()
{
  int a = 1, b = 3, c = 9;
  min(a,b) += c;
  min(a,b) += c;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}
