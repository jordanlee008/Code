#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int h[1000][2], g[1000][2], p[2000][2];
int d[2000][2000];
int nh, ng;

// ng how many g's already inside pts
// must insert next g after the index b
// vector containing points to travel to
vector<int> dfs(int ig, int b, vector<int> pts) {
  printf("dfs(%d, %d)\n", ig, b);
  vector<int> nnp;
  if (ig == ng) return pts;
  int cost = -1;
  for (int i = b; i < pts.size() - 2; i++) { // which index to insert after
    vector<int> np = pts;
    np.push_back(0);
    for (int j = np.size() - 1; j > i + 1; j--) np[j] = np[j - 1];
    np[i + 1] = ig + nh;
    np = dfs(ig + 1, i + 1, np);
    int c = 0;
    for (int i = 0; i < np.size() - 1; i++) c += d[np[i]][np[i + 1]];
    if (cost == -1 || c < cost) {
      cost = c;
      nnp = np;
    }
  }
  return nnp;
}

int main() {
  ifstream fin ("checklist.in");
  ofstream fout ("checklist.out");

  
  fin >> nh >> ng;
  for (int i = 0; i < nh; i++) {
    fin >> h[i][0] >> h[i][1];
    p[i][0] = h[i][0];
    p[i][1] = h[i][1];
  }
  for (int i = 0; i < ng; i++) {
    fin >> g[i][0] >> g[i][1];
    p[i + nh][0] = g[i][0];
    p[i + nh][1] = g[i][1];
  }

  for (int i = 0; i < nh + ng; i++) {
    for (int j = i; j < nh + ng; j++) {
      int dis = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
      d[i][j] = d[j][i] = dis;
    }
  }
  
  // which cow he needs to visit next
  vector<int> p;
  for (int i = 0; i < nh; i++) p.push_back(i);
  p = dfs(0, 0, p);
  int c = 0;
  for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
  cout << "\n";
  for (int i = 0; i < p.size() - 1; i++) c += d[p[i]][p[i + 1]];
  fout << c << "\n";
  cout << c << "\n";
}
