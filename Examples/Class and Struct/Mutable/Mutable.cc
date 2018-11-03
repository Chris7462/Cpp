#include <iostream>

using namespace std;

enum Action { None = -1, Square = 1, Abs = 2 };

class MATH{
  public:
    MATH( int a = 0 ) : num(a), act(None) {};
    ~MATH(){};
    int square() const { 
      act = Square;
      return num*num; 
    }
    int abs() const { 
      act = Abs;
      return (num > 0 ? num : -num ); 
    }
    Action last_action() const { return act; }
  private:
    int num;
    mutable Action act;
};

int main(){

  const MATH foo(-2);
  cout << foo.last_action() << endl;
  cout << foo.square() << endl;
  cout << foo.abs() << endl;
  cout << foo.last_action() << endl;
  return 0;
}
