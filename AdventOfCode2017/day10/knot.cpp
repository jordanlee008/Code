#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream fin ("knot.in");
  ofstream fout ("../day14/disk.in");

  string s;
  fin >> s;
  for (int disk = 0; disk < 128; disk++) {
    vector<int> ls;
    string s0 = s;
    s0 += '-';
    s0 += to_string(disk);
    cout << s0 << "\n";
    for (int i = 0; i < s0.length(); i++) ls.push_back(int(s0[i]));
    ls.insert(ls.end(), {17,31,73,47,23});
    
    
    vector<int> k;
    for (int i = 0; i < 256; i++) k.push_back(i);
    int cur = 0, skip = 0;
    for (int z = 0; z < 64; z++) {
      for (int i = 0; i < ls.size(); i++) {
	// flip stuff
	for (int j = 0; j < ls[i]/2; j++) {
	  swap(k[(cur + j) % 256], k[(cur + ls[i] - j - 1) % 256]);
	}
	cur += ls[i] + skip;
	skip++;
      }
    }

    vector<int> dk;
    for (int i = 0; i < 16; i++) {
      int x = k[16*i];
      for (int j = 1; j < 16; j++) {
	x = x ^ k[16*i + j];
      }
      dk.push_back(x);
    }

    for (int i = 0; i < 16; i++) {
      if (dk[i] < 16) fout << "0";
      fout << hex << dk[i];
    }
    fout << "\n";
  }
}
