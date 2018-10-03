#include <iostream>
#include <string>

int main()
{
  int i, sum;
  std::string str;
  std::cin >> str;

  sum = 0;
  for ( i = 0 ; i < str.size() ; ++i ){
    sum += static_cast<int>(str[i]-'a'+1);
  }
  std::cout << sum << std::endl;

  return 0;
}
