/*
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ofstream fout ("numtri.out");
  ifstream fin ("numtri.in");

  const int rmax = 1000;
  int r;
  fin >> r;

  int c[rmax], sprev[rmax], srow[rmax];
  for (int i = 0; i < r; i++) {
    c[i] = 0;
    sprev[i] = 0;
    srow[i] = 0;
  }

  for (int irow = 1; irow <= r; irow++) {
    for (int i = 0; i < irow; i++) {
      fin >> c[i];
    }
    for (int i = 0; i < irow; i++) {
      if (i > 0) {
	srow[i] = (sprev[i] > sprev[i-1]) ? sprev[i]+c[i] : sprev[i-1]+c[i];
      }
      else {
	srow[i] = sprev[i]+c[i];
      }
    }
    for (int i = 0; i < irow; i++) {
      sprev[i] = srow[i];
      cout << srow[i] << " ";
    }
    cout << endl;
  }
  
  int smax = 0;
  for (int i = 0; i < r; i++) {
    if (srow[i] > smax) smax = srow[i];
  }
  fout << smax << endl;

  return 0;
}
