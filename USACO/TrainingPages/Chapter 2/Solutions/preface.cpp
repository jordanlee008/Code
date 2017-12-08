/*
PROG: preface
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
  int val;
  string str;
  int repeats;
} RomanChars;

const RomanChars rs[] = {
  {1000, "M", 3},
  {900, "CM", 1},
  {500, "D", 1},
  {400, "CD", 1},
  {100, "C", 3},
  {90, "XC", 1},
  {50, "L", 1},
  {40, "XL", 1},
  {10, "X", 3},
  {9, "IX", 1},
  {5, "V", 1}, 
  {4, "IV", 1},
  {1, "I", 3},
};
const int nrs = sizeof(rs)/sizeof(RomanChars);

string romanize(int n) {
  string s("");
  while (n > 0) {
    for (int i = 0; i < nrs; i++) {
      if (rs[i].val <= n) {
	int nrep = n/rs[i].val;
	if (nrep > rs[i].repeats) nrep = rs[i].repeats;
	for (int j = 0; j < nrep; j++) {
	  s += rs[i].str;
	  n -= rs[i].val;
	}
      }
    }
  }
  return s;
}

int main() {
  ofstream fout ("preface.out");
  ifstream fin ("preface.in");

  int n;
  fin >> n;

  int counts[26] = { };
  for (int i = 1; i <= n; i++) {
    string sroman = romanize(i);
    cout << i << " " << sroman << endl;
    for (int j = 0; j < sroman.size(); j++) {
      counts[sroman[j]-'A']++;
    }
  }
  
  string sorder("IVXLCDM");
  for (int i = 0; i < sorder.size(); i++) {
    char c = sorder[i];
    if (counts[c-'A'] > 0) {
      fout << c << " " << counts[c-'A'] << endl;
    }
  }

  return 0;
}
