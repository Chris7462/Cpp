#include <iostream>
#include <vector>

struct Point {
  double x,y;
  Point(){}
  Point(double a, double b) : x(a), y(b) {}
  ~Point(){};
};

class Polygon {
  protected:
    std::vector<Point> vertex;
  public:
    int vertex_no() const { return vertex.size(); }
    virtual std::string name() const { return "Polygon"; }
    Point geometrical_center() const;
    friend std::ostream& operator<<(std::ostream& out, const Polygon& foo) ;
    virtual ~Polygon(){ std::cout << "De-Polygon" << std::endl; }
};

class Triangle : public Polygon {
  public:
    Triangle(){}
    Triangle(Point pt1, Point pt2, Point pt3){ vertex.push_back(pt1); vertex.push_back(pt2); vertex.push_back(pt3); }
    virtual std::string name() const { return "Triangle"; }
    ~Triangle(){ std::cout << "De-Triangle" << std::endl; }
};

class Rectangle : public Polygon {
  public:
    Rectangle(){}
    Rectangle(Point pt1, Point pt2, Point pt3, Point pt4){ vertex.push_back(pt1); vertex.push_back(pt2); vertex.push_back(pt3); vertex.push_back(pt4); }
    virtual std::string name() const { return "Rectangle"; }
    ~Rectangle(){ std::cout << "De-Rectangle" << std::endl; }
};

int main(){

  Point o(0,0), a(1,0), b(0,1), c(1,1);
  Triangle triangle(o,a,b);
  std::cout << triangle << std::endl;

  Rectangle rectangle(o,a,c,b);
  std::cout << rectangle << std::endl;

  Triangle tria(o,a,b);
  Polygon pol(tria);    // cast to polygon, not virtual
  std::cout << pol << std::endl;

  Polygon pol2;
  pol2 = static_cast<Polygon>(tria);  // cast again, not virtual
  std::cout << pol2 << std::endl;

  Polygon &pol3 = tria;   // virtual function 
  std::cout << pol3 << std::endl;

  // destructor for Derive
  Triangle *ptr = new Triangle(a,b,c);
  std::cout << *ptr << std::endl;
  delete ptr;

  // destructor for Base
  Polygon *poly = new Triangle(o,a,b);
  std::cout << *poly << std::endl;
  delete poly;

  Polygon *poly2 = new Triangle(a,b,c);
  Triangle *tri2 = dynamic_cast<Triangle*>(poly2);
  //Triangle &tri2 = dynamic_cast<Triangle&>(*poly2);

  if (tri2 ){
    std::cout << "It success!" << std::endl;
    std::cout << *tri2 << std::endl;
  } else {
    std::cout << "It fails!" << std::endl;
  }

  return 0;
}

std::ostream& operator<<(std::ostream& out, const Point& foo){
  out << "(" << foo.x << "," << foo.y << ")";
  return out;
}

std::ostream& operator<<(std::ostream& out, const Polygon& foo){
  out << foo.name() << ": ";
  for( int i=0 ; i<foo.vertex.size() ; ++i ){
    out << foo.vertex[i] << " ";
  }
  out << "\tGeometrical center: " << foo.geometrical_center();
  return out;
}

Point Polygon::geometrical_center() const {
  double x=0,y=0;
  for( int i=0 ; i<vertex.size() ; ++i ){
    x += vertex[i].x;
    y += vertex[i].y;
  }
  x /= vertex.size();
  y /= vertex.size();
  return Point(x,y);
}
