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
  double h;
} node;

class Compare {
public:
  bool operator() (node v1, node v2)
  {
    return v1.g + v1.h > v2.g + v2.h;
  }
};

int N, T;
int f[101][101];
int vis[101][101][3];
priority_queue<node, deque<node>, Compare > p;

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
  v1.h = 1.001*T*(abs(N-1-(x))+abs(N-1-(y)));

  if (vis[v1.x][v1.y][v1.steps % 3]) return;
  
  p.push(v1);
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
  
}

int main() {
  ifstream fin ("visitfj.in");
  ofstream fout ("visitfj.out");
  
  fin >> N;
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
  v.h = 0;
  //  v.h = 1*T*(N-1)*(N-1);
  p.push(v);

  while (p.size()) {
    v = p.top();
    vis[v.x][v.y][v.steps % 3] = 1;

    cout << "Node: " << v.x << " " << v.y << " " << v.g << endl;
    if ((v.x == (N-1)) && (v.y == (N-1))) {
	fout << v.g << endl;
	cout << "Cost " << v.g << endl;
	break;
      }
    p.pop();
    bfs(v);
  }

  return 0;
}
