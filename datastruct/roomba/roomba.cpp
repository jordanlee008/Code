#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double minDistance(int r, int x1, int y1, int x2, int y2) {
  double rd = r, x1d = x1, y1d = y1, x2d = x2, y2d = y2;
  //  printf("%f\t%f\t%f\t%f\t%f\n", rd, x1d, y1d, x2d, y2d);
  // (x1, y1) above wall, (x2, y2) below wall
  // check if can go straight
  double dist = fabs(x2d * y1d - y2d * x1d) / sqrt((y2d - y1d) * (y2d - y1d) + (x2d - x1d) * (x2d - x1d));
  double slope = (y2d - y1d) / (x2d - x1d);
  bool vert = false;
  if (x2 == x1) vert = true;
  double yat0 = y1d - slope * x1d;
  int quad1 = 0, quad2 = 0;
  if (x1 > 0) quad1 += 1;
  if (y1 > 0) quad1 += 2;
  if (x2 > 0) quad2 += 1;
  if (y2 > 0) quad2 += 2;
  
  //  printf("dist: %f\tvert: %d\tslope: %f\tyat0: %f\n", dist, vert, slope, yat0);
  if ((vert && x2 < -r) || (yat0 > 0 && dist >= r && slope > 0) || (yat0 < 0 && dist >= r && slope < 0) || (quad1 == quad2)) {
    //    printf("straight\n");
    return sqrt((y2d-y1d)*(y2d-y1d) + (x2d-x1d)*(x2d-x1d));
  }
  

  // robot circles around edge of wall
  double d1 = sqrt((y1d*y1d + x1d*x1d) - rd*rd);
  double dtoc1 = sqrt(y1d*y1d + x1d*x1d);
  double th1 = acos(rd / dtoc1);
  double th2 = atan2(y1d, x1d);
  if (th2 < 0) th2 = -th2;
  //  printf("th1: %f\tth2: %f\n", th1, th2);
  double d2 = sqrt((y2d*y2d + x2d*x2d) - rd*rd);
  double dtoc2 = sqrt(y2d*y2d + x2d*x2d);
  double th3 = acos(rd / dtoc2);
  double th4 = atan2(y2d, x2d);
  if (th4 < 0) th4 = -th4;
  //  printf("th3: %f\tth4: %f\n", th3, th4);
  double th;
  if (y1 * y2 > 0) {
    if (th4 - th3 > th1 + th2) th = (th4 - th3) - (th1 + th2);
    else th = (th2 - th1) - (th3 + th4);
  }
  else th = 2 * M_PI - (th1 + th2 + th3 + th4);
  //  printf("th: %f\n", th);
  double d3 = th * rd;
  //  printf("d1: %f\nd2: %f\nd3: %f\n", d1, d2, d3);
  return d1 + d2 + d3;
}

/*int main() {
  cout << minDistance(5, -3, 4, 6, -6 ) << "\n";
  }*/
