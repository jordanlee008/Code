/*
  Jordan Lee
  Senior Team
  ACSL
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void calstring(deque<int> n) {
  int last = 0;
  int current = 0;
  bool front = true; // true is front, false is back
  while (n.size()) {
    while (n.size() && current <= last) {
      int d;
      if (front) {
	d = n.front();
	n.pop_front();
      }
      else {
	d = n.back();
	n.pop_back();
      }
      current = 10 * current + d;
    }
    if (current > last) cout << current << " ";
    last = current;
    current = 0;
    front = !front;
  }
  cout << "\n";
}

int main() {
  vector<long long> n;
  vector< deque<int> > v;
  for (int i = 0; i < 5; i++) {
    long long nn;
    cin >> nn;
    n.push_back(nn);
  }
  for (int i = 0; i < 5; i++) {
    deque<int> d;
    while (n[i]) {
      d.push_front(n[i] % 10);
      n[i] /= 10;
    }
    v.push_back(d);
  }
  for (int i = 0; i < 5; i++) {
    calstring(v[i]);
  }
}
