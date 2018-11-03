#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
  double x, y;
  Point(double a, double b) : x(a), y(b) {}
};

class Polygon{
  protected:
    vector<Point> vertex;
  public:
    int vertex_no() const { return vertex.size(); }
    Point geometrical_center() const {} // not finished
    virtual string name() const { return "Polygon"; }
};

class Traingle : public Polygon {
  public:
    Traingle(){}
    Traingle( Point pt1, Point pt2, Point pt3 ){
      vertex.push_back(pt1);
      vertex.push_back(pt2);
      vertex.push_back(pt3);
    }
    Point circumcenter () const {}
    virtual string name() const { return "Traingle"; }
};

class Rectangle : public Polygon {
  public:
    Rectangle(){}
    Rectangle( Point pt1, Point pt2, Point pt3, Point pt4 ){
      vertex.push_back(pt1);
      vertex.push_back(pt2);
      vertex.push_back(pt3);
      vertex.push_back(pt4);
    }
    virtual string name() const { return "Rectangle"; }
};

void print_vertex_no( const Polygon& p){
  cout << p.name() << " : " << p.vertex_no() << endl;
}

int main(){
  Point o(0,0), a(1,0), b(0,1), c(1,1);
  Traingle triangle(o,a,b);
  Rectangle rectangle(o,a,c,b);

  cout << triangle.vertex_no() << endl;
  cout << rectangle.vertex_no() << endl;

  cout << triangle.name() << endl;
  cout << rectangle.name() << endl;

  print_vertex_no(triangle);
  print_vertex_no(rectangle);
  
  return 0;
}
