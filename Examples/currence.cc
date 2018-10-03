#include <iostream>

int main(){
  double currence[] = {4.294, 33.49, 0.2786, 1, 4.046, 33.03, 51.3};
  int i, j, n = sizeof(currence)/sizeof(double);

  for ( i = 0 ; i < n ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      std::cout << currence[j]/currence[i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
