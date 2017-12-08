/*
ID: jorlee
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

const int nmax = 12;
int xCoord[nmax + 1];
int yCoord[nmax + 1];
int nWormhole;
int partner[nmax + 1];
int next_on_right[nmax + 1];

/*
int search(col) {
  if (all col filled)
    return board;
  for (all row) {
    if (col, row not filled) {
      place thing;
      search (col + 1);
      remove thing;
    }
  }
  } */

bool cycle_exists () {
  for (int start = 1; start <= nWormhole; start++) {
    //testing for cycle from start
    int pos = start;
    for (int count = 0; count < nWormhole; count++)
      pos = next_on_right[partner[pos]];
    if (pos != 0)
      return true;
  }//end for starting positions
  /*  for (int i = 1; i <= nWormhole; i++)
    cout << i << ":" << partner[i] << " ";
    cout << endl; */
  return false;
}

int solve () {
  int total = 0;
  int i;
  //find first wormhole that is not paired
  for (i = 1; i <= nWormhole; i++) {
    if (partner[i] == 0) {
      break;
    }
  }

  //base case - for when all is paired, returns to count number of solutions
  if (i > nWormhole) {
    if (cycle_exists()) {
      return 1;
    }
    else return 0;
  }//end if
  
  //try pairing i with all other wormhole j
  for (int j = i + 1; j <= nWormhole; j++)
    if (partner[j] == 0) {
      partner[i] = j;
      partner[j] = i;
      total = total + solve();
      partner[i] = partner[j] = 0;
    }//end if
  return total;
}//end pairing

int main () {
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
  
  fin >> nWormhole;
  for (int i = 1; i <= nWormhole; i++) {
    fin >> xCoord[i] >> yCoord[i];
    //    cout << xCoord[i] << yCoord[i] << endl;
  }
  
  for (int i = 1; i <= nWormhole; i++)
    for (int j = 1; j <= nWormhole; j++)
      if (xCoord[i] < xCoord[j] && yCoord[i] == yCoord[j]) //j is on right
	if (next_on_right[i] == 0 ||
	    xCoord[j] - xCoord[i] < xCoord[next_on_right[i]] - xCoord[i])
	  next_on_right[i] = j;
  
  fout << solve() << endl;
  
}//end main
