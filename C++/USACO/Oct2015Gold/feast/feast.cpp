/*
ID: jorlee
PROG: feast
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("feast.in");
  ofstream fout ("feast.out");

  int T, A, B;
  fin >> T >> A >> B;

  bool done[2][T + 1];
  done[0][1] = true;

  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= T; j++) {
      if (!done[i][j])
	continue;
      if (j + A <= T)
	done[0][j + A] = true;
      if (j + B <= T)
	done[0][j + B] = true;
      if (i == 0)
	done[1][j / 2] = true;
    }
  }

  int ret = T;
  while (!done[1][ret])
    ret--;
  fout << ret << endl;
  
  return 0;
}
