/*
ID: jorlee
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nr;
int tri[1000][1000];
int ctri[1000][1000];

void solve () {
  for (int i = nr - 1; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      ctri[i][j] = tri[i][j] + max(ctri[i + 1][j], ctri[i + 1][j + 1]);
}

int main (void) {
  ifstream fin ("numtri.in");
  ofstream fout ("numtri.out");
  fin >> nr;
  for (int i = 0; i < nr; i++)
    for (int j = 0; j <= i; j++)
      fin >> tri[i][j]; 
  for (int i = 0; i < nr; i++)
    ctri[nr - 1][i] = tri[nr - 1][i];
  solve();
  for (int i = 0; i < nr; i++) {
    for(int j = 0; j <= i; j++) {
      cout << ctri[i][j] << " ";
    }
    cout << endl;
  }
  fout << ctri[0][0] << endl;
  return 0;
}
