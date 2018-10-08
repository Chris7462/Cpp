#include <iostream>

using namespace std;

class FOO {
  public:
    FOO(){ ptr = new int(0); }
    FOO( int a ){ ptr = new int(a); }
    ~FOO(){ delete ptr; }
    FOO( const FOO& foo ){
      ptr = new int( *(foo.ptr) );
    }
    void print(){
      cout << ptr << "\t" << *ptr << endl;
    }
  private:
    int *ptr;
};

int main(){

  FOO foo, qoo(foo);
  foo.print();
  //qoo = foo;
  qoo.print();


  return 0;
}
