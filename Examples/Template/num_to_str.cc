#include <iostream>
#include <sstream>
#include <string>

template <class T>
std::string num_to_str(const T& x){
  std::ostringstream number;
  number << x;
  return number.str();
} 

int main(){

  int a = 10;
  std::string str = "abc";
  str += num_to_str(a);
  std::cout << str << std::endl;

  double b = 0.2;
  std::string str1 = "cde";
  str1 += num_to_str(b);
  std::cout << str1 << std::endl;

  return 0;
}
