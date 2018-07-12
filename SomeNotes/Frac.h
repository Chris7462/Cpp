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

    Frac& operator=(const Frac& foo);

    int get_num() const { return _num; }
    int get_den() const { return _den; }
    int gcd(int a, int b) const;
    static int obj_no() { return no; }

    friend std::ostream& operator<<(std::ostream& out, const Frac&);
    friend std::istream& operator>>(std::istream& in, Frac&);

    Frac& operator+=(const Frac&);
    Frac& operator-=(const Frac&);
    Frac& operator*=(const Frac&);
    Frac& operator/=(const Frac&);
};

int Frac::no=0;

int Frac::gcd(int a, int b) const {
  if ( a >= b ){
    return a%b == 0 ? b : gcd(b, a%b);
  } else {
    return b%a == 0 ? a : gcd(a, b%a);
  }
}

Frac& Frac::operator=(const Frac& foo){
  if (this == &foo) { return *this; }
  _num = foo.get_num();
  _den = foo.get_den();
  return *this;
}

std::ostream& operator<<(std::ostream& out, const Frac& foo){
  if ( foo._num == 0 ){
    out << foo._num;
  } else {
    int tmp_num = ( foo._num > 0 ? foo._num : -foo._num );
    int tmp_den = foo._den;
    int divisor = foo.gcd(tmp_num,tmp_den);
    tmp_num = tmp_num/divisor;
    tmp_num = ( foo._num > 0 ? tmp_num : -tmp_num);
    tmp_den = tmp_den/divisor;
    if ( tmp_den == 1 ){
      out << tmp_num;
    } else {
      out << tmp_num << "/" << tmp_den;
    }
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

/* overload operators (global) */
Frac operator+(const Frac& a, const Frac& b){
  double num = a.get_num()*b.get_den()+a.get_den()*b.get_num();
  double den = a.get_den()*b.get_den();
  return Frac(num,den);
}

Frac operator-(const Frac& a, const Frac& b){
  double num = a.get_num()*b.get_den()-a.get_den()*b.get_num();
  double den = a.get_den()*b.get_den();
  return Frac(num,den);
}

Frac operator*(const Frac& a, const Frac& b){
  double num = a.get_num()*b.get_num();
  double den = a.get_den()*b.get_den();
  return Frac(num,den);
}

Frac operator/(const Frac& a, const Frac& b){
  double num = a.get_num()*b.get_den();
  double den = a.get_den()*b.get_num();
  return Frac(num,den);
}

/* overload operators (members) */
Frac& Frac::operator+=(const Frac& foo){
  *this = *this+foo;
  return *this;
}

Frac& Frac::operator-=(const Frac& foo){
  *this = *this-foo;
  return *this;
}

Frac& Frac::operator*=(const Frac& foo){
  *this = *this*foo;
  return *this;
}

Frac& Frac::operator/=(const Frac& foo){
  *this = *this/foo;
  return *this;
}

/* over logical operators (global) */


#endif
