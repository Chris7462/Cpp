#ifndef _DYNSET_H_
#define _DYNSET_H_

#define DEFAULT_SIZE 10
#define INC_SIZE 20

enum Status { empty, occupied };

using namespace std;

class DynSet{
  public:
    // default constructor
    DynSet() : element_no(0), max_element_no(DEFAULT_SIZE) {
      element = new int[max_element_no];
      status = new Status[max_element_no];
      for ( int i = 0 ; i < max_element_no ; ++i ){
        *(status+i) = empty;
      }
      ++object_no;
    }

    // destructor
    ~DynSet(){
      delete [] element;
      delete [] status;
      --object_no;
    }

    // copy constructor
    DynSet( const DynSet& set );

    // assign operator
    DynSet& operator=( const DynSet& set );

    // insert element
    void insert_element( int data );

    // delete element
    int delete_element( int data );

    // print set
    void print_set() const;

    static int obj_no() { return object_no; }

  private:
    int *element;
    Status *status;
    int element_no;
    int max_element_no;
    static int object_no;
};

// initialize static object number.
int DynSet::object_no=0;

// copy constructor
DynSet::DynSet( const DynSet& set ){
  element_no = set.element_no;
  max_element_no = set.max_element_no;
  element = new int[max_element_no];
  status = new Status[max_element_no];
  for ( int i = 0 ; i < max_element_no ; ++i ){
    element[i] = set.element[i];
    status[i] = set.status[i];
  }
  ++object_no;
}

// assign operator
DynSet& DynSet::operator=( const DynSet& set ){
  if ( max_element_no >= set.max_element_no ){
    int i, c = 0;
    element_no = set.element_no;

    for ( i = 0 ; i < set.max_element_no ; ++i ){
      if ( set.status[i] == occupied ){
        element[c] = set.element[i];
        status[c] = set.status[i];
        ++c;
      }
    }

    for ( i = c ; i < max_element_no ; ++i ){
      status[i] = empty;
    }

  } else {
    element_no = set.element_no;
    max_element_no = set.max_element_no;

    int *tmp_element = new int[max_element_no];
    Status *tmp_status = new Status[max_element_no];

    for ( int i = 0 ; i < max_element_no ; ++i ){
      tmp_element[i] = set.element[i];
      tmp_status[i] = set.status[i];
    }

    delete [] element;
    delete [] status;

    element = tmp_element;
    status = tmp_status;
  }

  return *this;
}

// insert element
void DynSet::insert_element( int data ){
  int i;
  if ( element_no < max_element_no ){
    for ( i = 0 ; i < max_element_no ; ++i ){
      if ( status[i] == empty ){
        element[i] = data;
        status[i] = occupied;
        ++element_no;
        return;
      }
    }
  } else {
    int *tmp_element = new int[max_element_no+INC_SIZE];
    Status *tmp_status = new Status[max_element_no+INC_SIZE];

    for ( i = 0 ; i < max_element_no ; ++i ){
      tmp_element[i] = element[i];
      tmp_status[i] = status[i];
    }
    tmp_element[max_element_no] = data;
    tmp_status[max_element_no] = occupied;
    ++element_no;

    for ( i = 1 ; i < INC_SIZE ; ++i ){
      tmp_status[max_element_no+i] = empty;
    }

    delete [] element;
    delete [] status;

    element = tmp_element;
    status = tmp_status;

    max_element_no += INC_SIZE;
  }
}

// delete element
int DynSet::delete_element( int data ){
  int no_element_deleted = 0;
  for ( int i = 0 ; i < max_element_no ; ++i ){
    if ( element[i] == data && status[i] == occupied ){
      status[i] = empty;
      --element_no;
      ++no_element_deleted;
    }
  }
  return no_element_deleted;
}

void DynSet::print_set() const {
  cout << "{ ";
  for ( int i = 0 ; i < max_element_no ; ++i ){
    if ( status[i] == occupied ){
      cout << element[i] << " ";
    }
  }  
  cout << "}" << endl << "No. of elements: " << element_no << endl;
}

#endif
