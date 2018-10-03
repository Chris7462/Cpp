#include <iostream>

int main(){
  char ch;
  while ( 1 ){
    std::cout << "Input char: ";
    std::cin >> ch;

    ch = ( ch < 'n' ? ch+13 : ch-13 );

    std::cout << ch << std::endl;
  }

  return 0;
}
