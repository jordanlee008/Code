#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define VI vector<int>

int N;
vector<VI> g;
VI w, l, r;
vector<string> name;
vector<VI> c(1 + N*(N-1)/2 + N + 1, vector<int>(1 + N*(N-1)/2 + N + 1, 0));
vector<VI> a(1 + N*(N-1)/2 + N + 1, vector<int>(0, 0));
vector<VI> f(1 + N*(N-1)/2 + N + 1, vector<int>(1 + N*(N-1)/2 + N + 1, 0));

vector<int> dfs(VI p, VI s, int v, int t) {
  //  printf("dfs(%d)\n", v);
  if (v == t) return p;
  for (int i : a[v]) {
    if (!s[i]) {
      //      printf("[%d][%d] s[%d]\n", v, i, s[i]);
      vector<int> np = p;
      np.push_back(i);
      vector<int> ns = s;
      ns[v] = 1;
      VI pp = dfs(np, ns, i, t);
      if (pp.size()) return pp;
    }
  }
  return VI(0,0);
}

vector<int> maxflow(int x) {
  printf("maxflow(%d)\n", x);
  
  for (int i = 0; i < 1 + N*(N-1)/2 + N + 1; i++) {
    a[i] = VI(0,0);
  }
  
  int ct = 1;  
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      c[0][ct] = g[i][j];
      a[0].push_back(ct);
      
      c[ct][i + N*(N-1)/2 + 1] = 1000000;
      a[ct].push_back(i + N*(N-1)/2 + 1);
      
      c[ct][j + N*(N-1)/2 + 1] = 1000000;
      a[ct].push_back(j + N*(N-1)/2 + 1);
      
      ct++;
    }
  }
  
  for (int i = 0; i < N; i++) {
    c[N*(N-1)/2 + i + 1][N*(N-1)/2+N+1] = w[x] + r[x] - w[i];
    //    printf("team %d = %d\n", N*(N-1)/2 + i + 1, w[x] + r[x] - w[i]);
    if (c[N*(N-1)/2 + i + 1][N*(N-1)/2+N+1] > 0) {
      a[N*(N-1)/2 + i + 1].push_back(N*(N-1)/2+N+1);
    } else {
      c[N*(N-1)/2 + i + 1][N*(N-1)/2+N+1] = 0;
    }
  }
  
  /*  for (int i = 0; i < c.size(); i++) {
    cout << i << "\t";
  }
  cout << "\n";
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[j].size(); j++) {
      cout << c[i][j] << "\t";
    }
    cout << "\n";
    }
  for (int i = 0; i < a.size(); i++) {
    cout << i << ":";
    for (int j = 0; j < a[i].size(); j++) {
      cout << " " << a[i][j];
    }
    cout << "\n";
    }*/

  VI p = dfs(VI(1,0), VI(N*(N-1)/2+N+2,0), 0, N*(N-1)/2+N+1);
  
  while (p.size()) {
    //    for (int i = 0; i < p.size(); i++) cout << p[i] << " ";
    //    cout << "\n";
    
    int cost = c[p[0]][p[1]];
    for (int i = 1; i < p.size()-1; i++) {
      if (c[p[i]][p[i+1]] < cost) cost = c[p[i]][p[i+1]];
    }
    //    cout << cost << "\n";
    
    for (int i = 0; i < p.size()-1; i++) {
      f[p[i]][p[i+1]] = f[p[i]][p[i+1]] + cost;
      c[p[i]][p[i+1]] = c[p[i]][p[i+1]] - cost;
      if (c[p[i]][p[i+1]] <= 0) {
	for (int j = 0; j < a[p[i]].size(); j++) {
	  if (a[p[i]][j] == p[i+1]) a[p[i]].erase(a[p[i]].begin() + j);
	}
      }

      f[p[i+1]][p[i]] = f[p[i+1]][p[i]] - cost;
      c[p[i+1]][p[i]] = c[p[i+1]][p[i]] + cost;
      if (c[p[i+1]][p[i]] > 0) {
	bool found = false;
	for (int j = 0; j < a[p[i+1]].size(); j++) {
	  if (a[p[i+1]][j] == p[i]) found = true;
	}
	if (!found) a[p[i+1]].push_back(p[i]);
      }
    }
    
    p = dfs(VI(1,0), VI(N*(N-1)/2+N+2,0), 0, N*(N-1)/2+N+1);
  }
  
  bool fill = true;
  /*  for (int i = 1; i < N*(N-1)/2 + 1; i++) {
    printf("f[0][%d] = %d\n", i, f[0][i]);
    }*/
  for (int i = 1; i < N*(N-1)/2 + 1; i++) {
    //    printf("c[0][%d] = %d\n", i, c[0][i]);
    if (c[0][i] != 0) fill = false;
  }
  //  cout << "fill " << fill << "\n";
  if (fill) return VI(0,0);
  
  /*VI tms;
  for (int i = N*(N-1)/2 + 1; i < N*(N-1)/2+N+1; i++) {
    if (i - (N*(N-1)/2 + 1) == x) continue;
    VI v = dfs(a, VI(1,0), VI(N*(N-1)/2+N+2,0), 0, i);
    if (v.size()) tms.push_back(i - N*(N-1)/2-1);
    }*/
  return VI(1,0);
}

void baseball() {
  // GET INPUT
  cin >> N;
  VI e;
  for (int i = 0; i < N; i++) {
    g.push_back(e);
    string s;
    cin >> s;
    name.push_back(s);

    int c;
    cin >> c;
    w.push_back(c);

    cin >> c;
    l.push_back(c);

    cin >> c;
    r.push_back(c);

    for (int j = 0; j < N; j++) {
      if (j == i) {
	cin >> s;
	g[i].push_back(-1);
	continue;
      }
      cin >> c;
      g[i].push_back(c);
    }
  }
  
  // OUTPUT
  for (int i = 0; i < N; i++) {
    VI tms = maxflow(i);
    if (tms.size()) {
      cout << name[i] << " cannot catch up\n";
      //      for (int j = 0; j < tms.size(); j++) cout << name[tms[j]] << " ";
      //      cout << "}\n";
    } else {
      cout << name[i] << " is not eliminated\n";
    }
  }
}

int main() {
  baseball();
  return 0;
}
