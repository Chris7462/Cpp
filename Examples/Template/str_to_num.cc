#include <iostream>
#include <sstream>
#include <string>

template <typename T>
T str_to_num(const std::string& foo ){
  T num;
  std::istringstream(foo) >> num;
  return num;
}

int main(){

  std::string foo = "3.1415926";
  double pi = str_to_num<double>(foo);
  std::cout << pi << std::endl;

  std::cout << str_to_num<int>(foo) << std::endl;

  std::string bar = "99";
  int max = str_to_num<int>(bar);
  std::cout << max << std::endl;

  return 0;
}
