/*
ID: jorlee
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int nw;
int w[13][2];
int partner[13] = {0};
int nextright[13] = {0};

bool loop (void) {
  for (int start = 1; start <= nw; start++) {
    int pos = start;
    for (int count = 1; count <= nw; count++) {
      pos = nextright[partner[pos]];
    }
    if (pos != 0)
      return true;
  }
  return false;
}

int solve (void) {
  int total = 0;
  
  //pair up wormholes
  int index;
  for (index = 1; index <= nw; index++)
    if (partner[index] == 0)
      break;
  
  if (index > nw)
    if (loop()) return 1;
    else return 0;
  
  for (int j = index + 1; j <= nw; j++) {
    if (partner[j] == 0) {
      partner[j] = index;
      partner[index] = j;
      total += solve();
      partner[j] = partner[index] = 0;
    }
  }
  return total;
}

int main (void) {
  ifstream fin ("wormhole.in");
  ofstream fout ("wormhole.out");
  
  fin >> nw;
  for (int i = 1; i <= nw; i++)
    fin >> w[i][0] >> w[i][1];
  
  //find next right
  for (int i = 1; i <= nw; i++)
    for (int j = 1; j <= nw; j++)
      if (w[j][1] == w[i][1] && w[j][0] > w[i][0])
	if (w[j][0] - w[i][0] < w[nextright[i]][0] - w[i][0] || nextright[i] == 0)
	  nextright[i] = j;
  
  fout << solve() << endl;
}
