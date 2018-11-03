#ifndef _SET_H_
#define _SET_H_

using namespace std;

const int SIZE = 10;

enum Status { empty, occupied };

class Set {
  public:
    // constructor
    Set();
    Set(int data, int no = 1);
    // destructor
    ~Set();
    // copy constructor
    Set( const Set& set );

    // assignment operator
    Set& operator=( const Set& set );

    void initialization();
    void print_set();
    bool insert_element(int data);
    int delete_element(int data);

    friend void friend_print( const Set& set ) {
      cout << set.element_no << endl;
    }

  private:
    int element[SIZE];
    Status status[SIZE];
    int element_no;
};


Set::Set(){
  for ( int i = 0 ; i < SIZE ; ++i ){
    status[i] = empty;
  }
  element_no = 0;
}

Set::Set( int data, int no ){
  for ( int i = 0 ; i < SIZE ; ++i ){
    if ( i < no ){
      element[i] = data;
      status[i] = occupied;
    } else {
      status[i] = empty;
    }
  }
  element_no = no;
}

Set::~Set(){}

// copy constructor
Set::Set( const Set& set ){
  for ( int i = 0 ; i < SIZE ; ++i ){
    element[i] = set.element[i];
    status[i] = set.status[i];
  }
  element_no = set.element_no;
}

Set& Set::operator=( const Set& set ){
  for ( int i = 0 ; i < SIZE ; ++i ){
    element[i] = set.element[i];
    status[i] = set.status[i];
  }
  element_no = set.element_no;
  return *this;
}

void Set::initialization(){
  for ( int i = 0 ; i < SIZE ; ++i ){
    status[i] = empty;
  }
  element_no = 0;
}

void Set::print_set(){
//if ( element_no == 0 ){
//  cout << "No element in the set" << endl;
//} else {
    cout << "{ ";
    for ( int i = 0 ; i < SIZE ; ++i ){
      if ( status[i] == occupied ){
        cout << element[i] << " ";
      }
    }
    cout << "}" << endl << "No: " << element_no << endl;
//}
}

bool Set::insert_element(int data){
  if ( element_no == SIZE ){
    return false;
  }

  for ( int i = 0 ; i < SIZE ; ++i ){
    if ( status[i] == empty ){
      element[i] = data;
      status[i] = occupied;
      ++element_no;
      return true;
    }
  }
}

int Set::delete_element(int data){
  int no_element_del = 0;
  
  for ( int i = 0 ; i < SIZE ; ++i ){
    if ( element[i] == data && status[i] == occupied ){
      status[i] = empty;
      ++no_element_del;
      --element_no;
    }
  }
  return no_element_del;
}

#endif
