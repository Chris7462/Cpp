#include <iostream>
#include "University.h"

int main(){

  Science sci;
  sci.list_all_departments();
  sci.list_common_subjects();

  Engineering eng;
  eng.list_all_departments();
  eng.list_common_subjects();

  University univ;
  univ.list_all_colleges();
  univ.list_all_departments();

  std::cout << univ.get_name() << std::endl;
  univ.list_departments_in_college(Sci);
  std::cout << univ.total_no_of_departments();


  return 0;
}
