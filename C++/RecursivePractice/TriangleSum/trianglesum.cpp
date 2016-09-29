#include <iostream>
#include <fstream>

using namespace std;

const int nrowmax = 100;
int nrow;
int cell[nrowmax][nrowmax];

int solve (int r, int c) {
  if (r > nrow)
    return 0;
  int t1 = solve(r + 1, c);
  int t2 = solve(r + 1, c + 1);
  int t = max(t1, t2) + cell[r][c];
  return t;
}

int main () {
  ifstream fin ("trianglesum.in");
  ofstream fout ("trianglesum.out");
  
  fin >> nrow;
  for (int i = 0; i < nrow; i++)
    for (int j = 0; j <= i; j++)
      fin >> cell[i][j];
  cout << solve(0, 0) << endl;
}
