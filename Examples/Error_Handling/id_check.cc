#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class ID_ERR{
  private:
    int kind;
  public:
    ID_ERR( int i ) : kind(i) {};

    const char* error_msg() const {
      switch ( kind ){
        case 0 : return "Length is wrong";
        case 1 : return "First digit must be alphabeta";
        case 2 : return "The first number must be 1 or 2";
        case 3 : return "The second number and after that must be between 0 to 9";
        case 4 : return "Number checked wrong";
      }
    }
};

bool correct_id( string id ) throw(ID_ERR) {
  static const int mozart[10] = {1,7,5,6,1,7,9,1,3,5};
  int no[10], i, tmp, sum;
  
  if ( id.size() != 10 ) throw ID_ERR(0);

  for ( i = 0 ; i < 9 ; ++i ){
    if ( i == 0 ){
      if ( ( id[0] >= 'a' ) && ( id[0] <= 'z' ) ){
        id[0] += 'A' - 'a';
      }
      if ( ( id[0] < 'A' ) || ( id[0] > 'Z' ) ) throw ID_ERR(1);

      tmp = id[0] - 'A' + 1;
      no[0] = tmp/10;
      no[1] = tmp % 10;
    } else if ( i == 1 ){
      if ( !( id[1] == '1' || id[1] == '2' ) ) throw ID_ERR(2);

      no[2] = id[1]-'0';
    } else {
      if ( id[i] < '0' || id[i] > '9' ) throw ID_ERR(3);
      no[i+1] = id[i]-'0';
    }
  } 

  sum = no[0];
  for ( i = 1 ; i < 10 ; ++i ) sum += no[i] * mozart[i];
  sum = sum % 10;

  if ( sum != ( id[9] - '0' ) ) throw ID_ERR(4);

  return true;
}

int main(){
  string id;

  while(1){
    cout << "Input ID number: ";
    cin >> id;
    try {
      if ( correct_id(id) ){
        cout << "Correct!" << endl;
      }
      return 0;
    }
    catch( const ID_ERR& e ){
      cout << "Wrong: " << e.error_msg() << endl;
    }
  }

  return 0;
}
