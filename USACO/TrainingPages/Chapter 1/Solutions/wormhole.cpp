/*
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int nmax = 12;

int nstuck = 0;
int nw;
int w[nmax][2];

int walkhole(int i0, int holes[][2], int n) {
  int x = holes[i0][0];
  int y = holes[i0][1];
  int ihole = -1;
  int xhole = 1E9;
  for (int i = 0; i < n; i++) {
    if (holes[i][1] == y) {
      if ((holes[i][0] > x) && (holes[i][0] < xhole)) {
	ihole = i;
	xhole = holes[i][0];
      }
    }
  }
  return ihole;
}

int testcycle(int hnext[], int holes[][2], int n) {
  for (int i0 = 0; i0 < n; i0++) {
    int i1 = i0;
    int ncycle = 0;
    while ((i1 = walkhole(i1, holes, n)) >= 0) {
      i1 = hnext[i1];
      ncycle++;
      if (ncycle > n) return 1;
    }
    //    cout << "test: " << i0 << " " << ncycle << endl;
  }
  return 0;
}

int pairings(vector<int> p) {
  int np = p.size();

  /*
  cout << "input: ";
  for (int i = 0; i < np; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
  */

  for (int i = 0; i < np; i++) {
    if (p[i] < 0) {
      int ncall = 0;
      for (int j = i+1; j < np; j++) {
	if (p[j] < 0) {
	  p[i] = j;
	  p[j] = i;
	  ncall += pairings(p);
	  p[j] = -1;
	}
      }
      return ncall;
    }
  }

  int stuck = testcycle(&p[0], w, nw);
  if (stuck) nstuck++;

  cout << "pairing: ";
  for (int i = 0; i < np; i++) {
    cout << p[i] << " ";
  }
  if (stuck) {
    cout << "Stuck!";
  }
  cout << endl;
  
  return 1;
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");

    fin >> nw;
    for (int i = 0; i < nw; i++) {
      fin >> w[i][0] >> w[i][1];
    }

    vector<int> p(nw);
    for (int i = 0; i < nw; i++) {
      p[i] = -1;
    }
    cout << "NPairings = " << pairings(p) << endl;

    fout << nstuck << endl;

    return 0;
}
