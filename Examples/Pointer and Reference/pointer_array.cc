#include <iostream>

int main()
{
  const char * arr[] = {"Space", "The", "Final", "Frontier"};
  int i, j, n = sizeof(arr)/sizeof(char*);

  for ( i = 0 ; i < n ; ++i ){
    for ( j = 0 ; arr[i][j] != '\0' ; ++j ){
      std::cout << arr[i][j] << " ";
      //std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}
