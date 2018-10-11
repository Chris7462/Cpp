#include <iostream>

int main()
{
  const int n = 5;
  int *a = new int[n];
  int *b = new int[n];
  int **M = new int*[n];

  int i, j;
  for ( i = 0 ; i < n ; ++i ){
    a[i] = i+1;
    b[i] = n-i;
    M[i] = new int[n];
  }

  for ( i = 0 ; i < n ; ++i ){
    std::cout << a[i] << std::endl;
  }

  for ( i = 0 ; i < n ; ++i ){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;

  for ( i = 0 ; i < n ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      M[i][j] = a[i]*b[j];
      std::cout << M[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for ( i = 0 ; i < n ; ++i ){
    delete [] M[i];
  }

  delete [] a;
  delete [] b;
//delete [] M;

  return 0;
}
