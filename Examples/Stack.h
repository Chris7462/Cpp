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
    void swap(Stack& x);

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
  if ( element_no == 0 ){
    cout << "No element in the stack. Nothing to show." << endl;
  }
  return data[element_no-1];
}

const int& Stack::top() const {
  if ( element_no == 0 ){
    cout << "No element in the stack. Nothing to show." << endl;
  }
  return data[element_no-1];
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
  if ( element_no == 0 ){
    cout << "No element in the stack. Nothing to pop." << endl;
    return;
  }
  --element_no;
}

void Stack::swap(Stack& x){
  int i, tmp_data[SIZE], tmp_element_no;
  for ( i = 0 ; i < (*this).size() ; ++i ){
    tmp_data[i] = (*this).top();
    (*this).pop();
  }

  //tmp_element_no = element_no;

}

#endif
