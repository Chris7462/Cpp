#ifndef _BGE_H_
#define _BGE_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "transf.h"

class Basic_Geometric_Entity {
  public:
    virtual Basic_Geometric_Entity* transformation( const std::vector<Geometric_Transformation*>& geotrs ) const = 0;

    virtual Basic_Geometric_Entity* clone() const = 0;
    virtual ostream& print(ostream& out) const = 0;
    virtual ~Basic_Geometric_Entity(){}
    friend ostream& operator<<(ostream& out, const Basic_Geometric_Entity& bge ){
      return bge.print(out);
    }
};

class Line : public Basic_Geometric_Entity {
  public:
    Line( const Point& a, const Point& b) : p(a), p(b) {}
    virtual Line* transformation(const std::vector<Geometric_Transformation*>& geotrs ) const;
  private:
    Point p, q;
}

#endif
