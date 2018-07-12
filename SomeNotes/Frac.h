#ifndef _FRAC_H_
#define _FRAC_H_

class Frac{
  private:
    int _num;
    int _den;
    static int no;
  public:
    Frac() : _num(0), _den(1) { ++no; }
    Frac(int n, int d=1) : _num(n), _den(d) { 
      if( d<0 ){
        _num *= -1;
        _den *= -1;
      }
      ++no; 
    }
    Frac(const Frac& foo){ _num = foo._num; _den = foo._den; ++no; }
    ~Frac(){ --no; }

    int get_num() const { return _num; }
    int get_den() const { return _den; }
    int gcd(int a, int b) const;
    static int obj_no() { return no; }

    friend std::ostream& operator<<(std::ostream& out, const Frac&);
    friend std::istream& operator>>(std::istream& in, Frac&);
};

int Frac::no=0;

int Frac::gcd(int a, int b) const {
  if ( a >= b ){
    return a%b == 0 ? b : gcd(b, a%b);
  } else {
    return b%a == 0 ? a : gcd(a, b%a);
  }
}

std::ostream& operator<<(std::ostream& out, const Frac& foo){
  if ( foo._num == 0 || foo._den == 1 ){
    out << foo._num;
  } else {
    int num = ( foo._num > 0 ? foo._num : -foo._num );
    int den = foo._den;
    int divisor = foo.gcd(num,den);
    out << foo._num/divisor << "/" << foo._den/divisor;
  }
  return out;
}

std::istream& operator>>(std::istream& in, Frac& foo){
  std::cout << "Input numerator: ";
  in >> foo._num;
  std::cout << "Input denominator > 0: ";
  in >> foo._den;
  return in;
}

#endif
