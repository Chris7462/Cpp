#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector {
  public:
    // constructor
    Vector();
    Vector( unsigned int s, int v = 0 );

    // copy constructor 
    Vector( const Vector& a );

    // Assign operator
    Vector& operator=( const Vector& a );

    // destructor
    ~Vector();

    int& operator[]( int i );
    const int& operator[]( int i ) const;
    const unsigned int get_size() const;

    friend std::istream& operator>>( std::istream& in, Vector& a );
    friend std::ostream& operator<<( std::ostream& out, const Vector& a );

  private:
    int *data;
    unsigned int size;
};

Vector operator+( const Vector& a, const Vector& b);
Vector operator-( const Vector& a, const Vector& b);
Vector operator*( const Vector& a, const Vector& b);
Vector operator/( const Vector& a, const Vector& b);

#endif
