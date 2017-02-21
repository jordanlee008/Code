#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node {
  int x;
  int y;
  int steps;
  int g;
  int h;
} node;

bool sortfunc(const node& v1, const node& v2) {
  return v1.g + v1.h < v2.g + v2.h;
}

int N, T;
int f[101][101];
int vis[101][101][3];
deque< node > p;
int mq = 0;
int counter = 0;

void add(node &v0, int dx, int dy) {
  int x0 = v0.x;
  int y0 = v0.y;
  int x = x0 + dx;
  int y = y0 + dy;
  if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) return;

  
  node v1;
  v1.x = x;
  v1.y = y;
  v1.g = v0.g+T;
  v1.steps = v0.steps+1;
  if (v1.steps % 3 == 0)
    v1.g += f[x][y];
  v1.h = T*(abs(N-1-(x))+abs(N-1-(y)));

  if (vis[v1.x][v1.y][v1.steps % 3]) return;
  
  p.push_back(v1);
}

void bfs(node &v) { // t is total time so far

  int dx;
  int dy;

  dx = -1; dy = 0;
  add(v, dx, dy);

  dx = 1; dy = 0;
  add(v, dx, dy);

  dx = 0; dy = -1;
  add(v, dx, dy);

  dx = 0; dy = 1;
  add(v, dx, dy);
  
  sort(p.begin(), p.end(), sortfunc);
}

int main() {
  ifstream fin ("visitfj.in");
  ofstream fout ("visitfj.out");
  
  fin >> N;
  mq = N;
  fin >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> f[i][j];
      //      cout << f[i][j] << " ";
    }
    //    cout << "\n";
  }

  node v;
  v.x = 0;
  v.y = 0;
  v.steps = 0;
  v.g = 0;
  v.h = 2*T*(N-1);
  p.push_back(v);

  while (p.size()) {
    counter++;
    v = p[0];
    vis[v.x][v.y][v.steps % 3] = 1;

    cout << "Node: " << v.x << " " << v.y << " " << v.g << endl;
    if ((v.x == (N-1)) && (v.y == (N-1))) {
	fout << v.g << endl;
	cout << "Cost " << v.g << endl;
	cout << "Counter " << counter << endl;
	break;
      }
    p.pop_front();
    bfs(v);
  }

  return 0;
}
