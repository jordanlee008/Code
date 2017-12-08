/*
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> IntPair;

bool FracComp(const IntPair &l, const IntPair &r) {
  return l.first*r.second < r.first*l.second;
}

int gcd(int p, int q) {
  int r;
  do {
    r = q % p;
    q = p;
    p = r;
  } while (r != 0);
  return q;
}

int main() {
  ofstream fout ("frac1.out");
  ifstream fin ("frac1.in");

  vector<IntPair> f;

  int n;
  fin >> n;

  f.push_back(IntPair(0,1));
  f.push_back(IntPair(1,1));
  for (int q = 2; q <= n; q++) {
    for (int p = 1; p < q; p++) {
      // Check to see if reduced form:
      if (gcd(p, q) == 1) {
	f.push_back(IntPair(p,q));
      }
    }
  }

  sort(f.begin(), f.end(), FracComp);
  for (int i = 0; i < f.size(); i++) {
    fout << f[i].first << "/" << f[i].second << endl;
  }
  
  return 0;
}
