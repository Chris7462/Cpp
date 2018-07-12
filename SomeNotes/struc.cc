#include <iostream>

using namespace std;

const int SIZE = 10;
enum Status { empty, occupied };
struct Set{
  int element[SIZE];
  int status[SIZE];
  int element_no;
};

void set_initialization( Set &foo ){
  for ( int i=0; i<SIZE; ++i ){
    foo.status[i] = empty;
  }
  foo.element_no=0;
}

bool insert_element( Set &s, int data ){
  if ( s.element_no == SIZE ){
    return false;
  } else {
    for ( int i=0 ; i<SIZE ; ++i ){
      if ( s.status[i] == empty ){
        s.element[i] = data;
        s.status[i] = occupied;
        ++s.element_no;
        return true;
      }
    }
  }
}

int delete_element( Set &s, int data ){
  if ( s.element_no == 0 ){
    cout << "nothing to delete" << endl;
    return 0;
  }
  int no_element_deleted = 0;
  for ( int i=0 ; i<SIZE ; ++i ){
    if ( s.status[i] == occupied && s.element[i] == data ){
      s.status[i] = empty;
      --s.element_no;
      ++no_element_deleted;
    }
  }
  cout << no_element_deleted << " elements are deleted" << endl;
  return no_element_deleted;
}

void print_set( const Set &s ){
  cout << s.element_no << endl;
  for ( int i=0; i<SIZE; ++i ){
    if ( s.status[i] == occupied ){
      cout << s.element[i] << " ";
    }
  }
  cout << endl;
}

int main(){

  Set bar;
  set_initialization(bar);
//  print_set(bar);
  delete_element(bar, 3);

  insert_element(bar, 5);
  insert_element(bar, 5);
  insert_element(bar, 5);
  insert_element(bar, 5);
  insert_element(bar, 5);
  print_set(bar);

  delete_element(bar, 5);
  print_set(bar);

  return 0;
}
