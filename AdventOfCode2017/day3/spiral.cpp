#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int coord(int x, int y) {
  // assumes -200 < x,y < 200
  if (x >= 0 && y >= 0) {
    return 200*x + y;
  } else if (x < 0 & y >= 0) {
    return 40000 + -200*x + y;
  } else if (x < 0 & y < 0) {
    return 80000 + -200*x - y;
  } else {
    return 120000 + 200*x - y;
  }
  
}

int main() {
  ifstream fin ("spiral.in");
  ofstream fout ("spiral.out");

  int n;
  fin >> n;

  /*  PART 1
  int r = 1, s = 0;
  while ((r+2)*(r+2) < n) { r += 2; }
  int t = (r + 1) / 2;
  while (r*r + 2*t*(s+1) < n) { s++; }
  int u = n - (r*r + 2*t*s + t);
  if (u < 0) u = -u;
  cout << r << " " << s << "\n";
  cout << t << " " << u << "\n";
  fout << t + u << "\n"; */

  vector<int> v(160000,0);
  v[coord(0,0)] = 1;
  int x = 0, y = 0, i = 1;
  int r = -1, s = 0;
  int t, u;
  while (true) {
    i++;
    
    if ((r+2)*(r+2) < i) { r += 2; s = 0; }
    t = (r + 1) / 2;
    if (r*r + 2*t*(s+1) < i) s++;
    u = i - (r*r + 2*t*s);

    if (u > 1) {
      if (s == 0) y++;
      else if (s == 1) x--;
      else if (s == 2) y--;
      else if (s == 3) x++;
    } else {
      if (s == 0) x++;
      else if (s == 1) x--;
      else if (s == 2) y--;
      else if (s == 3) x++;
    }
    
    int sum = v[coord(x-1,y-1)] + v[coord(x-1,y)] + v[coord(x,y-1)] + v[coord(x-1,y+1)] + v[coord(x+1,y-1)] + v[coord(x,y+1)] + v[coord(x+1,y)] + v[coord(x+1,y+1)];
    v[coord(x,y)] = sum;
    cout << x << " " << y << " " << sum << "\n";

    if (sum > n) {
      fout << sum << "\n";
      break;
    }
  }
  
  
  
  return 0;
}
