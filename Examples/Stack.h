#ifndef _STACK_H_
#define _STACK_H_

using namespace std;

class Stack{
  public:
    Stack() : element_no(0) {}
    ~Stack(){}
    bool empty() const;
    int size() const;
    int& top();
    const int& top() const;
    void push(const int& val);
    void pop();
    void swap(Stack& foo);

  private:
    enum {SIZE=10};
    int data[SIZE];
    int element_no;
};

bool Stack::empty() const {
  return (element_no == 0 ? true : false);
}

int Stack::size() const {
  return element_no;
}

int& Stack::top() {
  if ( element_no > 0 ){
    return data[element_no-1];
  }
}

const int& Stack::top() const {
  if ( element_no > 0 ){
    return data[element_no-1];
  }
}

void Stack::push(const int& val){
  if ( element_no == SIZE ){
    cout << "Stack is full. Can't push anymore." << endl;
    return;
  }
  data[element_no] = val;
  ++element_no;
}

void Stack::pop(){
  if ( element_no > 0 ){
    --element_no;
  }
}

void Stack::swap(Stack& foo){
  int i, n;
  Stack tmp;

  // tmp = this
  if ( !(*this).empty() ){
    n = (*this).size();
    for ( i = 0 ; i < n ; ++i ){
      tmp.push((*this).top());
      (*this).pop();
    }
  }

  // this = foo
  if ( !foo.empty() ){
    n = foo.size();
    for ( i = 0 ; i < n ; ++i ){
      (*this).push(foo.top());
      foo.pop();
    }
  }

  // foo = tmp
  n = tmp.size();
  for ( i = 0 ; i < n ; ++i ){
    foo.push(tmp.top());
    tmp.pop();
  }
}

#endif
