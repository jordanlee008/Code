/*
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int dcheck[] = {0,0,0,0,0,0,0,0,0,0};
int checkdigits(int n) {
  while (n != 0) {
    int r = n % 10;
    n = n / 10;
    if (!dcheck[r]) {
      return 0;
    }
  }
  return 1;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int n;
    fin >> n;
    int d[n];
    for (int i = 0; i < n; i++) {
      fin >> d[i];
      dcheck[d[i]] = 1;
    }

    int ncrypt = 0;
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = 0; i2 < n; i2++) {
	for (int i3 = 0; i3 < n; i3++) {

	  int xi = 100*d[i1]+10*d[i2]+d[i3];

	  for (int j1 = 0; j1 < n; j1++) {
	    int p1 = xi*d[j1];
	    if ((p1 < 100) || (p1 >= 1000) || (!checkdigits(p1))) continue;
	    for (int j2 = 0; j2 < n; j2++) {
	      int p2 = xi*d[j2];
	      if ((p2 < 100) || (p2 >= 1000) || (!checkdigits(p2))) continue;

	      int psum = 10*p1+p2;
	      if ((psum >= 1000) && (psum < 10000) && (checkdigits(psum))) {
		cout << xi << " " << d[j1] << d[j2] << endl;
		ncrypt++;
	      }
	    }
	  }
	}
      }
    }

    fout << ncrypt << endl;

    return 0;
}
