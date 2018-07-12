#include <iostream>

using namespace std;

class Deposit{
  private:
    static double interest_rate;
  public:
    Deposit(){};
    static double print_rate( void ) {
      return interest_rate;
    }
    static void set_rate( double rate ) {
      interest_rate = rate;
    }

};
double Deposit::interest_rate = 0.05;

int main(){

  cout << Deposit::print_rate() << endl;

  Deposit::set_rate(0.03);
  cout << Deposit::print_rate() << endl;

  return 0;
}
