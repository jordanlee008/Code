#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int main() {
  ifstream fin ("pipe.in");
  ofstream fout ("pipe.out");

  int n;
  fin >> n;
  
  vector< vector<int> > v (n, vector<int>(n,0));
  string s;
  getline(fin,s);
  while (getline(fin,s)) {
    int x = atoi(s.substr(0, s.find(" <->")).c_str());
    
    string s0;
    for (int i = s.find(" <-> ") + 5; i < s.length(); i++) {
      if (s[i] == ' ') {
	v[x][atoi(s0.c_str())] = 1;
	s0 = "";
      } else { s0 += s[i]; }
    }
    v[x][atoi(s0.c_str())] = 1;
  }

  vector<int> f(n,0);
  int g = 0;
  
  for (int i = 0; i < n; i++) {
    if (f[i]) continue;

    g++;
    deque<int> d = {i};
    f[i] = 1;
    
    while (!d.empty()) {
      int x = d[0];
      d.pop_front();
      for (int j = 0; j < n; j++) {
	if (v[x][j]) {
	  if (f[j] && x != j) {
	    cout << x << " " << j << "\n";
	    cout << "RIP\n";
	  }
	  v[x][j] = v[j][x] = 0;
	  d.push_back(j);
	  f[j] = 1;
	}
      }
    }
  }

  fout << g << "\n";

  /* PART 1
  int sum = 0;
  for (int i = 0; i < n; i++) { if (f[i]) sum++; }
  fout << sum << "\n";
  */
  
}
