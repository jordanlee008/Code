struct Point {
  Point(double, x, y);
  bool operator<(const Point& q) {
    return x * q.y - y * q.x > 0;
  }
  
  double x,y;
};
