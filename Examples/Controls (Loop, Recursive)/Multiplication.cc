#include <iostream>
#include <iomanip>

int main(){

  int a, b, c;
  std::cin >> a >> b;
  
  std::cout << std::setw(7) << a << std::endl
            << std::setw(2) << "x" << std::setw(5) << b << std::endl
            << std::setw(7) << "-------" << std::endl;
  
  int no = b, i = 0;
  while(no){
    c = no % 10 ;
    no = no / 10;
    if ( c ){
      std::cout << std::setw(7-i) << a*c << std::endl; 
    }
    ++i;
  }
  std::cout << std::setw(7) << "-------" << std::endl
            << std::setw(7) << a*b << std::endl;

  return 0;
}
