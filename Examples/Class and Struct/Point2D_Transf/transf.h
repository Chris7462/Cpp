#ifndef _TRANSF_H_
#define _TRANSF_H_

#include <iostream>
#include <cmath>
#include <vector>

typedef double Angle;
typedef double Length;
typedef double Distance;

const double PI = 3.14159265358979;

enum Transformation_Type { TRA, ROT, REF };

class Geometric_Transformation {
  public:
    void update_transformation_matrix( double a[2][3] );
    virtual Transformation_Type get_transformation_type() const = 0;
    virtual ~Geometric_Transformation();
  protected:
    double m[2][3];
};

class Translation : public Geometric_Transformation {
  public:
    Translation( Distance x, Distance y );
    Transformation_Type get_transformation_type() const;
  private:
    Distance dx, dy;
};

class Rotation : public Geometric_Transformation {
  public:
    Rotation( Angle a );
    Transformation_Type get_transformation_type() const;
  private:
    Angle angle;
};

class Reflection : public Geometric_Transformation {
  public:
    Reflection( Angle a );
    Transformation_Type get_transformation_type() const;
  private:
    Angle angle;
};

class Point {
  public:
    Point();
    Point( double a, double b );
    Point transformation( const std::vector<Geometric_Transformation*>& gt ) const;
    friend std::istream& operator>>( std::istream& in, Point& pt );
    friend std::ostream& operator<<( std::ostream& out, const Point& pt);
  private:
    double x,y;
};

#endif
