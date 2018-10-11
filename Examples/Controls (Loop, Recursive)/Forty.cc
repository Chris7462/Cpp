#include <iostream>
#include <iomanip>

int main(){

  int F, O, R, T, Y, E, N, S, I, X;
  int forty, ten, sixty;

  int i, j, t, y;
  for ( i = 12345 ; i < 98766 ; ++i ){
    F = i/10000;
    O = (i/1000)%10;
    if ( O == F ){ 
      continue;
    }
    R = (i/100)%10;
    if ( R == F || R == O ){
      continue;
    }
    T = (i/10)%10;
    if ( T == F || T == O || T == R ){
      continue;
    }
    Y = i%10;
    if ( Y == F || Y == O || Y == R || Y == T ){
      continue;
    }

    forty = F*10000+O*1000+R*100+T*10+Y;

    for ( j = 1 ; j < 99 ; ++j ){
      E = j/10;
      if ( E == F || E == O || E == R || E == T || E == Y ){
        continue;
      }
      N = j%10;
      if ( N == F || N == O || N == R || N == T || N == Y || N == E ){
        continue;
      }
      ten = T*100+E*10+N;

      sixty = forty+ten+ten;

      S = sixty/10000;
      I = (sixty/1000)%10;
      X = (sixty/100)%10;
      t = sixty/10%10;
      y = sixty%10;

      if ( y != Y || t != T ){
        continue;
      }

      if ( S == F || S == O || S == R || S == T || S == Y || S == E || S == N ){
        continue;
      }
      if ( I == F || I == O || I == R || I == T || I == Y || I == E || I == N || I == S ){
        continue;
      }
      if ( X == F || X == O || X == R || X == T || X == Y || X == E || X == N || X == S || X == I ){
        continue;
      }
      std::cout << std::setw(10) << forty << std::endl
        << std::setw(10) << ten << std::endl
            << std::setw(3) << " +" << std::setw(7) << ten << std::endl
            << std::setw(11) << "--------" << std::endl
            << std::setw(10) << sixty << std::endl;
    }
  }
  return 0;
}
