#include <iostream>
#include <cmath>

struct Point {
  double x, y;
  Point(double a, double b) : x(a), y(b) {}
};

enum Color { red, green, blue, cyan, yellow };

class Geometric_Entity {
  protected:
    Color entity_color;
  public:
    virtual double area() const = 0;
};

class Triangle : public Geometric_Entity {
  private:
    Point pt1, pt2, pt3;
  public:
    //Triangle(){}
  //Triangle(Point a, Point b, Point c){
  //  pt1(a);
  //}
    virtual double area() const {
      double a = sqrt(pow((pt1.x-pt2.x),2)+pow((pt1.y-pt2.y),2));
      return a;
    }
};

class Circle : public Geometric_Entity {
  private:
    Point center;
    double radius;
  public:
    virtual double area() const { return 0; }
};

double print_area( const Geometric_Entity& foo ){
  std::cout << foo.area() << std::endl;
}

int main(){
//  Geometric_Entity cc; 
  Point pt1(1,0), pt2(0,1), pt3(0,0);
//Triangle traingle(pt1,pt2,pt3);

  std::cout << M_PI << std::endl;
  return 0;
}
