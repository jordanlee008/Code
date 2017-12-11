#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin ("hex.in");
  ofstream fout ("hex.out");

  vector<int> i_mv;
  vector<int> pos = {0,0,0};
  vector<int> d;
  string s;
  while (fin >> s) {    
    if (s == "n") { i_mv.push_back(1); pos[0]++; }
    else if (s == "ne") { i_mv.push_back(2); pos[1]++; }
    else if (s == "se") { i_mv.push_back(3); pos[2]++; }
    else if (s == "s") { i_mv.push_back(4); pos[0]--; }
    else if (s == "sw") { i_mv.push_back(5); pos[1]--; }
    else if (s == "nw") { i_mv.push_back(6); pos[2]--; }
    else i_mv.push_back(0);

    vector<int> dis = {0,0,0};
    // n + se = ne
    pos[1] += pos[0];
    pos[2] -= pos[0];
    pos[0] = 0;
    for (int i = 0; i < pos.size(); i++) { dis[0] += abs(pos[i]); }
    pos[2] += pos[1];
    pos[0] += pos[1];
    pos[1] = 0;
    for (int i = 0; i < pos.size(); i++) { dis[1] += abs(pos[i]); }
    pos[0] -= pos[2];
    pos[1] += pos[2];
    pos[2] = 0;
    for (int i = 0; i < pos.size(); i++) { dis[2] += abs(pos[i]); }
    d.push_back(*min_element(dis.begin(), dis.end()));
  }
  
  // PART 1
  fout << d[d.size()-1] << "\n";
  // PART 2
  fout << *max_element(d.begin(), d.end()) << "\n";
}
