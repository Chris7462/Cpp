#ifndef _QUEUE_H_
#define _QUEUE_H_

using namespace std;

class Queue {
  public:
    Queue() : first_index(-1), last_index(-1), element_no(0), max_element_no(Default_Size) {
      data = new int[Default_Size];
    }
    ~Queue(){
      delete [] data;
    }
    bool empty() const;
    int size() const;
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;
    void pop();
    void push (const int& val);
    void swap(Queue& foo);

  private:
    enum { Default_Size = 3, Inc_Size = 6 };
    int *data;
    int first_index;
    int last_index;
    int element_no;
    int max_element_no;
};

bool Queue::empty() const {
  //cout << "ele_no = " << element_no << ", 1st = " << first_index << ", last = " << last_index << endl;
  return ( element_no > 0 ? false : true );
}

int Queue::size() const {
  return element_no;
}

int& Queue::front(){
  if ( element_no > 0 ){
    return data[first_index];
  }
}

const int& Queue::front() const {
  if ( element_no > 0 ){
    return data[first_index];
  }
}

int& Queue::back(){
  if ( element_no > 0 ){
    return data[last_index];
  }
}

const int& Queue::back() const {
  if ( element_no > 0 ){
    return data[last_index];
  }
}

void Queue::pop(){
  if ( element_no > 0 ){
    --element_no;
    first_index = (element_no == 0 ? -1 : (++first_index)%max_element_no);
    last_index = (element_no == 0 ? -1 : last_index);
  } else {
    cout << "Nothing to pop" << endl;
  }
  //cout << "ele_no = " << element_no << ", 1st = " << first_index << ", last = " << last_index << endl;
}

void Queue::push(const int& val){
  int i;
  if ( element_no == 0 ){
    first_index = 0;
    last_index = 0;
    data[0] = val;
    ++element_no;
  } else if ( element_no == max_element_no ){ // if it's full then ask for new space;
    int *tmp_data = new int[max_element_no+Inc_Size];

    // copy all elements to new space;
    for ( i = 0 ; i < max_element_no ; ++i ){
      tmp_data[i] = (*this).front();
      (*this).pop();
    }
    tmp_data[max_element_no] = val;

    // free old memory
    delete [] data;

    // assign new
    data = tmp_data;
    first_index = 0;
    last_index = max_element_no;
    element_no = last_index+1;
    max_element_no += Inc_Size;
  } else {
    last_index = (++last_index)%max_element_no;
    data[last_index] = val;
    ++element_no;
  }
  //cout << "ele_no = " << element_no << ", 1st = " << first_index << ", last = " << last_index << endl;
}

void Queue::swap(Queue& foo){
  int i, n;
  Queue tmp;

  // tmp = this
  n = (*this).size();
  for ( i = 0 ; i < n ; ++i ){
    tmp.push((*this).front());
    (*this).pop();
  }

  // this = foo
  n = foo.size();
  for ( i = 0 ; i < n ; ++i ){
    (*this).push(foo.front());
    foo.pop();
  }

  // foo = tmp
  n = tmp.size();
  for ( i = 0 ; i < n ; ++i ){
    foo.push(tmp.front());
    tmp.pop();
  }
}

#endif
