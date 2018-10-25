#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

struct Node;

Node* new_node(const int& a);

class List
{
  public:
    //constructor
    List();
    ~List();

    // add element in the node
    void push_back( const int& a );
    void push_front( const int& a );

    // remove element in the node
    void pop_back();
    void pop_front();

    // count the number of node
    int node_no() const ;

    // print elements in the list
    friend std::ostream& operator<<( std::ostream& out, const List& foo );

  private:
    Node *head, *tail;
};

#endif
