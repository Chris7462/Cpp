#ifndef _POLYGON_H_
#define _POLYGON_H_

const int MAX_VERTEX=10;
const int TRIANGLE_VERTEX=3;
const int RECTANGLE_VERTEX=4;

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double a, double b) : x(a), y(b) {}
};

std::ostream& operator<<(std::ostream& out, const Point& foo){
  out << "(" << foo.x << "," << foo.y << ")";
  return out;
}

// polygon is an abstract class
class Polygon {
  protected:
    Point *vertex;
  public:
  //friend std::ostream& operator<<(std::ostream& out, const Polygon& foo ){

  //}
};

class Triangle : public Polygon {
  public:
    Triangle(){ vertex = new Point [TRIANGLE_VERTEX]; }
    Triangle(const Point& pt1, const Point& pt2, const Point& pt3 ){
      vertex = new Point [TRIANGLE_VERTEX];
      vertex[0] = pt1;
      vertex[1] = pt2;
      vertex[2] = pt3;
    }
    ~Triangle(){ delete [] vertex; }
};

#endif
