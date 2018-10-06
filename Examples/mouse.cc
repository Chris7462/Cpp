#include <iostream>

using namespace std;

const int ROW = 13;
const int COL = 29;
int maze[ROW][COL] = {
  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
  {2,0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,0,2,0,2},
  {2,0,0,0,2,2,0,2,2,2,2,2,0,2,0,2,2,0,2,0,2,0,2,2,2,0,0,0,2},
  {2,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,2,0,2,2,2},
  {2,0,2,0,0,2,2,2,2,0,2,0,2,2,0,2,2,0,0,0,2,0,0,0,2,0,0,0,2},
  {2,2,2,2,0,0,2,0,2,0,0,0,0,0,0,2,0,0,2,2,2,0,2,0,2,0,2,0,2},
  {2,2,0,0,0,2,0,0,2,2,2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,0,2},
  {2,0,0,2,2,2,2,0,0,2,0,2,0,0,0,2,2,0,0,0,2,2,2,0,2,0,2,0,2},
  {2,2,0,0,0,0,0,2,0,0,0,2,2,2,0,0,0,2,2,0,2,0,0,0,2,0,0,0,2},
  {2,0,0,2,0,2,0,2,2,2,0,2,0,0,0,2,0,0,2,0,0,0,2,0,2,0,2,0,2},
  {2,2,2,2,0,2,0,2,0,0,0,0,0,2,0,2,2,0,2,0,2,0,2,2,2,0,2,0,2},
  {2,0,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,2},
  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

struct Point {
  int x, y;
};

Point pt(int, int);
int visit( int [][COL], Point, Point);
void print( const int [][COL] );

int main(){

  if( !visit(maze, pt(11, 1), pt(1,27)) ){
    cout << "\n沒有找到出口！\n";
  }
  print(maze);
  return 0;
}

Point pt(int x, int y){
  Point p = {x, y};
  return p;
}

int visit( int maze[][COL], Point start, Point end ){
  if ( !maze[start.x][start.y] ){
    maze[start.x][start.y] = 1;
    if( !maze[end.x][end.y] &&
        !(visit(maze, pt(start.x, start.y + 1), end) ||
          visit(maze, pt(start.x + 1, start.y), end) ||
          visit(maze, pt(start.x, start.y - 1), end) ||
          visit(maze, pt(start.x - 1, start.y), end)) ){
      maze[start.x][start.y] = 0;
    }
  }
  return maze[end.x][end.y];
}

void print( const int maze[][COL] ){
  int i, j;
  for ( i = 0 ; i < ROW ; ++i ){
    for ( j = 0 ; j < COL ; ++j ){
      switch( maze[i][j] ){
        case 0 : cout << "　";
                 break;
        case 1 : cout << "⊕ ";
                 break;
        case 2 : cout << "■ ";
                 break;
      }
    }
    cout << endl;
  }
}
