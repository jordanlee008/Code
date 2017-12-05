#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin ("jump.in");
  ofstream fout ("jump.out");
  
  int x;
  vector<int> v;
  while (fin >> x) v.push_back(x);
  
  int i = 0, s = 0;
  while (i < v.size()) {
    if (v[i] < 3) i += v[i]++;
    else i += v[i]--;
    s++;
  }
  fout << s << "\n";
}
