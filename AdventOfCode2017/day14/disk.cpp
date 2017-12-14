#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

vector<int> htob(string s) { // hex to dec
  vector<int> v;
  for (int i = 0; i < s.length(); i++) {
    switch (s[s.length()-i-1]) {
    case '0':
      v.insert(v.begin(),{0,0,0,0});
      break;
    case '1':
      v.insert(v.begin(),{0,0,0,1});
      break;
    case '2':
      v.insert(v.begin(),{0,0,1,0});
      break;
    case '3':
      v.insert(v.begin(),{0,0,1,1});
      break;
    case '4':
      v.insert(v.begin(),{0,1,0,0});
      break;
    case '5':
      v.insert(v.begin(),{0,1,0,1});
      break;
    case '6':
      v.insert(v.begin(),{0,1,1,0});
      break;
    case '7':
      v.insert(v.begin(),{0,1,1,1});
      break;
    case '8':
      v.insert(v.begin(),{1,0,0,0});
      break;
    case '9':
      v.insert(v.begin(),{1,0,0,1});
      break;
    case 'a':
      v.insert(v.begin(),{1,0,1,0});
      break;
    case 'b':
      v.insert(v.begin(),{1,0,1,1});
      break;
    case 'c':
      v.insert(v.begin(),{1,1,0,0});
      break;
    case 'd':
      v.insert(v.begin(),{1,1,0,1});
      break;
    case 'e':
      v.insert(v.begin(),{1,1,1,0});
      break;
    case 'f':
      v.insert(v.begin(),{1,1,1,1});
      break;
    }
  }
  return v;
}

int main() {
  ifstream fin ("disk.in");
  ofstream fout ("disk.out");
  
  int u = 0;
  vector< vector<int> > b;
  for (int i = 0; i < 128; i++) {
    string s;
    fin >> s;
    vector<int> v = htob(s);
    b.push_back(v);
    for (int j = 0; j < v.size(); j++) if (v[j]) u++;
  }
  
  int reg = 1;
  for (int i = 0; i < 128*128; i++) {
    deque<int> d;
    if (b[i/128][i%128] == 1) { d.push_back(i); reg++; }
    while (!d.empty()) {
      int c = d[0];
      d.pop_front();
      
      b[c/128][c%128] = reg;
      int c_n;
      c_n = c - 1;
      if (c%128 > 0 && b[c_n/128][c_n%128] == 1) d.push_back(c_n);
      c_n = c + 1;
      if (c%128 < 127 && b[c_n/128][c_n%128] == 1) d.push_back(c_n);
      c_n = c - 128;
      if (c/128 > 0 && b[c_n/128][c_n%128] == 1) d.push_back(c_n);
      c_n = c + 128;
      if (c/128 < 127 && b[c_n/128][c_n%128] == 1) d.push_back(c_n);
    }
  }
  
  fout << "used " << u << "\n";
  fout << "regions " << reg-1 << "\n";
}
