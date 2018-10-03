#include <iostream>

int main()
{
  int i, j, n = 5;
  int **M = new int*[n];

  for ( i = 0 ; i < n ; ++i ){
    M[i] = new int [n-i];
  }

  M[0][0] = 1;
  M[0][1] = 3;
  M[0][2] = 8;
  M[0][3] = 11;
  M[0][4] = 12;

  for ( j = 0 ; j < n ; ++j ){
    std::cout << M[0][j] << " ";
  }
  std::cout << std::endl;

  for ( i = 1 ; i < n ; ++i ){
    for ( j = 0 ; j < n-i ; ++j ){
      M[i][j] = M[i-1][j+1]-M[i-1][j];
      std::cout << M[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for ( i = 0 ; i < n ; ++i ){
    delete [] M[i];
  }

  delete [] M;

  return 0;
}
