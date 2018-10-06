#include <iostream>
#include <string>

using namespace std;

const int ROW = 5;
const int COL = 5;

const unsigned char no_bitmap[10][ROW] = { {14,17,17,17,14}, 
  {4,12,4,4,31}, {14,17,2,4,31}, {30,1,14,1,30},
  {2,6,10,31,2}, {30,16,30,1,30}, {14,16,30,17,14},
  {31,1,2,4,8}, {14,17,14,17,14}, {14,17,15,1,14}
};

void initialize( const string &, string * );

void print_map( const string * );

void clean_map( string * );

int main()
{
  string str, bitmap[ROW];
  cout << "Input a number string: ";
  cin >> str;
  cout << endl;

  // initialize the map
  initialize(str, bitmap);

  // output the map
  print_map(bitmap);

  // clean the map
  clean_map(bitmap);
  print_map(bitmap);
  
  return 0;
}

void initialize( const string & str, string map[] ){
  int r, c, no, bit;
  for ( r = 0 ; r < ROW ; ++r ){
    map[r] = "";
    for ( no = 0 ; no < str.length() ; ++no ){
      bit = no_bitmap[str[no]-'0'][r];
      for ( c = COL-1 ; c >= 0 ; --c ){
        map[r] += ( bit & ( 1 << c ) ? "*" : " " );
      }
      map[r] += "  ";
    }
  }
}

void print_map( const string *map ){
  for ( int r = 0 ; r < ROW ; ++r ){
    cout << map[r] << endl;
  }
}

void clean_map( string *map ){
  for ( int r = 0 ; r < ROW ; ++r ){
    map[r] = "";
  }
}
