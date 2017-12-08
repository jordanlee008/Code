/*
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ridefunc(string s) {
  const int divisor = 47;
  int n = 1;
  for (int i; i < s.size(); i++) {
    n *= s[i] - 'A' + 1;
    n %= divisor;
    printf("%c: %d\n", s[i], n);
  }
  return n;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string comet, group;
    fin >> comet;
    fin >> group;

    int ncomet = ridefunc(comet);
    int ngroup = ridefunc(group);
    if (ncomet == ngroup) {
      fout << "GO" << endl;
    }
    else {
      fout << "STAY" << endl;
    }

    return 0;
}
