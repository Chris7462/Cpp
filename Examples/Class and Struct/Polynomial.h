#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

class Polynomial{
  public:
    Polynomial() : deg(0) {
      for ( int i = 0 ; i < SIZE ; ++i ){
        coeff[i] = 0;
      }
    }
    Polynomial(double *coef, int d);
    ~Polynomial(){}
    double value( double x ) const;
    Polynomial derivative() const;
    Polynomial intergal() const;
    double intergal( double a, double b ) const;
    void print() const;
  private:
    enum { SIZE = 20 };
    int deg;
    double coeff[SIZE];
};

Polynomial::Polynomial(double *coef, int d){
  deg = d;
  for ( int i = 0 ; i < (d+1) ; ++i ){
    coeff[i] = coef[i];
  }
}

double Polynomial::value( double x ) const {
  double v = coeff[deg]*x;
  for ( int i = deg-1 ; i > 0 ; --i ){
    v = x*(coeff[i]+v); 
  }
  v += coeff[0];
  return v;
}

Polynomial Polynomial::derivative() const {
  int d = (*this).deg-1;
  double coef[d];
  for ( int i = 0 ; i < (d+1) ; ++i ){
    coef[i] = coeff[i+1]*(i+1);
  }
  Polynomial foo(coef,d);
  return foo;
}

Polynomial Polynomial::intergal() const {
  int d = (*this).deg+1;
  double coef[d];
  coef[0] = 0;
  for ( int i = 1 ; i < (d+1) ; ++i ){
    coef[i] = coeff[i-1]/i;
  }
  Polynomial foo(coef,d);
  return foo;
}

double Polynomial::intergal( double a, double b ) const {
  double v = (*this).intergal().value(b) - (*this).intergal().value(a);
  return v;
}

// print the function
void Polynomial::print() const {
  for ( int i = 0 ; i < (deg+1) ; ++i ){
    if ( i == 0 ){
      std::cout << coeff[i];
    } else if ( i == 1 ){
      std::cout << (coeff[i] >= 0 ? "+" : "") << coeff[i] << "x";
    } else {
      std::cout << (coeff[i] >= 0 ? "+" : "") << coeff[i] << "x^" << i;
    }
  }
  std::cout << std::endl;
}

#endif
