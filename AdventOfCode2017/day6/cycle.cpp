#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ip;

vector<int> cycle(vector<int> v) {
  vector<ip> vi;
  ip v0(0,0);
  for (int i = 0; i < v.size(); i++) {
    v0.first = v[i];
    v0.second = i;
    vi.push_back(v0);
  }
  
  sort(vi.begin(), vi.end());
  
  int i = vi[vi.size()-1].second - 1;
  if (i == -1) i = v.size()-1;
  int k = vi[vi.size()-1].first;
  v[vi[vi.size()-1].second] = 0;
  for (int j = 0; j < k; j++) {
    v[i]++;
    i--;
    if (i == -1) i = v.size()-1;
  }
  return v;
}

int main() {
  ifstream fin ("cycle.in");
  ofstream fout ("cycle.out");
  
  int x;
  vector<int> v;
  while (fin >> x) { v.push_back(x); }
  for (int i = 0; i < v.size() / 2; i++) swap(v[i], v[v.size()-1-i]);

  //  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  //  cout << "\n";

  vector< vector<int> > s;
  s.push_back(v);

  bool found = true;
  int index;
  while (found) {
    v = cycle(v);
    for (int i = 0; i < s.size(); i++) {
      if (v == s[i]) {
	found = false;
	index = i;
      }
    }
    s.push_back(v);

    //    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    //    cout << "\n";
  }
  
  fout << s.size() - 1 << "\n";
  fout << s.size() - 1 - index << "\n";

}
