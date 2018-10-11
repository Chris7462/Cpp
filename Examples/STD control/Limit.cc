#include <iostream>
#include <limits>

int main(){
  std::cout << std::numeric_limits<int>::max() << "\t" << std::numeric_limits<int>::min() << std::endl;
  std::cout << std::numeric_limits<unsigned int>::max() << "\t" << std::numeric_limits<unsigned int>::min() << std::endl;
  std::cout << std::numeric_limits<long long int>::max() << "\t" << std::numeric_limits<long long int>::min() << std::endl;
  std::cout << std::numeric_limits<float>::max() << "\t" << std::numeric_limits<float>::min() << std::endl;
  std::cout << std::numeric_limits<double>::max() << "\t" << std::numeric_limits<double>::min() << std::endl;
  return 0;
}
