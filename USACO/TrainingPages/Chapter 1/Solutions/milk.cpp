/*
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> PApair;
bool PAcomp(const PApair &l, const PApair &r) {
  return l.first < r.first;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int n, m;
    fin >> n >> m;

    typedef pair<int, int> papair;
    papair p[m];
    for (int i = 0; i < m; i++) {
      fin >> p[i].first >> p[i].second;
    }
    sort(p, p+m, PAcomp);

    int cost = 0;
    int units = 0;
    for (int i = 0; i < m; i++) {
      int u1 = n-units;
      if (u1 > p[i].second)
	u1 = p[i].second;
      units += u1;
      cost += p[i].first*u1;
    }

    fout << cost << endl;

    return 0;
}
