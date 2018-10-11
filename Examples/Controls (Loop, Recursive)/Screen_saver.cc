#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
  const int ROW = 24;
  const int COL = 80;

  int i, row, col, color;

  srand( static_cast<unsigned>(time(NULL)) );

  std::cout << "\x1b[2J" << std::flush;

  while(1){
    row = rand() % ROW + 1;
    col = rand() % COL + 1;
    color = rand() % 8;

    std::cout << "\x1b[" << row << ";" << col << "H" << "\x1b[" << 4 << color << "m" << " " << "\x1b[0m" << std::flush;

    for ( i = 0 ; i < 100000; ++i );
  }

  return 0;
}
