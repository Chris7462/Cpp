#include <iostream>

int main(){

  int i, j, k;
  const int m=2, n=3;

  // allocate memory for matrix A and B
  int **A = new int* [m];
  int **B = new int* [n];
  int **M = new int* [m];

  for ( i = 0 ; i < m ; ++i ){
    A[i] = new int [n];
  }

  for ( j = 0 ; j < n ; ++j ){
    B[j] = new int [m];
  }

  for ( i = 0 ; i < m ; ++i ){
    M[i] = new int [m];
  }

  // assign values
  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      A[i][j] = i+j;
    }
  }

  for ( j = 0 ; j < n ; ++j ){
    for ( i = 0 ; i < m ; ++i ){
      B[j][i] = j+i;
    }
  }

  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < m ; ++j ){
      M[i][j] = 0;
    }
  }

  // output the matrix
  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }

  for ( j = 0 ; j < n ; ++j ){
    for ( i = 0 ; i < m ; ++i ){
      std::cout << B[j][i] << " ";
    }
    std::cout << std::endl;
  }
  
  for ( i = 0 ; i < m ; ++i ){
    for ( k = 0 ; k < n ; ++k ){
      for ( j = 0 ; j < m ; ++j ){
        M[i][j] += A[i][k]*B[k][j];
      }
    }
  }

  for ( j = 0 ; j < m ; ++j ){
    for ( i = 0 ; i < m ; ++i ){
      std::cout << M[j][i] << " ";
    }
    std::cout << std::endl;
  }


  // free the memory
  for ( i = 0 ; i < m ; ++i ){
    delete [] A[i];
  }

  for ( j = 0 ; j < n ; ++j ){
    delete [] B[j];
  }

  for ( i = 0 ; i < m ; ++i ){
    delete [] M[i];
  }

  delete [] A;
  delete [] B;
  delete [] M;

  return 0;
}
