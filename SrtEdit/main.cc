#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  string line;
  ifstream infile("short.srt", ios_base::in);
  if ( infile.is_open() ){
    while ( getline(infile, line) ){
      cout << line << endl;
    }
    infile.close();
  }

  return 0;
}
