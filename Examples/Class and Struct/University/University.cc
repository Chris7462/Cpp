#include "University.h"

College::~College(){}

// If College is not pure abstruct class, then we need to define this function
void College::list_common_subjects() const {
  std::cout << " " << name << " Common subjects: None" << std::endl;
}

void College::list_all_departments() const {
  std::cout << "> " << name << ": ";
  for ( int i = 0 ; i < depts.size() ; ++i ){
    std::cout << depts[i] << " ";
  }
  std::cout << std::endl;
}

Name College::get_college_name() const {
  return name;
}

int College::get_dept_no() const {
  return depts.size();
}

Science::Science(){
  name = "Science";
  depts.push_back("Math");
  depts.push_back("Chem");
  depts.push_back("Phsy");
  depts.push_back("Life");
}

void Science::list_common_subjects() const {
  std::cout << " " << name << " Common subjects: Calculus, Physis" << std::endl;
}

Engineering::Engineering(){
  name = "Engineer";
  depts.push_back("Civil Eng");
  depts.push_back("Mech Eng");
  depts.push_back("Chem Eng");
}

void Engineering::list_common_subjects() const {
  College::list_common_subjects();
}

University::University() : name("Foo") {
  colleges.push_back(new Science);
  colleges.push_back(new Engineering);
}

University::~University(){
  for ( int i = 0 ; i < colleges.size() ; ++i ){
    delete colleges[i];
  }
  colleges.clear();
}

void University::list_all_colleges() const {
  std::cout << " " << name << "'s college: { ";
  for ( int i = 0 ; i < colleges.size() ; ++i ){
    std::cout << colleges[i]->get_college_name() << " ";
  }
  std::cout << "}" << std::endl;
}

void University::list_all_departments() const {
  std::cout << " " << name << "'s departments: \n";
  for ( int i = 0 ; i < colleges.size() ; ++i ){
    std::cout << "\t" << i+1;
    colleges[i]->list_all_departments();
  }
  std::cout << std::endl;
}

Name University::get_university_name() const {
  return name;
}

void University::list_departments_in_college( const Colleges& college ) const {
  colleges[college]->list_all_departments();
}

int University::total_no_of_departments() const {
  int total = 0;
  for ( int i = 0 ; i < colleges.size() ; ++i ){
    total += colleges[i]->get_dept_no();
  }
  return total;
}
