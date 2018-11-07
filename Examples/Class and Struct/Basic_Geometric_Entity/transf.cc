#include "transf.h"

void Geometric_Transformation::update_transformation_matrix( double a[2][3] ){
  int i, j;
  static double tmp[2][3];
  for ( i = 0 ; i < 2 ; ++i ){
    for ( j = 0 ; j < 2 ; ++j ){
      tmp[i][j] = m[i][0]*a[0][j] + m[i][1]*a[1][j];
    }
  }
  tmp[0][2] = m[0][0]*a[0][2]+m[0][1]*a[1][2]+m[0][2];
  tmp[1][2] = m[1][0]*a[0][2]+m[1][1]*a[1][2]+m[1][2];
  for ( i = 0 ; i < 2 ; ++i ){
    for ( j = 0 ; j < 3 ; ++j ){
      a[i][j] = tmp[i][j];
    }
  }
}

Geometric_Transformation::~Geometric_Transformation(){}  

Translation::Translation( Distance x, Distance y ) : dx(x), dy(y) {
  m[0][0] = 1.; m[0][1] = 0.; m[0][2] = dx;
  m[1][0] = 0.; m[1][1] = 1.; m[1][2] = dy;
}

Transformation_Type Translation::get_transformation_type() const {
  return Transformation_Type( TRA );
}

Rotation::Rotation( Angle a ) : angle(PI*a/180) {
  double c = cos(angle), s = sin(angle);
  m[0][0] = c; m[0][1] = -s; m[0][2] = 0;
  m[1][0] = s; m[1][1] = c ; m[1][2] = 0;
}

Transformation_Type Rotation::get_transformation_type() const {
  return Transformation_Type( ROT );
}

Reflection::Reflection( Angle a ) : angle(PI*a/180) {
  double c = cos(2.*angle), s = sin(2.*angle);
  m[0][0] = c; m[0][1] = s ; m[0][2] = 0;
  m[1][0] = s; m[1][1] = -c; m[1][2] = 0;
}

Transformation_Type Reflection::get_transformation_type() const {
  return Transformation_Type( REF );
}

Point::Point(){}

Point::Point( double a, double b ) : x(a), y(b) {}

Point Point::transformation( const std::vector<Geometric_Transformation*> & gt ) const {
  double m[2][3] = { {1,0,0},{0,1,0} };

  for ( int i = 0 ; i < gt.size() ; ++i ){
    gt[i]->update_transformation_matrix(m);
  }
  return Point( m[0][0]*x+m[0][1]*y+m[0][2], m[1][0]*x+m[1][1]*y+m[1][2]);
}

std::istream& operator>>( std::istream& in, Point& pt ){
  return in >> pt.x >> pt.y;
}

std::ostream& operator<<( std::ostream& out, const Point& pt ){
  return out << "( " << pt.x << " , " << pt.y << " )";
}
