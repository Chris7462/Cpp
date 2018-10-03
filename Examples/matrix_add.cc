#include <iostream>

int main()
{
  int n, i, j, k;
  std::cin >> n;

  int **M = new int* [n];
  for ( i = 0 ; i < n ; ++i ){
    M[i] = new int [n];
  }

  for ( k = 0 ; k < static_cast<int>(1.*n/2+0.5) ; ++k ){
    if ( k == 0 ){
      for ( i = 0 ; i < n ; ++i ){
        for ( j = 0 ; j < n ; ++j ){
          M[i][j] = 1;
        }
      }
    } else {
      for ( i = k ; i < n-k ; ++i ){
        for ( j = k ; j < n-k ; ++j ){
          M[i][j] += 1;
        }
      }
    }
  }

  for ( i = 0 ; i < n ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      std::cout << M[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
