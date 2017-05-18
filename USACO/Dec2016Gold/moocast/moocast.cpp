#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int main() {
  ifstream fin ("moocast.in");
  ofstream fout ("moocast.out");

  int n;
  fin >> n;
  int p[n][2];
  for (int i = 0; i < n; i++) {
    int x, y;
    fin >> x >> y;
    p[i][0] = x;
    p[i][1] = y;
  }
  
  VI sd;
  int d[n][n];
  int min[n];
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int dis = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
      d[i][j] = d[j][i] = dis;
      sd.push_back(dis);
    }
  }
  sort(sd.begin(), sd.end());
  
  for (int i = 0; i < n; i++) {
    min[i] = d[i + 1][i];
    for (int j = 0; j < n; j++) {
      if (j != i && d[j][i] < min[i]) min[i] = d[j][i];
    }
  }
  int max = min[0];
  for (int i = 1; i < n; i++) if (min[i] > max) max = min[i];
  int start = 0;
  for (int i = 0; i < sd.size() && sd[i] < max; i++) start++;
  // test out every radius
  int u[n];
  for (int j = 0; j < n; j++) u[j] = !j;
  vector<int> t;
  t.push_back(0);
  for (int i = start; i < sd.size(); i++) {
    if (sd[i] == sd[i - 1]) continue;
    //    printf("testing %d\n", i);
    int index = 0;
    while (index < t.size()) {
      for (int j = 0; j < n; j++) {
	if (d[t[index]][j] <= sd[i] && !u[j]) {
	  u[j] = 1;
	  t.push_back(j);
	}
      }
      index++;
    }
    if (t.size() == n) {
      cout << sd[i] << "\n";
      fout << sd[i] << "\n";
      break;
    }
  }
}
