#ifndef _QUEUE_H_
#define _QUEUE_H_

using namespace std;

class Queue {
  public:
    Queue() : first_index(-1), last_index(-1), element_no(0) {}
    ~Queue(){}
    bool empty() const;
    int size() const;
    int& front();
    const int& front() const;
    int& back();
    const int& back() const;
    void push (const int& val);
    void pop();
    void swap(Queue& foo);

  private:
    enum { SIZE = 10 };
    int data[SIZE];
    int first_index;
    int last_index;
    int element_no;
};

bool Queue::empty() const {
  cout << "ele_no = " << element_no << ", 1st = " << first_index << ", last = " << last_index << endl;
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

void Queue::push(const int& val){
  if ( element_no == SIZE ){
    cout << "Queue is full. Can't push anymore." << endl;
    return;
  }
  if ( element_no == 0 ){
    first_index = 0;
    last_index = 0;
  } else {
    last_index = (++last_index)%SIZE;
  }
  data[last_index] = val;
  ++element_no;
  //cout << "ele_no = " << element_no << ", 1st = " << first_index << ", last = " << last_index << endl;
}

void Queue::pop(){
  if ( element_no > 0 ){
    --element_no;
    first_index = (element_no == 0 ? -1 : (++first_index)%SIZE);
    last_index = (element_no == 0 ? -1 : last_index);
  } else {
    cout << "Nothing to pop" << endl;
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
