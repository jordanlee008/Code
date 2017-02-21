#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node {
  int x;
  int y;
  int g;
  int h;
} node;

class Compare {
public:
  bool operator() (const node v1, const node v2)
  {
    return v1.h > v2.h;
  }
};

int N, T;
int f[101][101];
int vis[101][101];
priority_queue<node, deque<node>, Compare > p;

int possible_dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int possible_dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

void add(const node v0, int dx, int dy) {
  int x0 = v0.x;
  int y0 = v0.y;
  int x = x0 + dx;
  int y = y0 + dy;
  if ((x < 0) || (x >= N) || (y < 0) || (y >= N)) return;  
  
  node v1;
  v1.x = x;
  v1.y = y;
  v1.g = v0.g + 3*T + f[x][y];
  if (v1.g >= vis[x][y]) return;
  vis[x][y] = v1.g;
  v1.h = v1.g + T * (abs(N-1-(x))+abs(N-1-(y)));
  
  p.push(v1);
}

void bfs(const node v) {

  int dx;
  int dy;
  
  for (int i = 0; i < 16; i++) {
    dx = possible_dx[i];
    dy = possible_dy[i];
    add(v, dx, dy);
  }
  
}

int main() {
  ifstream fin ("visitfj.in");
  ofstream fout ("visitfj.out");
  
  fin >> N;
  fin >> T;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> f[i][j];
      vis[i][j] = 0x7FFFFFFF;
      //      cout << f[i][j] << " ";
    }
    //    cout << "\n";
  }

  node v;
  v.x = 0;
  v.y = 0;
  v.g = 0;
  v.h = 0;
  //  v.h = 1*T*(N-1)*(N-1);
  vis[0][0] = 0;
  p.push(v);

  while (p.size()) {
    v = p.top();
    
    cout << "Node: " << v.x << " " << v.y << " " << v.g << endl;
    int dis = (N - 1 - v.x) + (N - 1 - v.y);
    if (dis < 3) {
      v.g += dis * T;
      fout << v.g << endl;
      printf("Cost: %d\n", v.g);
      break;
    }
    p.pop();
    bfs(v);
  }

  return 0;
}
