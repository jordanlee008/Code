/*
ID: jorlee
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int nb = 3;
int bsize[nb];
int buckets[nb];
bool cfinal[21];
bool state[21][21][21];

int pour (int b[3]) {
  printf("pouring: %d %d %d\n", b[0], b[1], b[2]);
  if (state[b[0]][b[1]][b[2]])
    return 0;
  state[b[0]][b[1]][b[2]] = true;

  if (b[0] == 0)
    cfinal[b[2]] = true;

  int ncall = 0;
  for (int i = 0; i < nb; i++) {
    for (int j = 0; j < nb; j++) {
      if ((b[i] > 0) && (i != j) && (b[j] < bsize[j])) {
	int d = bsize[j] - b[j];
	if (d > b[i]) d = b[i];
	int bp[3];
	for (int k = 0; k < nb; k++)
	  bp[k] = b[k];
	bp[j] += d;
	bp[i] -= d;
	ncall += pour(bp);
      }
    }
  }
  return ncall;
}

int main () {
  ifstream fin ("milk3.in");
  ofstream fout ("milk3.out");
  fin >> bsize[0] >> bsize[1] >> bsize[2];
  for (int i = 0; i < nb; i++)
    cout << bsize[i] << endl;
  int b[3];
  b[0] = 0;
  b[1] = 0;
  b[2] = bsize[2];
  cout << pour(b) << endl;
  bool output = false;
  for (int i = 0; i <= bsize[2]; i++) {
    if (cfinal[i])
      if (output)
	fout << " " << i;
      else {
	output = true;
	fout << i;
      }
  }
    fout << endl;
  return 0;
}
