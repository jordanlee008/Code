#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> digitize(string s) {
  vector<int> v;
  for (int i = 0; i < s.length(); i++) {
    v.push_back(s[i] - '0');
  }
  return v;
}

int next_sum(vector<int> v) {
  long long int s = 0;
  for (int i = 0; i < v.size()-1; i++) if (v[i] == v[i+1]) s += v[i];
  if (v[0] == v[v.size() - 1]) s += v[0];
  return s;
}

int main() {
  ifstream fin ("nextmatch.in");
  ofstream fout ("nextmatch.out");
  
  string s;
  fin >> s;
  vector<int> v;
  v = digitize(s);
  fout << next_sum(v) << "\n";
}
