#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;

vector<int> row(string s) {
  vector<int> v;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') v.push_back(1); // 1 is -
    else v.push_back(0); // 0 is +
  }
  return v;
}

string pan(string s, int k) {
  //  printf("pan(%d)\n", k);
  vector<int> sv = row(s);
  //  for (int i = 0; i < sv.size(); i++) cout << sv[i] << " ";
  //  cout << "\n";
  string o;
  int n = 0;
  for (int i = sv.size() - 1; i >= k - 1; i--) {
    //    for (int i = 0; i < sv.size(); i++) cout << sv[i] << " ";
    //    cout << "\n";
    if (sv[i]) {
      n++;
      for (int j = i; j >= i - (k - 1); j--) sv[j] = 1 - sv[j];
    }
  }
  
  for (int i = k - 1; i >= 0; i--) {
    if (sv[i]) return "IMPOSSIBLE";
  }
  return to_string(n);
}

int main() {  
  cin >> N;
  for (int i = 0; i < N; i++) {
    string s;
    int k;
    cin >> s >> k;
    cout << "Case #" << i + 1 << ": " << pan(s, k) << "\n";
  }
}
