/*
ID: ddlee1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count(int index, string s, int n) {
  int shift = 0;
  if (s[index] == 'r') {
    while((shift < n) && (s[(index+shift)%n] != 'b'))
      shift++;
  }
  else if (s[index] == 'b') {
    while((shift < n) && (s[(index+shift)%n] != 'r'))
      shift++;
  }
  else if (s[index] == 'w') {
    while((shift < n) && (s[(index+shift)%n] == 'w'))
      shift++;
    if (shift < n) {
      shift += count((index+shift)%n, s, n);
    }
  }
  else {
    printf("Unknown bead\n");
  }
  if (shift > n) shift = n;
  return shift;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n;
    string beads;

    fin >> n;
    fin >> beads;

    int nmax = 0;
    for (int i = 0; i < n; i++) {
      int n1 = count(i, beads, n);
      int n2 = count((i+n1)%n, beads, n);
      int ntot = n1+n2;
      if (ntot > n) ntot = n;
      if (ntot > nmax) nmax = ntot;
    }

    fout << nmax << endl;

    return 0;
}
