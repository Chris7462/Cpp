#include <iostream>

using namespace std;

//const int SIZE=10;
enum status {empty, occupied};

class Set {
  private:
    int *element;
    status *stat;
    int element_no;
    int size;
  public:
    Set(int SIZE=10);     /* constructor */
    ~Set(void);           /* destructor */
    Set(const Set &foo ); /* copy-constructor */
    Set& operator=(const Set& foo); /* assign operator */
    void print(void) const;
    friend void print2(const Set &foo );
    bool insert(int data);
    bool remove(int data);
};

int main(){

  Set foo;
  foo.print();
  foo.insert(3);
  foo.print();
  foo.remove(2);
  foo.insert(4);
  foo.insert(4);
  foo.print();
  foo.remove(4);
  foo.print();

  /* const class */
  const Set bar(5);
  bar.print();
  //bar.insert(3);

  Set qoo(foo); // this equals to Set qoo=foo;, but is different from Set qoo; qoo=foo;
  qoo.print();
  cout << endl;

  Set pqa;
  //pqa.operator=(qoo);
  pqa = qoo;
  pqa.print();

  print2(pqa);

  return 0;
}

/* constructor */
Set::Set(int SIZE){
  element = new int[SIZE];
  stat = new status[SIZE];
  element_no = 0;
  for ( int i=0 ; i<SIZE ; ++i ){
    stat[i] = empty;
  }
  size=SIZE;
  cout << "Set size is " << size << endl;
}

/* destructor */
Set::~Set(void){
  delete [] element;
  delete [] stat;
}

/* copy-constructor */
Set::Set(const Set &foo ){
  cout << "Copy constructor" << endl;
  element = new int[foo.size];
  stat = new status[foo.size];
  element_no = foo.element_no;
  for ( int i=0; i<foo.size; ++i ){
    stat[i] = foo.stat[i];
    element[i] = foo.element[i];
  }
  size = foo.size;
//cout << &foo.element[0] << endl;
//cout << &element[0] << endl;
}

/* assign operator */
Set& Set::operator=(const Set& foo){
  cout << "assign operator" << endl;
  element = new int[foo.size];
  stat = new status[foo.size];
  element_no = foo.element_no;
  for ( int i=0; i<foo.size; ++i ){
    stat[i] = foo.stat[i];
    element[i] = foo.element[i];
  }
  size = foo.size;
  return *this;
}

void Set::print(void) const {
  if( element_no == 0 ){
    cout << "Nothing to print!" << endl;
    cout << this->element_no << endl;
    cout << (*this).element_no << endl;
  } else {
    cout << "There are " << element_no << " elements in the set: ";
    for ( int i=0; i<size; ++i ){
      if ( *(stat+i) == occupied ){
        cout << *(element+i) << " ";
        //cout << this->element[i] << " ";
      }
    }
    cout << endl;
  }
}


void print2(const Set &foo ){
  cout << "There are " << foo.element_no << " elements in ths set" << endl;
}

bool Set::insert(int data){
  if ( element_no == size){
    cout << "No space to insert elements" << endl;
    return 0;
  } else {
    for ( int i = 0 ; i < size; ++i ){
      if ( stat[i] == empty ){
        stat[i] = occupied;
        element[i] = data;
        ++element_no;
        return 1;
      }
    }
  }
}

bool Set::remove(int data){
  if ( element_no == 0 ){
    cout << "No elements in the set. Nothing to be deleted." << endl;
  } else {
    int del_element_no=0;
    for ( int i=0 ; i<size; ++i ){
      if ( stat[i] == occupied && element[i] == data ){
        stat[i] = empty;
        --element_no;
        ++del_element_no;
      }
    }
    if ( del_element_no == 0 ){
      cout << "Can't find the element " << data << " in the set. Nothing to be deleted" << endl;
    } else {
      cout << "There are " << del_element_no << " element to be deleted" << endl;
    }
  }
}
