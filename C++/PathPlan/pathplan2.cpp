#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int xstart, ystart;
int xend, yend;
int L, H;
vector< vector<int> > cost; //path[y][x]
vector< vector<int> > path; //path[y][x]

vector<int> findadj (int x, int y) {
  vector<int> a;
  if (x > 0)
    a.push_back(y * L + x - 1);
  if (x < L - 1)
    a.push_back(y * L + x + 1);
  if (y > 0)
    a.push_back((y - 1) * L + x);
  if (y < H - 1)
    a.push_back((y + 1) * L + x);
  return a;
}

int main () {
  ifstream fin ("pathplan.in");
  ofstream fout ("pathplan.out");
  
  fin >> L >> H;
  cost.reserve(H);
  for (int i = 0; i < H; i++)
    for (int j = 0; j < L; j++) {
      int a;
      fin >> a;
      cost[i].push_back(a);
    }

  path.reserve(H);
  for (int i = 0; i < H; i++)
    for (int j = 0; j < L; j++) {
      path[i].push_back(-1);
    }

  fin >> xstart >> ystart;
  fin >> xend >> yend;

  deque<int> check;
  check.push_back(ystart * L + xstart);
  while (check.size() > 0) {
    printf("Checking [%d][%d]\n", (check[0] % L), (check[0] / L));
    vector<int> a;
    a = findadj((check[0] % L), (check[0] / L));
    int smallpath = 2147483647;
    for (int i = 0; i < a.size(); i++) {
      if (path[a[i] / L][a[i] % L] == -1) {
	check.push_back(a[i]);
      } else {
	smallpath = min(smallpath, path[a[i] / L][a[i] % L]) + cost[check[0] / L][check[0] % L];
      }
    }
    path[check[0] / L][check[0] % L] = smallpath;
    check.pop_front();
  }

  cout << path[yend][xend] << endl;
  
  return 0;
}
