#include <vector>
#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

bool left_turn(const Point& p, const Point& q, const Point& r) {
  return (r.x - q.x) * (q.y - p.y) - (r.y - q.y) * (q.x - p.x) < 0;
}

void conv_hull(vector<Point>& pts) {
  // translate everything to the origin and sort in order from lowest going ccw
  int low = 0;
  for (int i = 1; i < pts.size(); i++)
    if (pts[low].y > pts[i].y) low = i;
    else if (pts[low].y == pts[i].y && pts[low].x > pts[i].x) low = i;
  double lowx = pts[low].x;
  double lowy = pts[low].y;
  for (int i = 0; i < pts.size(); i++) {
    pts[i].x -= lowx;
    pts[i].y -= lowy;
  }
  swap(pts[0], pts[low]);
  sort(pts.begin() + 1, pts.end());
  
  // graham scan spookiness
  int index = 2;
  while (index < pts.size()) {
    while (left_turn(pts[index - 2], pts[index - 1], pts[index])) {
      pts.erase(pts.begin() + index - 1);
      index--;
    }
    index++;
  }
}

int main() {
  
  return 0;
}
