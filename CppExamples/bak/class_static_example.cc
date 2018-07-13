#include <iostream>

using namespace std;

class FOO{
  private:
    static int count;

  public:
    FOO(){ ++count; }
    FOO( const FOO &a ){ ++count; }
    ~FOO(){ --count; }

    static int obj_no(void){ return count; }
};
int FOO::count=0;

int main(){
  FOO a;
  for ( int i=0; i<3; ++i ){
    cout << FOO::obj_no() << endl;
    FOO b(a);
    cout << FOO::obj_no() << endl;
  }
  cout << FOO::obj_no() << endl;

  // cout << a.obj_no() << endl; // not a good way to do it.

  return 0;
}
