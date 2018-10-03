#include <iostream>
#include <string>

int main()
{
  std::string str = "gninrael gnimmargorp egaugnal sekat ynam ecitcarp";
  int i, j;

  int count = 0;
  std::string word;
  std::string words[20];

  for ( i = 0 ; i < str.size() ; ++i ){
    if (  !( ( str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >= 'A' && str[i] <= 'Z' ) ) ){
      continue;
    }

    word = "";
    do {
      word += str[i];
      ++i;
    } while ( ( str[i] >= 'a' && str[i] <= 'z' ) || ( str[i] >= 'A' && str[i] <= 'Z' ) ); 

    words[count] = word;
    ++count;
  }

  for ( i = 0 ; i < count ; ++i ){
    for ( j = words[i].size()-1 ; j >= 0 ; --j ){
      std::cout << words[i][j];
    } 
    std::cout << " ";
  }
  std::cout << std::endl;

  return 0;
}
