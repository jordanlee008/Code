#include <iostream>
#include <vector>

using namespace std;

int N;
int n;

bool check(vector< vector<int> > b, int x, int r, int c) {
  if (x != 1) {
    for (int i = 1; i <= n; i++) {
      if (b[i][c] != 1) return false;
    }
    for (int i = 0; i < n; i++) {
      if (b[r][i] != 1) return false;
    }
  }
  
  if (x != 2) {
    for (int i = 1; i <= r + c; i++) {
      if (b[i][r + c - i] != 2) return false;
    }
    for (int i = 1; i <= max(r,c) - min(r,c); i++) {
      if (b[i][max(r,c) - min(r,c) - i] != 2) return false;
    }
  }
  
  return true;
}

int val(int x) {
  if (x == 3) return 2;
  if (x == 2 || x == 1) return 1;
  return 0;
}

vector< vector<int> > dfs(vector< vector<int> > b, int p) { // b[0] = total points, number of changes
  int r = p / n; // i.e. n = 0,0 on board
  int c = p % n;
  vector< vector<int> > nb3 = b;
  vector< vector<int> > nb2 = b;
  vector< vector<int> > nb1 = b;
  nb3[0][1] = b[0][1] + 1;
  nb2[0][1] = b[0][1] + 1;
  nb1[0][1] = b[0][1] + 1;
  if (check(b, 3, r, c)) { nb3[0][0] += val(3) - val(nb3[r][c]); nb2[r][c] = 3; dfs(nb3, p + 1); }
  else if (b[r][c] == 0) {
    if (check(b, 2, r, c)) { nb2[0][0] += val(2) - val(nb2[r][c]); nb2[r][c] = 2; dfs(nb2, p + 1); }
    if (check(b, 1, r, c)) { nb1[0][0] += val(1) - val(nb1[r][c]); nb1[r][c] = 1; dfs(nb1, p + 1); }
  }
  if (nb3[0][0] > nb2[0][0] && nb3[0][0] > nb1[0][0]) return nb3;
  else if (nb2[0][0] > nb1[0][0]) return nb2;
  return nb1;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int m;
    cin >> n >> m;
    vector< vector<int> > b (n + 1, vector<int>(n, 0));
    for (int j = 0; j < m; j++) {
      char m0;
      int r0, c0;
      cin >> m0 >> r0 >> c0;
      if (m0 == 'o') { b[r0][c0 - 1] = 3; b[0][0] += val(3); }
      else if (m0 == 'x') { b[r0][c0 - 1] = 2; b[0][0] += val(2); }
      else if (m0 == '+') { b[r0][c0 - 1] = 1; b[0][0] += val(1); }
    }
    vector< vector<int> > bb = dfs(b, n);
    printf("Case #%d: %d %d\n", i + 1, bb[0][0], bb[0][1]);
    for (int j = 1; j < n+1; j++) {
      for (int k = 0; k < n; k++) {
	cout << bb[j][k] << " ";
      }
      cout << "\n";
    }
  }
  
  
}
