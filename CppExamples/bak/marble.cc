#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

  const int M = 100000000;  // simulation number;
  int size = 3;
  int i, m, count;

  int *pos = new int [size+1];
  for ( i = 0 ; i <= size ; ++i ){
    pos[i] = 0;
  }

  for ( m = 0 ; m < M ; ++m ){
    count = 0;
    for ( i = 0 ; i < size ; ++i ){
      count += rand()%2;
    }
    ++pos[count];
  }

  /* show output */
  for ( i = 0 ; i <= size ; ++i ){
    cout << static_cast<double>(*(pos+i))/M << " ";
  }
  cout << endl;

  delete [] pos;

  return 0;
}
