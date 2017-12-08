/*
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> IntPair;
bool IntPairComp(const IntPair &l, const IntPair &r) {
  if (l.second < r.second) return true;
  if (l.second > r.second) return false;
  if (l.first < r.first) return true;
  else return false;


int main() {
  ofstream fout ("ariprog.out");
  ifstream fin ("ariprog.in");
  
  int n, m;
  fin >> n;
  fin >> m;

  // Lookup table to check bisquares:
  bool v[10*250*250] = {false};
  for (int p = 0; p <= m; p++) {
    for (int q = p; q <= m; q++) {
      int bisq = p*p + q*q;
      v[bisq] = true;
    }
  }
  // Sorted list of bisquares:
  vector<int> vs;
  for (int i = 0; i <= 2*m*m; i++) {
    if (v[i]) vs.push_back(i);
  }

  
  // Generate arithmetic sequence candidates:
  vector<IntPair> ab;
  for (int i = 0; i < vs.size(); i++) {
    int a = vs[i];
    for (int j = i+1; j < vs.size(); j++) {
      int b = vs[j] - a;
      bool valid = true;
      for (int nb = 2; nb < n; nb++) {
	if (!v[a+nb*b]) {
	  valid = false;
	  break;
	}
      }
      if (valid) {
	ab.push_back(IntPair(a,b));
	cout << a << " " << b << endl;
      }
    }
  }
  
  // Sort by differences, then starting number:
  sort(ab.begin(), ab.end(), IntPairComp);

  // Output lines:
  for (int i = 0; i < ab.size(); i++) {
    fout << ab[i].first << " " << ab[i].second << endl;
  }
  if (ab.size() == 0) {
    fout << "NONE" << endl;
  }
 
  return 0;
}
