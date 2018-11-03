#ifndef _SCHOOL_H_
#define _SCHOOL_H_

#include <iostream>

const int MAX_STUDENT = 10;
const int MAX_CLASS = 3;

struct Student {
  std::string name;
  int id;
};

std::ostream& operator<<(std::ostream& out, const Student& s);
std::istream& operator>>(std::istream& in, Student& s);

class Class {
  public:
    Class();
    ~Class();

    bool insert_student( const Student& s );
    int current_student_no() const;

    friend std::ostream& operator<<(std::ostream& out, const Class& c);

  private:
    Student student[MAX_STUDENT];
    int student_no;
};

class Course {
  public:
    bool add_student( int c, const Student& st );

    friend std::ostream& operator<<(std::ostream& out, const Course& foo);

  private:
    Class classes[MAX_CLASS];
};

#endif
