#include "School.h"

std::ostream& operator<<(std::ostream& out, const Student& s){
  return (out << s.id << "\t" << s.name);
}

std::istream& operator>>(std::istream& in, Student& s){
  return (in >> s.id >> s.name);
}

Class::Class() : student_no(0) {}
Class::~Class(){}

bool Class::insert_student( const Student& s ){
  if ( student_no == MAX_STUDENT ){
    std::cout << "Insert fail! Can't have more student" << std::endl;
    return false;
  } else {
    student[student_no] = s;
    ++student_no;
    return true;
  }
}

int Class::current_student_no() const {
  return student_no;
}

std::ostream& operator<<(std::ostream& out, const Class& c){
  for ( int i = 0 ; i < c.student_no ; ++i ){
    out << c.student[i] << std::endl;
  }
  return out;
}

bool Course::add_student( int c, const Student& st ){
  if ( c < 1 || c > MAX_CLASS ){
    return false;
  } else {
    return ( classes[c-1].insert_student(st) ? true : false );
  }
}

std::ostream& operator<<(std::ostream& out, const Course& foo){
  int total_student_no = 0;
  
  for ( int i = 0 ; i < MAX_CLASS ; ++i ){
    total_student_no += foo.classes[i].current_student_no();
    out << "Class " << i+1 << "\n" << foo.classes[i] << std::endl;
  }
  out << "Total students = " << total_student_no << std::endl;
  return out;
}

