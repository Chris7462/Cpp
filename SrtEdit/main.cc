#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned int Index;
typedef string Timestamp;
typedef string Content;

struct Data {
  Index index;
  Timestamp timestamp;
  Content content;
};

//class Subtitle {
//  public:
//    Subtitle( const char* file ){
//      ifstream infile(file);
//      string line;

//      Data data;
//      istringstream data_entry;

//      while ( getline(infile, line) ){

//      }
//    }
//  private:
//    vector<Data> subtitle;
//}

int main(){

  string line;
  //ifstream infile("short.srt", ios_base::in);
  ifstream infile("short.srt");
  //if ( infile.is_open() ){
  while ( getline(infile, line) ){
    cout << line << endl;
  }
  //infile.close();
  //}

  return 0;
}
