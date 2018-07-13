#ifndef _INHERIT_H_
#define _INHERIT_H_

class A {
  protected:
    int abs( int x ){ return x > 0 ? x : -x; }
  public:
    int square( int x ){ return x*x; }
};

class B : public A {
//class B : protected A {
//class B : private A {
  public:
    int cubic( int x ){ return x*square(x); }
};

class C : public B {
//class C : protected B {
  public:
    int abs_sum( int x, int y ){ return abs(x)+abs(y); }
    int square_sum( int x, int y ){ return square(x)+square(y); }
    int cubic_sum( int x, int y ){ return cubic(x)+cubic(y); }
};

#endif
