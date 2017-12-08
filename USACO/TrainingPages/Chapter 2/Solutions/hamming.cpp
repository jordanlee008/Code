/*
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int hdist(int x, int y, int b) {
  int z = x ^ y;
  int d = 0;
  for (int i = 0; i < b; i++) {
    if (z & 0x01) d++;
    z >>= 1;
  }
  return d;
}

int main() {
  ofstream fout ("hamming.out");
  ifstream fin ("hamming.in");

  int n,b,d;
  fin >> n >> b >> d;

  int xmax = (1 << (b+1));
  vector<int> codes;

  for (int i = 0; i < n; i++) {
    for (int x = 0; x < xmax; x++) {
      bool valid = true;
      for (int j = 0; j < codes.size(); j++) {
	if (hdist(x, codes[j], b) < d) {
	  valid = false;
	  break;
	}
      }
      if (valid) {
	codes.push_back(x);
	break;
      }
    }
  }

  for (int i = 0; i < codes.size(); i++) {
    fout << codes[i];
    if ((((i+1) % 10) == 0) || (i == codes.size()-1)) {
      fout << endl;
    }
    else {
      fout << " ";
    }
  }

  return 0;
}


/*
// Sorting is only necessary if more than one scoop of each type can be given:
typedef pair<int, int> IntPair;
bool IntPairComp(const IntPair &l, const IntPair &r) {
  return l.first < r.first;
}

vector<int> sort_index(vector<int> v) {
  int n = v.size();
  vector<IntPair> s(n);
  for (int i = 0; i < n; i++) {
    s[i].first = v[i];
    s[i].second = i;
  }
  sort(s.begin(), s.end(), IntPairComp);
  vector<int> index(n);
  for (int i = 0; i < n; i++) {
    index[i] = s[i].second;
  }
  return index;
}
*/
