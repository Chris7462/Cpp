#include <iostream>
#include <string>

int main()
{
  int bitmap[26][5] = {
    {6,9,15,9,9}, {14,9,14,9,14}, {6,9,8,9,6},
    {14,9,9,9,14}, {15,8,14,8,15}, {15,8,14,8,8},
    {7,8,11,9,6}, {9,9,15,9,9}, {7,2,2,2,7},
    {7,2,2,10,14}, {9,10,12,10,9}, {8,8,8,9,15},
    {9,15,9,9,9}, {9,13,11,9,9}, {6,9,9,9,6},
    {14,9,14,8,8}, {15,9,13,11,15}, {14,9,14,10,9},
    {7,8,6,1,14}, {15,2,2,2,2}, {9,9,9,9,15},
    {9,9,9,9,6}, {9,9,9,15,9}, {9,9,6,9,9}, 
    {9,9,7,1,14}, {15,1,2,4,15}
  };

  int i, j, no, k, bit;

  std::string word;
  std::cout << "Input a word : ";
  std::cin >> word;
  std::cout << std::endl;

  std::string line_map;
  std::string tmp = " ";

  for ( i = 0 ; i < 5 ; ++i ){
    for ( j = 0 ; j < word.size() ; ++j ){
      no = word[j] - 'A';
      bit = bitmap[no][i];
      
      tmp += word[j];
      for ( k = 0 ; k < 4 ; ++k ){
        //line_map += ( bit & (8>>k) ? word[j] : "  " );
        line_map += ( bit & (8>>k) ? tmp : "  " );
      }
      line_map += ' ';
      tmp = " ";
    }
    std::cout << line_map << std::endl;
    line_map = "";
  }

  return 0;
}
