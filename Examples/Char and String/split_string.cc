#include <iostream>
#include <string>

int main()
{
  int i;
  std::string Q = "Must you be so linear";

  int count = 0;
  std::string word;
  std::string words[20];

  for ( i = 0 ; i < Q.size() ; ++i ){
    if ( !( (Q[i] >= 'a' && Q[i] <= 'z') || (Q[i] >= 'A' && Q[i] <= 'Z') ) ){ 
      continue;
    }
    word = "";

    do {
      word += Q[i];
      ++i;
    } while ( (Q[i] >= 'a' && Q[i] <= 'z') || (Q[i] >= 'A' && Q[i] <= 'Z' ) );

    words[count] = word;
    ++count;
  }

  for ( i = 0 ; i < count ; ++i ){
    std::cout << i+1 << " : [" << words[i] << "]\n";
  }

  return 0;
}
