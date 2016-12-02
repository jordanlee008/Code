#include <vector>
#include <iostream>
#include "point.h"

using namespace std;

int quadrant(const Point& p) {
  if (p.x > 0 && p.y >= 0) return 0;
  if (p.x <= 0 && p.y > 0) return 1;
  if (p.x < 0 && p.y <= 0) return 2;
  return 3;
}

int doublequad(const Point& p, const Point& q) { // return 1 or -1
  
}

bool inside(const vector<Point>& pts, const Point& p0) {
  int tot = 0;
  for (int i = 0; i < pts.size() - 1; i++) {
    int dif = quadrant(pts[i + 1]) - quadrant(pts[i]);
    if (dif == -3) tot += 1;
    if (dif == 2 || dif == -2) tot += 2 * doublequad(pts[i + 1], pts[i]);
    if (dif == 1 || dif == -1 || dif == 0) tot += dif;
  }
  if (tot == 0) return false;
  return true;
}
