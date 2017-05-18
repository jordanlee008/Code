#include <iostream>
#include <vector>

using namespace std;

int N;

char convert(int x) {
  switch (x) {
  case 0: return 'R'; break;
  case 1: return 'O'; break;
  case 2: return 'Y'; break;
  case 3: return 'G'; break;
  case 4: return 'B'; break;
  case 5: return 'V'; break;
  }
}

bool comp(int c1, int c2) {
  int dif = abs(c1 - c2) % 5;
  if (dif > 1) return true;
  return false;
}

vector<int> make(vector<int> s, vector<int> c, int x) { // x is index
  for (int i = 0; i < 6; i++) {
    if (c[i] && comp(s[x-1], i)) {
      vector<int> ns = s;
      ns[x] = i;
      vector<int> nc = c;
      nc[i]--;

      if (x == N - 1 && comp(ns[0], ns[x])) return ns;
      else if (x == N - 1) continue;
      
      ns = make(ns, nc, x + 1);
      if (ns.size()) return ns;
    }
  }
  return vector<int>(0,0);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> N;
    int x0;
    vector<int> c;
    for (int j = 0; j < 6; j++) {
      int c0;
      cin >> c0;
      if (c0) x0 = c0;
      c.push_back(c0);
    }

    vector<int> s(N, -1);
    s[0] = x0;
    c[x0]--;
    s = make(s, c, 1);
    
    if (!s.size()) { printf("Case #%d: IMPOSSIBLE\n", i + 1); }
    else {
      printf("Case #%d: ", i + 1);
      for (int j = 0; j < N; j++) cout << convert(s[j]);
      cout << "\n";
    }
  }
}
