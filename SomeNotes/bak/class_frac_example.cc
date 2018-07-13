#include <iostream>
#include <cassert>

using namespace std;

class Fraction{
  private:
    int _num;
    int _den;
  public:
    /* constructor */
    Fraction(void){}
    Fraction(int n, int d=1): _num(n), _den(d) {
      assert(d!=0);
      if (d<0){ _num *= -1; _den *= -1; }
    }
    /* destructor */
    ~Fraction(){};

    /* some function */
    int get_num(void) const { return _num; }
    int get_den(void) const { return _num; }
    void print(void);
};


int main(){

  Fraction a(3,-1);
  a.print();

  return 0;
}


void Fraction::print(void){
  cout << _num << "/" << _den << endl;
}
