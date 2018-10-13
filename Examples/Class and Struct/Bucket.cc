#include <iostream>
#include "Bucket.h"

using namespace std;

int main()
{
  Bucket a(5), b(3);

  a.fill_up();
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;
  a.pour_to(b);
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;
  b.empty();
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;
  a.pour_to(b);
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;
  a.fill_up();
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;
  a.pour_to(b);
  cout << "a = " << a.water_height() << "\t" << "b = " << b.water_height() << endl;

  return 0;
}
