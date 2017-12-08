/*
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n;
    fin >> n;

    int start[n], stop[n];
    int tmin = 1000000;
    int tmax = 0;
    for (int i = 0; i < n; i++) {
      fin >> start[i] >> stop[i];
      if (start[i] < tmin) tmin = start[i];
      if (stop[i] > tmax) tmax = stop[i];
    }

    int tmilk = 0;
    int tidle = 0;
    int t0 = tmin;
    int state = 0;

    for (int t = tmin; t <= tmax; t++) {
      int milking = 0;
      for (int i = 0; i < n; i++) {
	if ((t >= start[i]) & (t < stop[i])) {
	  milking = 1;
	  break;
	}
      }
      if (milking != state) {
	if (milking) {
	  if ((t-t0) > tidle)
	    tidle = t-t0;
	}
	else {
	  if ((t-t0) > tmilk)
	    tmilk = t-t0;
	}
	state = milking;
	t0 = t;
      }
    }

    fout << tmilk << " " << tidle << endl;

    return 0;
}
