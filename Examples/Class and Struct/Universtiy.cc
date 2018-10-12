#include <iostream>
#include "University.h"

int main(){
  
  Science science;
  science.list_common_subjects();
  science.list_all_departments();

  Engineering engineering;
  engineering.list_common_subjects();
  engineering.list_all_departments();


  University university;
  university.list_all_colleges();
  university.list_all_departments_in_college();

  std::cout << Sci << std::endl;
  university.list_departments_in_college(Sci);
  std::cout << university.total_no_of_depts() << std::endl;

  return 0;
}
