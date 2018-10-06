#include <iostream>
#include <string>

using namespace std;

const int ROW = 5, COL = 5;

void build_bitmap( const string& , string *);

int main()
{
  int i, j, bit;
  string no="1", bitmap[ROW];
  
  build_bitmap(no, bitmap);

  for ( i = 0 ; i < ROW ; ++i ){
    cout << bitmap[i] << endl;
  }
  
  //string no, bitmap[ROW];
  //cin >> no;

//for ( i = 0 ; i < ROW ; ++i ){
//  bit = bitmap[0][i];
//  for ( j = 0 ; j < COL ; ++j ){
//    cout << (bit & (16>>j) ? "*" : " ");
//  }
//  cout << endl;
//}

  return 0;
}

void build_bitmap( const string& no, string * bitmap ){
  unsigned char no_bitmap[10][ROW] = { {14,17,17,17,14}, {12,20,4,4,31},//{4,12,20,4,31}, 
    {14,17,2,4,31}, {30,1,14,1,30}, {2,6,10,31,2}, {31,16,30,1,30},
    {15,16,30,17,14}, {31,1,2,4,8}, {14,17,14,17,14}, {14,17,15,1,30} };

  int i, n, r, c;
  for ( r = 0 ; r < ROW ; ++r ){
    for ( i = 0 ; i < no.size() ; ++i ){
      n = no_bitmap[no[i]-'0'][r];
      //for ( c = 0 ; c < COL ; ++c ){
      for ( c = COL-1 ; c >= 0 ; --c ){
        //bitmap[r] += ( n & (16>>c) ? '*' : ' ');
        bitmap[r] += ( n & (1<<c) ? '*' : ' ');
      }
      bitmap[r] += "  ";
    }
  }

}
