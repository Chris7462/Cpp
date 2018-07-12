#include <iostream>
#include "Frac.h"

using namespace std;

int main(){
  
  /* Constructor */
  Frac a(3,-2), b(2), c, d(a);
  cout << "There are " << Frac::obj_no() << " objects in the set" << endl;

  /* io operator overload */
  cout << a << endl << b << endl << c << endl << d << endl;
//cout << "Input a frac number" << endl;
//Frac e;
//cin >> e;
//cout << e << endl;


  return 0;
}
