#include <iostream>
#include <cmath>

#define PI 3.14159265

int main()
{
  const int m = 24;
  const int n = 80;
  char MAT[m][n] = {' '};

  int i, j;
  double x, y;

  // initialize the matrix
  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      MAT[i][j] = ' ';
    }
  }

  // setting the x-boundary
  for ( j = 0 ; j < n ; ++j ){
    MAT[0][j] = '*';
    MAT[m-1][j] = '*';
  }

  // setting the y-boundary
  for ( i = 0 ; i < m ; ++i ){
    MAT[i][0] = '*';
    MAT[i][n-1] = '*';
  }

  // set x-axis
  MAT[12][n-1] = 'X';
  MAT[12][n-2] = '>';
  for ( j = 1 ; j < n-2 ; ++j ){
    MAT[12][j] = '-';
  }
  
  // set y-axis
  MAT[0][40] = 'Y';
  for ( i = 1 ; i < m-1 ; ++i ){
    MAT[i][40] = '|';
  }

  // calculate cosine function
  for ( j = 1 ; j < 79 ; ++j ){
    x = (20.0*j-790)/77;
    y = cos(x);
    i = -(21*y-23)/2;
    //std::cout << x << "\t" << y << "\t" << i << std::endl;
    MAT[i][j] = '*';
  }

  for ( i = 0 ; i < m ; ++i ){
    for ( j = 0 ; j < n ; ++j ){
      std::cout << MAT[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
