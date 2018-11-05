#ifndef _UNIVERISTY_H_
#define _UNIVERSITY_H_

#include <iostream>
#include <string>
#include <vector>

enum Colleges { Sci, Eng, Mgt, Ife, Eth };

typedef std::string Name;

class College {
  public:
    virtual ~College();
    virtual void list_common_subjects() const = 0;
//    virtual void list_common_subjects() const;
    void list_all_departments() const;
    Name get_college_name() const;
    int get_dept_no() const;
  protected:
    Name name;
    std::vector<Name> depts;
};

class Science : public College {
  public:
    Science();
    void list_common_subjects() const;
};

class Engineering : public College {
  public:
    Engineering();
    void list_common_subjects() const;
};

class University {
  public:
    University();
    ~University();
    void list_all_colleges() const;
    void list_all_departments() const;
    Name get_university_name() const;
    void list_departments_in_college( const Colleges& college ) const;
    int total_no_of_departments() const;

  private:
    Name name;
    std::vector<College*> colleges;
};


#endif
