#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dc[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};

int main() {
  ifstream fin ("visitfj.in");
  ofstream fout ("visitfj.out");

  int N, T;
  fin >> N >> T;

  int A[101][101];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> A[i][j];
    }
  }

  vector<vector<int> > D(N, vector<int>(N, 0x7FFFFFFF));
  D[0][0] = 0;

  priority_queue<pair< int, pair<int,int> > > q;
  q.push(make_pair(2*(N-1)*T,make_pair(0, 0)));

  int result = 0x7FFFFFFF;
  while (!q.empty()) {
    int gh = -q.top().first;
    int d = -q.top().second.first;
    int r = q.top().second.second / N;
    int c = q.top().second.second % N;
    printf("(%d,%d)\n", r, c);
    q.pop();
    if (d != D[r][c]) {
      continue;
    }

    int dist = abs(N - 1 - r) + abs(N - 1 - c);
    if (dist <= 2) {
      result = min(result, d + dist * T);
    }

    for (int i = 0; i < sizeof(dr) / sizeof(int); i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 || nr >= N || nc < 0 || nc >= N ||
          D[nr][nc] < d + A[nr][nc] + 3 * T) {
        continue;
      }
      D[nr][nc] = d + A[nr][nc] + 3 * T;
      int distnrnc = abs(N-1-nr) + abs(N-1-nc);
      q.push(make_pair(-(D[nr][nc]+distnrnc*T), make_pair(-D[nr][nc], nr * N + nc)));
    }
  }
  
  fout << result << endl;

  return 0;
}
