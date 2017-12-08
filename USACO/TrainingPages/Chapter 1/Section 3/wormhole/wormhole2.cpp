#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int nmax = 12;

int nw;
int w[nmax][2];
int nextright[nmax];
int partner[nmax];

bool cycle_exists (void) {
  for (int start = 0; start < nw; start++) {
    //start is index for starting wormhole
    int pos = start;
    for (int count = 0; count < nw; count++)
      //only checks nw wormholes - or else continue infinite if there is cycle
      //set pos to the wormhole that we will first encounter
      //loops through to keep going to the wormhole on the right
      pos = nextright[partner[pos]];
    if (pos != 0)
      return true;
  }
  return false;
}

int solve (void) {
  int total = 0;
  int i;
  
  //find first wormhole that is unpaired
  for (i = 0; i < nw; i++)
    if (partner[i] == 0)
      break;

  //base case - for when all is paired, return the number of solutions
  if (i >= nw)
    if (cycle_exists)
      return 1;
    else
      return 0;
  
  //pair wormhole i with some other j
  for (int j = i + 1; j < nw; j++)
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;
      //call solve again to find the next node
      total += solve();
      //clear partner board so that it will find next node again
      partner[i] = partner[j] = 0;
    }
  return total;
}

int main (void) {
  ifstream fin ("wormhole.in");
  ofstream fout ("wormhole.out");

  fin >> nw;
  for (int i = 0; i < nw; i++)
    fin >> w[i][0] >> w[i][1];

  //try to pair all wormholes so that we can fill out the next on right map
  for (int i = 0; i < nw; i++)
    for (int j = 0; j < nw; j++)
      if (w[i][0] < w[j][0] && w[i][1] == w[j][1])
	if (nextright == 0 || w[j][0] - w[i][0] < w[nextright[i]][0] - w[i][0])
	  nextright[i] = j;

  fout << solve() << endl;
}
