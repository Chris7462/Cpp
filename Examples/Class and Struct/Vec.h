#ifndef _VEC_H_
#define _VEC_H_

class Vec{
  private:
    int *data;
    unsigned int size;
  public:
    /* constructor */
    Vec() : data(NULL), size(0) {}
    Vec(unsigned int s, int v=0);
    Vec(const Vec&);

    /* copy operator */
    Vec& operator=(const Vec&);

    /* destructor */
    ~Vec();

    /* overload io operator as friend function */
    friend std::ostream& operator<<(std::ostream&, const Vec&);
    friend std::istream& operator>>(std::istream&, Vec&);

    /* overload subscript operator */
    int& operator[](int i) { return data[i]; }
    const int& operator[](int i) const { return data[i]; }

    /* overload operators as member function */
    Vec operator+(const Vec&) const ;
    Vec operator-(const Vec&) const ;
    int operator*(const Vec&) const;

};

/* constructor */
Vec::Vec(unsigned int s, int v) : size(s) {
  data = new int [size];
  for( int i=0 ; i<size ; ++i ){ 
    *(data+i) = v; 
  }
}

Vec::Vec(const Vec& foo) : size(foo.size) {
  data = ( size > 0 ? new int [size] : NULL );
  for( int i=0 ; i<size ; ++i ){
    *(data+i) = foo.data[i];
  }
}

/* copy operator */
Vec& Vec::operator=(const Vec& foo){
  if( this == &foo ){ return *this; }
  if( size != foo.size ) {
    if( size ){ delete [] data; }
    size = foo.size;
    data = ( size ? new int [size] : NULL );
  }
  for( int i=0 ; i<size ; ++i ){
    *(data+i) = foo.data[i];
  }
  return *this;
}

/* destructor */
Vec::~Vec(){ if (size>0) delete [] data; }

/* overload operator for output stream */
std::ostream& operator<<(std::ostream& out, const Vec& a){
  out << "{";
  if( a.size ){
    for( int i=0 ; i<a.size-1 ; ++i ){
      out << *(a.data+i) << ",";
    }
    out << *(a.data+a.size-1);
  }
  out << "}";
  return out;
}

std::istream& operator>>(std::istream& in, Vec& a){
  for( int i=0 ; i<a.size ; ++i ){
    in >> *(a.data+i);
  }
  return in;
}

/* overload operators as global function */
Vec Vec::operator+(const Vec& a) const {
  Vec foo(a.size);
  for( int i=0; i<foo.size; ++i ){
    foo.data[i] = this->data[i] + a.data[i];
  }
  return foo;
}

Vec Vec::operator-(const Vec& a) const {
  Vec foo(a.size);
  for( int i=0; i<foo.size; ++i ){
    foo.data[i] = this->data[i] - a.data[i];
  }
  return foo;
}

int Vec::operator*(const Vec& foo) const {
  if( !size ){
    return 0;
  } else {
    int sum=0;
    for( int i=0 ; i<size ; ++i ){
      //sum += data[i]*foo.data[i];
      sum += data[i]*foo[i];
    }
    return sum;
  }
}

#endif
