/*
ID: jorlee
PROG: paint
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  ifstream fin ("paint.in");
  ofstream fout ("paint.out");

  int n1, n2, m1, m2;

  fin >> n1 >> n2;
  fin >> m1 >> m2;

  int out = 0;

  if (n2 < m1) {
    out = n2 - n1 + m2 - m1;
    fout << out << endl;
  } else if (m2 < n1) {
    out = n2 - n1 + m2 - m1;
    fout << out << endl;
  } else {
    out = max(m2, n2) - min(n1, m1);
    fout << out << endl;
  }
  return 0;
}
