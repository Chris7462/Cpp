#include <iostream>
#include <string>

int main()
{
  char weekday1[5][4] = {"mon", "tue", "wed", "thu", "fri"};
  std::string weekday2[] = {"mon", "tue", "wed", "thu", "fri"};
  char* weekday3[5] = {"mon", "tue", "wed", "thu", "fri"};

  for ( int i = 0 ; i < 5 ; ++i ){
    std::cout << weekday1[i] << std::endl;
  }
  
  for ( int i = 0 ; i < 5 ; ++i ){
    std::cout << weekday2[i] << std::endl;
  }

  return 0;
}
