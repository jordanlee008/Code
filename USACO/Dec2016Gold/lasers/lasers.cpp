#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int n, xl, yl, xb, yb;
//vector<VI> x;
//vector<VI> y;
vector<VI> p;
VI d;

/*int laser(int dx, int dy, vector<VI> pts) {
  printf("laser(%d, %d)\n", dx, dy);
  if (dx == 0 || dy == 0) return 0;
  int m = -1;
  for (int i = 0; i < x[dx].size(); i++) {
    vector<VI> xcc = xc;
    int x1 = xcc[dx][i];
    printf("x1: %d\n", x1);
    xcc[dx].erase(xcc[dx].begin() + i);
    int c = 1 + laser(dx, x1, xcc, yc);
    if ((c > 0) && (m == -1 || 1 + c < m))  m = 1 + c;
  }
  for (int i = 0; i < y[dy].size(); i++) {
    vector<VI> ycc = yc;
    int y1 = ycc[dy][i];
    printf("y1: %d\n", y1);
    ycc[dy].erase(ycc[dy].begin() + i);
    int c = 1 + laser(y1, dy, xc, ycc);
    if ((c > 0) && (m == -1 || 1 + c < m)) m = 1 + c;
    }


  for (int i = 0; i < pts.size(); i++) {
    if (pts[i][0] == dx || pts[i][1] == dy) {
      vector<VI> np = pts;
      int x1 = pts[i][0], y1 = pts[i][1];
      np.erase(np.begin() + i);
      int c = 1 + laser(x1, y1, np);
      if ((c > 0) && (m == -1 || c < m)) m = c;
    }
  }
  return m;
}*/

void laser(int pt, vector<VI> pts) {
  for (int i = 0; i < pts.size(); i++) {
    if (p[pt][0] == pts[i][0] || p[pt][1] == pts[i][1]) {
      if (d[pt] + 1 < d[i] || d[i] == 0) {
	d[i] = d[pt] + 1;
	laser(i, pts);
      }
    }
  }
}

int main() {
  ifstream fin ("lasers.in");
  ofstream fout ("lasers.out");
  
  fin >> n >> xl >> yl >> xb >> yb;
  /*VI empty;
  for (int i = 0; i < 1000; i++) {
    x.push_back(empty);
    y.push_back(empty);
    }*/
  for (int i = 0; i < n; i++) {
    int x1, y1;
    fin >> x1 >> y1;
    //    x[x1].push_back(y1);
    //    y[y1].push_back(x1);
    VI e;
    e.push_back(x1);
    e.push_back(y1);
    p.push_back(e);
    cout << x1 << y1 << "\n";
  }
  VI e;
  e.push_back(xb);
  e.push_back(yb);
  p.push_back(e);
  laser(0, p);
  fout << d[n] << "\n";
  cout << d[n] << "\n";
}
