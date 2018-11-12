#ifndef _POINT2D_H_
#define _POINT2D_H_

template <typename T>
class Point2D {
  public:
    Point2D();
    Point2D(T xin, T yin);
    ~Point2D();

    template <typename S>
    friend std::ostream& operator<<(std::ostream& out, const Point2D<S>& foo);

  private:
    T x, y;
};

template <typename T>
Point2D<T>::Point2D() : x(0), y(0) {}

template <typename T>
Point2D<T>::Point2D(T xin, T yin) : x(xin), y(yin) {}

template <typename T>
Point2D<T>::~Point2D(){};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Point2D<T>& foo){
  out << "(" << foo.x << "," << foo.y << ")";
  return out;
}

#endif
