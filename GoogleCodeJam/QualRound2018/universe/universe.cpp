#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dam(vector<int> v) {
  int tot = 0, pow = 1;
  for (int i = 0; i < v.size(); i++) {
    tot += pow * v[i];
    pow *= 2;
  }
  return tot;
}

int exp(int p) {
  int pow = 1;
  for (int i = 0; i < p; i++) {
    pow *= 2;
  }
  return pow;
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int D;
    string P;
    cin >> D >> P;
    
    vector<int> v = {0};
    int ind = 0, num = 0;
    for (char c : P) {
      if (c == 'S') { v[ind]++; num++; }
      else if (c == 'C') { v.push_back(0); ind++; }
      else { cerr << "badstring\n"; }
    }
    
    if (num > D) {
      printf("Case #%d: IMPOSSIBLE\n", i+1);
      continue;
    }

    int sw = 0, d = dam(v);
    while (d > D && ind > 0) {
      if (v[ind]) {
	v[ind]--;
	v[ind-1]++;
	d -= exp(ind-1);
	sw++;
      } else {
	ind--;
      }
    }
    printf("Case #%d: %d\n", i+1, sw);
    
  }
  
}
