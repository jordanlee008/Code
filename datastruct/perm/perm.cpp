#include <iostream>
#include <vector>
#include <mach/mach_time.h>

using namespace std;

typedef vector<int> VI;

vector<VI> permstart(vector<int> n) {
  vector<VI> r;
  if (n.size() == 1) {
    r.push_back(n);
    return r;
  }
  for (int i = 0; i < n.size(); i++) {
    vector<int> v;
    for (int j = 0; j < n.size(); j++)
      if (n[j] != n[i]) v.push_back(n[j]);
    
    vector<VI> h = permstart(v);
    for (int j = 0; j < h.size(); j++) {
      h[j].insert(h[j].begin(), n[i]);
      r.push_back(h[j]);
    }
  }
  return r;
}

vector<VI> perm(int n) {
  vector<int> v;
  for (int i = 1; i < n + 1; i++) v.push_back(i);
  return permstart(v);
}

double time() {
  return 1E-9 * mach_absolute_time();
}

int main() {
  double start = time();
  vector<VI> v = perm(5);
  double end = time();
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "number " << v.size() << "\n";
  cout << "time " << end - start << "\n";
  return 0;
}
