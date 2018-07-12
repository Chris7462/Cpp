#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
using namespace std;

class Complex{
  private:
    double _re;
    double _im;
    static int count;
  public:
    /* constructor */
    Complex(){ ++count; }
    Complex(double r, double i=0) : _re(r), _im(i) { ++count; }
    Complex(const Complex& foo){ _re = foo.get_re(); _im = foo.get_im(); ++count; }

    /* destructor */
    ~Complex(){ --count; }

    /* access private function */
    double get_re(void) const { return _re; }
    double get_im(void) const { return _im; }
    static int obj_no(void){ return count; }

    /* print function for different purpose */
    void print(void) const;               // object print. ex: foo.print()
    //friend void print2(const Complex&);   // use object as input to print object. ex: print(foo)

    /* copy constructor */
    //void operator=(const Complex&);
    //Complex operator=(const Complex&);
    Complex& operator=(const Complex&);

    Complex operator-(void) const;

    Complex& operator+=(const Complex&);
    //Complex operator+(const Complex& a) const ;

    /* member operator overload */
    Complex& operator++();
    Complex operator++(int);

    friend ostream& operator<<(ostream& out, const Complex& foo){
      out << foo._re << (foo._im>=0 ? "+":"") << foo._im << "i";
      return out;
    }

};

int Complex::count=0;

void Complex::print() const {
  if ( this->get_im()<0){
    cout << this->get_re() << this->get_im() << "i" << endl;
  } else {
    cout << this->get_re() << "+" << this->get_im() << "i" << endl;
  }
}

void print2(const Complex& foo){
  if ( foo.get_im()<0 ){
    cout << foo.get_re() << foo.get_im() << "i" << endl;
  } else {
    cout << foo.get_re() << "+" << foo.get_im() << "i" << endl;
  }
}

/* member operator overload */
//void Complex::operator=(const Complex& foo){
//	_re = foo.get_re();
//	_im = foo.get_im();
//}
//Complex Complex::operator=(const Complex& foo){
//	_re = foo.get_re();
//	_im = foo.get_im();
//	return Complex(_re,_im);
//}
Complex& Complex::operator=(const Complex& foo){
  if ( this == &foo ) return *this;
  _re = foo.get_re();
  _im = foo.get_im();
  return *this;
}

Complex Complex::operator-(void) const {
  return Complex(-this->get_re(),-this->get_im());
}

Complex& Complex::operator+=(const Complex& a){
  _re = _re+a.get_re();
  _im = _im+a.get_im();
  return *this;
}

/* global operator overload */
Complex operator+(const Complex& a, const Complex& b){
  double re = a.get_re()+b.get_re();
  double im = a.get_im()+b.get_im();
  return Complex(re,im);
}

Complex operator-(const Complex& a, const Complex& b){
  double re = a.get_re()-b.get_re();
  double im = a.get_im()-b.get_im();
  return Complex(re,im);
}

Complex& operator-=(Complex& a, const Complex& b){
  a = a-b;
  return a;
}

bool operator==(const Complex& a, const Complex& b){
  return ( (a.get_re()==b.get_re()) && (a.get_im() == b.get_im()) );
}

Complex& Complex::operator++(){
  ++(this->_re);
  ++(this->_im);
  return *this;
}

Complex Complex::operator++(int a){
  Complex bar(*this);
  *this+=1;
  return bar;
}

Complex& operator--(Complex& foo){
  foo -= 1;
  return foo;
}

Complex operator--(Complex& foo, int a){
  Complex bar(foo);
  foo -= 1;
  return bar;
}

#endif
