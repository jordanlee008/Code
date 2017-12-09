#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin ("garbage.in");
  ofstream fout ("garbage.out");
  
  string s;
  fin >> s;
  int tot_score = 0;
  int cur_score = 0;
  int tot_gar = 0;
  bool garb = false;
  bool ign = false;
  for (int i = 0; i < s.length(); i++) {
    if (ign) {
      ign = false;
      continue;
    }
    if (garb && (s[i] != '!' && s[i] != '>')) {
      tot_gar++;
    } else {
      if (s[i] == '{') cur_score++;
      if (s[i] == '}') { tot_score += cur_score; cur_score--; }
    }
    if (s[i] == '!') { ign = true; continue; }
    if (s[i] == '<') garb = true;
    if (s[i] == '>') { garb = false; }
  }
  
  cout << tot_gar << "\n";
  cout << tot_score << "\n";
}
