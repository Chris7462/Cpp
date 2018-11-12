#ifndef _SET_H_
#define _SET_H_

#include <iostream>

template <typename T>
class Set {
  public:
    Set<T>();
    Set<T>(T x, int n);
    ~Set<T>();

    // print
    void print(void) const ;

    template <typename S>
    friend std::ostream& operator<<(std::ostream& out, const Set<S>& foo );

  private:
    T* data;
    int no;
};

// Constructor
template <typename T>
Set<T>::Set() : no(0) {
  data = nullptr;
}

template <typename T>
Set<T>::Set(T x, int n ) : no(n) {
  data = new T[no];
  for ( int i = 0 ; i < no ; ++i ){
    data[i] = x;
  }
}

// Destructor
template <typename T>
Set<T>::~Set(){
  std::cout << "release memory" << std::endl;
  delete [] data;
}

template <typename T>
void Set<T>::print(void) const {
  std::cout << "{ ";
  for ( int i = 0 ; i < no ; ++i ){
    std::cout << *(data+i) << " "; 
  }
  std::cout << "}" << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& foo ){
  out << "{ ";
  for ( int i = 0 ; i < foo.no ; ++i ){
    out << *(foo.data+i) << " ";
  }
  out << "}";

  return out;
}

#endif
