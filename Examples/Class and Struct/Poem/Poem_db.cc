#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

typedef std::string Poet;
typedef std::string Name;
typedef std::string Content;

struct Poem {
  Poet poet;
  Name name;
  Content content;
};

std::istream& operator>>(std::istream& in, Poem& poem){
  std::string content;
  in >> poem.poet >> poem.name >> poem.content;
  while ( in >> content ) {
    poem.content += " " + content;
  }
  return in;
}

std::ostream& operator<<(std::ostream& out, const Poem& poem){
  out << poem.poet << " " << poem.name << "\n" << poem.content;
  return out;
}

class Tang_Poem{
  private:
    std::vector<Poem> five;
    std::vector<Poem> seven;
  public:
    Tang_Poem( const char* poem5, const char* poem7 ){
      std::ifstream infile1(poem5), infile2(poem7);
      std::string line;

      Poem poem;
      std::istringstream poem_entry;

      while( getline(infile1, line) ){
        poem_entry.str(line);
        poem_entry >> poem;
        five.push_back(poem);
        poem_entry.clear();
      }

      while( getline(infile2, line) ){
        poem_entry.str(line);
        poem_entry >> poem;
        five.push_back(poem);
        poem_entry.clear();
      }
    }

    std::vector<Poem> search_poet( const Poet& poet ) const {
      int i;
      std::vector<Poem> poems;
      for ( i = 0; i<five.size(); ++i ){
        if ( five[i].poet == poet ) poems.push_back(five[i]);
      }

      for ( i = 0; i<seven.size(); ++i ){
        if ( seven[i].poet == poet ) poems.push_back(seven[i]);
      }
      return poems;
    }
};

int main(){

  Tang_Poem poem_db("five_poem_utf8.db", "seven_poem_utf8.db");

  Poet poet;
  std::vector<Poem> poems;

  int i;

  while(1){
    std::cout << "Input name: ";
    std::cin >> poet;

    poems = poem_db.search_poet( poet );

    for( i=0 ; i<poems.size() ; ++i ){
      std::cout << "\n" << poems[i] << "\n";
    }
    std::cout << std::endl;
  }

  return 0;
}
