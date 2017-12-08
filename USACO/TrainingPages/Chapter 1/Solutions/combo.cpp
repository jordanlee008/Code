/*
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int valid(int x[3], int y[3], int n) {
  for (int i = 0; i < 3; i++) {
    int z = (n + x[i] - y[i]) % n;
    if ((z > 2) && (z < n-2))
      return 0;
  }
  return 1;
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    int n;
    fin >> n;

    int jcombo[3], mcombo[3];
    fin >> jcombo[0] >> jcombo[1] >> jcombo[2];
    fin >> mcombo[0] >> mcombo[1] >> mcombo[2];

    int nvalid = 0;
    int v[3];
    for (v[0] = 1; v[0] <= n; v[0]++) {
      for (v[1] = 1; v[1] <= n; v[1]++) {
	for (v[2] = 1; v[2] <= n; v[2]++) {
	  if (valid(v, jcombo, n) || valid(v, mcombo, n)) {
	    cout << v[0] << " " << v[1] << " " << v[2] << endl;
	    nvalid++;
	  }
	}
      }
    }

    fout << nvalid << endl;

    return 0;
}
