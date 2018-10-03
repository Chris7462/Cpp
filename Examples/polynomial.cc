#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  int n;
  std::cout << "Input the degree of polynomial: ";
  std::cin >> n;

  int i, j;

  int *pc = new int [n+1];
  int *pd = new int [n+1];
  int *pe = new int [2*n+1];

  // set random seed
  srand( static_cast<unsigned int>( time(NULL) ) );

  // generate random number 
  for ( i = 0 ; i < n+1 ; ++i ){
    pc[i] = rand()%10+1;
    pd[i] = rand()%10+1;
  }

  std::cout << "f(x) = " << pc[0];
  for ( i = 1 ; i < n+1 ; ++i ){
    std::cout << " + " << pc[i] << "x^" << i;
  }
  std::cout << std::endl;

  std::cout << "g(x) = " << pd[0];
  for ( i = 1 ; i < n+1 ; ++i ){
    std::cout << " + " << pd[i] << "x^" << i;
  }
  std::cout << std::endl;

  // initialize pe
  for ( i = 0 ; i < 2*n+1 ; ++i ){
    pe[i] = 0;
  }

  for ( i = 0 ; i < n+1 ; ++i ){
    for ( j = 0 ; j < n+1 ; ++j ){
      pe[i+j] += pc[i]*pd[j];
    }
  }

  std::cout << "e(x) = " << pe[0];
  for ( i = 1 ; i < 2*n+1 ; ++i ){
    std::cout << " + " << pe[i] << "x^" << i;
  }
  std::cout << std::endl;

  // derivative
  std::cout << "f'(x) = " << pc[1];
  for ( i = 2 ; i < n+1 ; ++i ){
    std::cout << " + " << i*pc[i] << "x^" << i-1;
  }
  std::cout << std::endl;

//std::cout << "(f+g)(x) = " << pc[0]+pd[0];
//for ( i = 1 ; i < n+1 ; ++i ){
//  std::cout << " + " << pc[i]+pd[i] << "x^" << i;
//}
//std::cout << std::endl;

  delete [] pc;
  delete [] pd;
  delete [] pe;

  return 0;
}
