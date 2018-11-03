#include <iostream>
#include "School.h"

int main(){

  Course foo;
  int c;
  Student s;
  std::cout << "Input c, id, name\n";
  while(1){
    std::cin >> c;
    if ( c == 0 ) break;
    std::cin >> s;
    foo.add_student(c,s);
  }

  std::cout << "\n" << foo << std::endl;

  return 0;
}

