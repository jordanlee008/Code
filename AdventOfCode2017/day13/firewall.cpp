#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ifstream fin ("firewall.in");
  ofstream fout ("firewall.out");

  int n;
  fin >> n;
  vector<int> l(n,0);
  string s;
  while (getline(fin,s)) {
    int layer = atoi(s.substr(0,s.find(":")).c_str());
    int depth = atoi(s.substr(s.find(":")+1).c_str());
    l[layer] = depth;
  }

  for (int i = 0; i < n; i++) cout << l[i] << " ";
  cout << "\n"; 

  bool safe = false;
  int d = -1;
  while (!safe) {
    d++;
    vector<int> caught;
    for (int i = 0; i < n; i++) {
      if (l[i] == 0) continue;
      
      int p = (d+i) % (l[i] + l[i] - 2);
      if (p == 0) caught.push_back(i);
    }
    
    if (caught.size() == 0) { safe = true; }
  }
  
  /*for (int i = 0; i < caught.size(); i++) fout << caught[i] << " ";
  fout << "\n";

  int sum = 0;
  for (int i = 0; i < caught.size(); i++) sum += l[caught[i]]*caught[i];
  fout << sum << "\n"; */

  fout << d << "\n";
}
