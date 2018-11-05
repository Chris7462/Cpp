#include <iostream>
#include "University.h"

int main()
{
  Science sci;
  sci.list_all_departments();
  sci.list_common_subjects();
  std::cout << std::endl;

  Engineering eng;
  eng.list_all_departments();
  eng.list_common_subjects();
  std::cout << std::endl;

  University foo;
  foo.list_all_colleges();
  foo.list_all_departments();

  std::cout << "> " << foo.get_university_name() << "\tNo of depts: " << foo.total_no_of_departments() << std::endl;

  foo.list_departments_in_college(Sci);

  return 0;
}
