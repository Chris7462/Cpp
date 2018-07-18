#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <vector>

enum Colleges { Sci, Eng, Mgt, Ife, Eth };
typedef std::string Name;

//class University {
//  
//};

class College {
  protected:
    Name name;
    std::vector<Name> depts;
  public:
    virtual void list_common_subjects() const = 0;

    void list_all_departments() const {
      std::cout << name << ": ";
      for( int i=0 ; i<depts.size() ; ++i ){
        std::cout << depts[i] << " ";
      }
      std::cout << std::endl;
    }

    Name get_college_name() const { return name; }

    int get_dept_no() const { return depts.size(); }
    
    virtual ~College(){}
};

void College::list_common_subjects() const {
  std::cout << name << ": No common subjects" << std::endl;
}

class Science : public College {
  public:
    Science(){ 
      name = "College of Science"; 
      depts.push_back("Math");
      depts.push_back("Chem");
      depts.push_back("Phy");
    }

    virtual void list_common_subjects() const {
      std::cout << name << ": Calculus and Physics" << std::endl;
    }
};

class Engineering : public College {
  public:
    Engineering(){ 
      name = "College of Engineering"; 
      depts.push_back("ME");
      depts.push_back("MC");
      depts.push_back("CE");
    }

    virtual void list_common_subjects() const {
      College::list_common_subjects();
    }
};

class University {
  private:
    Name name;
    std::vector<College*> colleges;
  public:
    University() : name("MSU") {
      colleges.push_back(new Science);
      colleges.push_back(new Engineering);
    }
    ~University(){ 
      for(int i=0; i<colleges.size(); ++i ){
        delete colleges[i];
      }
    }

    void list_all_colleges() const {
      std::cout << name << " has: " << std::endl;
      for ( int i=0 ; i<colleges.size() ; ++i ){
        std::cout << colleges[i]->get_college_name() << std::endl;
      }
    }

    void list_all_departments_in_college(){
      for ( int i=0 ; i<colleges.size() ; ++i ){
        colleges[i]->list_all_departments();
      }
    }

    void list_departments_in_college( const Colleges& college ) const {
      colleges[college]->list_all_departments();
		}

		int total_no_of_depts() const {
			int no=0;
			for ( int i=0 ; i<colleges.size() ; ++i ){
        no += colleges[i]->get_dept_no();
			}
      return no;
		}

};

#endif
