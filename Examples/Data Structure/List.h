#ifndef _LIST_H_
#define _LIST_H_

using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node* new_node( const int& a ){
  Node *p = new Node;
  p->data = a;
  p->next = NULL;
  return p;
}

class List{
  public:
    List() : head(NULL), tail(NULL) {};

    List( int n, const int& val ) : head(NULL), tail(NULL) {
      for ( int i = 0 ; i < n ; ++i ){
        push_back(val);
      }
    }

    ~List();

    List( const List& foo);
    Node* find( const int& a );
    void remove( Node* p );
    List& operator+=( const List& a );

    //insert node
    void push_back( const int& a );
    void push_front( const int& a );

    //remove node
    void pop_back();
    void pop_front();

    int node_no() const ;

    friend ostream& operator<<( ostream& out, const List& foo );

  private:
    Node *head, *tail;
};

List::~List(){
  Node *p;
  while( head != NULL ){
    p = head->next;
    delete head;
    head = p;
  }
}

//insert node
void List::push_back( const int& a ){
  if ( head == NULL ){
    head = new_node(a);
    tail = head;
  } else {
    tail->next = new_node(a);
    tail = tail->next;
  }
}

void List::push_front( const int& a ){
  if ( head == NULL ){
    head = new_node(a);
    tail = head;
  } else {
    Node* p = new_node(a);
    p->next = head;
    head = p;
  }
}

void List::pop_back(){
  if ( head != NULL ){
    if ( head == tail ){
      delete tail;
      head = tail = NULL;
    } else {
      Node *p = head;
      while( p->next != tail ){
        p = p->next;
      }
      delete tail;
      tail = p;
      p->next = NULL;
    }
  }
}

void List::pop_front(){
  if ( head != NULL ){
    Node *p = head->next;
    delete head;
    head = p;
    if ( head == NULL ){
      tail = NULL;
    }
  }
}

int List::node_no() const {
  Node *p = head;
  int no = 0;
  while ( p != NULL ){
    ++no;
    p = p->next;
  }
  return no;
}

ostream& operator<<( ostream& out, const List& foo ){
  Node* p;
  for ( p = foo.head ; p != NULL ; p = p->next ){
    out << p->data << " ";
  }
  return out;
}

#endif
