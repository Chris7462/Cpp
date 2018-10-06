#include <iostream>
#include <string>

using namespace std;

string bigint_add( string a, string b )
{
  int i, tmp, diff;
  diff = a.length()-b.length();
  if ( diff < 0 ){ diff *= -1; }

  if ( a.length() < b.length() ){
    for ( i = 0 ; i < diff ; ++i ){
      a = '0' + a;
    }
  } else {
    for ( i = 0 ; i < diff ; ++i ){
      b = '0' + b;
    }
  }

  string sum = "";
  int carry = 0;
  for ( i = a.length()-1 ; i >= 0 ; --i ){
    tmp = (a[i]-'0') + (b[i]-'0') + carry;
    sum = static_cast<char>((tmp%10)+'0')+sum;
    carry = tmp/10;
  }

  if ( carry ){
    sum = static_cast<char>(carry+'0')+sum;
  }

  return sum;
}

int main()
{
  string a, b;
  cin >> a >> b;
//a = "12434352636";
//b = "5346323462923";
  cout << a << "\n" << b << endl;
  cout << bigint_add(a,b) << endl;

  return 0;
}
