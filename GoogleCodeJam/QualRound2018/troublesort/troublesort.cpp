#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> trouble(vector<int> v) {
  bool done = false;
  while (!done) {
    done = true;
    for (int i = 0; i < v.size() - 2; i++) {
      if (v[i] > v[i+2]) {
	done = false;
	swap(v[i],v[i+2]);
      }
    }
  }
  return v;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    vector<int> v1, v2;
    
    cin >> N;
    for (int j = 0; j < N; j++) {
      int x;
      cin >> x;
      v1.push_back(x);
      v2.push_back(x);
    }
    v1 = trouble(v1);
    sort(v2.begin(), v2.end());

    int bad = -1;
    for (int j = 0; j < N; j++) {
      if (v1[j] != v2[j]) {
	bad = j;
	break;
      }
    }

    if (bad == -1) printf("Case #%d: OK\n", i+1);
    else printf("Case #%d: %d\n", i+1, bad);
    
  }
}
