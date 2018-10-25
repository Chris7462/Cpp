#include "Vector.h"

// constructor
Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector( unsigned int s, int v ) : size(s) {
  data = new int[size];
  for ( int i = 0 ; i < size ; ++i ){
    *(data+i) = v;
  }
}

// copy constructor
Vector::Vector( const Vector& a ){
  size = a.size;
  data = new int[size];
  for ( int i = 0 ; i < size ; ++i ){
    *(data+i) = *(a.data+i);
  }
}

// assign operator
Vector& Vector::operator=( const Vector& a ){
  if ( this == &a ) return *this;
  if ( a.size != size ){
    delete [] data;
    size = a.size;
    data = new int[size];
  }
  for ( int i = 0 ; i < size ; ++i ){
    data[i] = a.data[i];
  }
  return *this;
}

// destructor
Vector::~Vector(){
  delete [] data;
}

int& Vector::operator[]( int i ){
  return *(data+i);
}

const int& Vector::operator[]( int i ) const {
  return *(data+i);
}

const unsigned int Vector::get_size() const{
  return size;
}

std::istream& operator>>( std::istream& in, Vector& a ){
  for ( int i = 0 ; i < a.size ; ++i ){
    in >> a.data[i];
  }
  return in;
}

std::ostream& operator<<( std::ostream& out, const Vector& a ){
  out << "{ ";
  for ( int i = 0 ; i < a.size ; ++i ){
    out << *(a.data+i) << " ";
  }
  out << "}";
  return out;
}

Vector operator+( const Vector& a, const Vector& b){
  int i;
  unsigned int size = (a.get_size() >= b.get_size() ? a.get_size() : b.get_size());
  Vector bar(size);
  if ( a.get_size() != b.get_size() ){
    std::cout << "longer object length is not a multiple of shorter object length" << std::endl;
    if ( a.get_size() > b.get_size() ){
      for ( i = 0 ; i < b.get_size() ; ++i ){
        bar[i] = a[i]+b[i];
      }
      for ( i = b.get_size() ; i < a.get_size() ; ++i ){
        bar[i] = a[i]+b[i%b.get_size()];
      }
    } else {
      for ( i = 0 ; i < a.get_size() ; ++i ){
        bar[i] = a[i]+b[i];
      }
      for ( i = a.get_size() ; i < b.get_size() ; ++i ){
        bar[i] = a[i%a.get_size()]+b[i];
      }
    }
  } else {
    for ( i = 0 ; i < size ; ++i ){
      bar[i] = a[i]+b[i];
    }
  }
  return bar;
}

Vector operator-( const Vector& a, const Vector& b){
  int i;
  unsigned int size = (a.get_size() >= b.get_size() ? a.get_size() : b.get_size());
  Vector bar(size);
  if ( a.get_size() != b.get_size() ){
    std::cout << "longer object length is not a multiple of shorter object length" << std::endl;
    if ( a.get_size() > b.get_size() ){
      for ( i = 0 ; i < b.get_size() ; ++i ){
        bar[i] = a[i]-b[i];
      }
      for ( i = b.get_size() ; i < a.get_size() ; ++i ){
        bar[i] = a[i]-b[i%b.get_size()];
      }
    } else {
      for ( i = 0 ; i < a.get_size() ; ++i ){
        bar[i] = a[i]-b[i];
      }
      for ( i = a.get_size() ; i < b.get_size() ; ++i ){
        bar[i] = a[i%a.get_size()]-b[i];
      }
    }
  } else {
    for ( i = 0 ; i < size ; ++i ){
      bar[i] = a[i]-b[i];
    }
  }
  return bar;
}

Vector operator*( const Vector& a, const Vector& b){
  int i;
  unsigned int size = (a.get_size() >= b.get_size() ? a.get_size() : b.get_size());
  Vector bar(size);
  if ( a.get_size() != b.get_size() ){
    std::cout << "longer object length is not a multiple of shorter object length" << std::endl;
    if ( a.get_size() > b.get_size() ){
      for ( i = 0 ; i < b.get_size() ; ++i ){
        bar[i] = a[i]*b[i];
      }
      for ( i = b.get_size() ; i < a.get_size() ; ++i ){
        bar[i] = a[i]*b[i%b.get_size()];
      }
    } else {
      for ( i = 0 ; i < a.get_size() ; ++i ){
        bar[i] = a[i]*b[i];
      }
      for ( i = a.get_size() ; i < b.get_size() ; ++i ){
        bar[i] = a[i%a.get_size()]*b[i];
      }
    }
  } else {
    for ( i = 0 ; i < size ; ++i ){
      bar[i] = a[i]*b[i];
    }
  }
  return bar;
}

Vector operator/( const Vector& a, const Vector& b){
  int i;
  unsigned int size = (a.get_size() >= b.get_size() ? a.get_size() : b.get_size());
  Vector bar(size);
  if ( a.get_size() != b.get_size() ){
    std::cout << "longer object length is not a multiple of shorter object length" << std::endl;
    if ( a.get_size() > b.get_size() ){
      for ( i = 0 ; i < b.get_size() ; ++i ){
        bar[i] = a[i]/b[i];
      }
      for ( i = b.get_size() ; i < a.get_size() ; ++i ){
        bar[i] = a[i]/b[i%b.get_size()];
      }
    } else {
      for ( i = 0 ; i < a.get_size() ; ++i ){
        bar[i] = a[i]/b[i];
      }
      for ( i = a.get_size() ; i < b.get_size() ; ++i ){
        bar[i] = a[i%a.get_size()]/b[i];
      }
    }
  } else {
    for ( i = 0 ; i < size ; ++i ){
      bar[i] = a[i]/b[i];
    }
  }
  return bar;
}
