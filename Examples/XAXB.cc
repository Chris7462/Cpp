#include <iostream>

int main(){

  int num1, num2;
  std::cout << "Input num1: ";
  std::cin >> num1;
  std::cout << "Input num2: ";
  std::cin >> num2;
  int i, j, n = 4;
  int vec1[n], vec2[n];
  
  vec1[0] = num1 / 1000;
  vec1[1] = num1 / 100 % 10;
  vec1[2] = num1 / 10 % 10;
  vec1[3] = num1 / 1 % 10;

  vec2[0] = num2 / 1000;
  vec2[1] = num2 / 100 % 10;
  vec2[2] = num2 / 10 % 10;
  vec2[3] = num2 / 1 % 10;

  int A = 0, B = 0;
  for ( i = 0 ; i < n ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      if ( vec1[i] == vec2[j] ){
        if ( i == j ){
          ++A;
        } else {
          ++B;
        }
      }
    }
  }

  std::cout << A << "A" << B << "B" << std::endl;

  return 0;
}
