#ifndef _GEOMETRIC_H_
#define _GEOMETRIC_H_

#include <cmath>

enum Color {red, green, blue, cyan, yellow };

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point( double a, double b ) : x(a), y(b) {}
  Point( const Point& foo ){
    x = foo.x;
    y = foo.y;
  }
};

std::ostream& operator<<(std::ostream& out, const Point& foo){
  out << "(" << foo.x << "," << foo.y << ")";
  return out;
}

class Geometric_Entity {
  protected:
    Color entity_color;
  public:
    Color display_color() const { return entity_color; }
    virtual std::string name() const = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    double length(Point pta, Point ptb) const { 
      return sqrt(pow((pta.x-ptb.x),2)+pow((pta.y-ptb.y),2)); 
    }

    friend std::ostream& operator<<(std::ostream& out, const Geometric_Entity& foo){
      out << "Name: " << foo.name() 
        << ", Color: " << foo.display_color() 
        << ", Perimeter: " <<  foo.perimeter()
        << ", Area: " << foo.area();
      return out;
    }
};

class Circle : public Geometric_Entity {
  private:
    Point center;
    double radius;
  public:
    Circle(){ entity_color = red; }
    Circle(Point o, double r=1) : center(o), radius(r) { entity_color = red; }
    virtual std::string name() const { return "Circle"; }
    virtual double perimeter() const { return 2*M_PI*radius; }
    virtual double area() const { return M_PI*radius*radius; }
};

class Triangle : public Geometric_Entity {
  private:
    Point pt1, pt2, pt3;
  public:
    Triangle(){ entity_color = green; }
    Triangle(Point x, Point y, Point z) : pt1(x), pt2(y), pt3(z) { entity_color = green; }

    virtual std::string name() const { return "Triangle"; }
    virtual double perimeter() const { 
      return (length(pt1,pt2)+length(pt1,pt3)+length(pt2,pt3));
    } 
    virtual double area() const { 
      double a=length(pt1,pt2), b=length(pt1,pt3), c=length(pt2,pt3);
      double s=(a+b+c)/2;
      return sqrt(s*(s-a)*(s-b)*(s-c)); 
    }
};

class Rectangle : public Geometric_Entity {
  private:
    Point pt1, pt2, pt3, pt4;
  public:
    Rectangle(){ entity_color = blue; }
    Rectangle(Point w, Point x, Point y, Point z ) : pt1(w), pt2(x), pt3(y), pt4(z) { entity_color = blue; }
    virtual std::string name() const { return "Rectangle"; }
    virtual double perimeter() const {
      return (length(pt1,pt2)+length(pt2,pt3)+length(pt3,pt4)+length(pt4,pt1));
    }
    virtual double area() const {
      double a=length(pt1,pt2), b=length(pt2,pt3);
      return a*b;
    }
};

#endif
