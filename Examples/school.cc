#include <iostream>
#include <iomanip>

const int MAX_SECTION = 3;
const int MAX_STUDENT = 10;

struct Student {
  std::string name;
  unsigned int id;
  Student(){}
  Student(std::string n, unsigned int i) : name(n), id(i) {}
};

std::ostream& operator<<(std::ostream& out, const Student& s){
  return out << std::setw(6) << s.name << " [" << s.id << "]";
}

class Section {
  private:
    Student student[MAX_STUDENT];
    int student_no;
  public:
    /* constructor */
    Section() : student_no(0) {}

    /* add function */
    bool insert_student( const Student& s ){
      if( student_no == MAX_STUDENT ){
        return false;
      } else {
        student[student_no++] = s;
        return true;
      }
    }

    int current_student_no() const { return student_no; }

    friend std::ostream& operator<<( std::ostream& out, const Section& foo ){
      for ( int i=0; i<foo.student_no; ++i ){
        out << i+1 << " : " << foo.student[i] << "\n";
      }
      return out;
    }
};

class Course {
  private:
    Section section[MAX_SECTION];
  public:
    bool add_student( int c, const Student& s ){
      if ( c < 1 || c > MAX_SECTION ){
        return false;
      } else {
        return ( section[c-1].insert_student(s) ? true : false );
      }
    }

    friend std::ostream& operator<<( std::ostream& out, const Course& foo ){
      int total_student_no = 0;
      for ( int i=0 ; i<MAX_SECTION ; ++i ){
        total_student_no += foo.section[i].current_student_no();
        out << "Section " << i+1 << ": \n" << std::left << foo.section[i] << "\n";
      }
      out << "Total enroll number: " << total_student_no << "\n";
      return out;
    }
};

int main(){


  Student a("Bob",9010), b("Chris",9011), c = {"Amy", 9012}, d= {"Pete", 9014};
//std::cout << a << std::endl;
//std::cout << b << std::endl;
//std::cout << c << std::endl;
//std::cout << d << std::endl;

  Course stat;
  stat.add_student(1,a);
  stat.add_student(2,b);
  stat.add_student(2,c);
  stat.add_student(3,d);

  std::cout << stat << std::endl;

  return 0;
}
