/*
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int nmax = 50;
int m, n;
int mwall[nmax][nmax];
int mfill[nmax][nmax];

typedef pair<int, int> IntPair;

int flood(int i1, int j1, int label) {
  vector<IntPair> queue;
  queue.push_back(IntPair(i1, j1));

  int count = 0;
  while (queue.size() > 0) {
    IntPair a = queue.front();
    queue.erase(queue.begin());

    if (mfill[a.first][a.second] == label) continue;

    mfill[a.first][a.second] = label;
    count++;

    IntPair b(a);
    // West
    if (!(mwall[a.first][a.second] & 0x01)) {
      b.first = a.first;
      b.second = a.second - 1;
      queue.push_back(b);
    }
    // North
    if (!(mwall[a.first][a.second] & 0x02)) {
      b.first = a.first - 1;
      b.second = a.second;
      queue.push_back(b);
    }
    // East
    if (!(mwall[a.first][a.second] & 0x04)) {
      b.first = a.first;
      b.second = a.second + 1;
      queue.push_back(b);
    }
    // South
    if (!(mwall[a.first][a.second] & 0x08)) {
      b.first = a.first + 1;
      b.second = a.second;
      queue.push_back(b);
    }
  }
  return count;
}

int main() {
  ofstream fout ("castle.out");
  ifstream fin ("castle.in");

  vector<int> mcounts;

  fin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fin >> mwall[i][j];
      mfill[i][j] = 0;
    }
  }

  int nlabel = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mfill[i][j] <= 0) {
	mcounts.push_back(flood(i, j, nlabel));
	nlabel++;
      }
    }
  }
  nlabel--; // 1..label in mfill[][]

  fout << nlabel << endl; // number of rooms

  int maxcount = 0;
  for (int i = 0; i < nlabel; i++) {
    if (mcounts[i] > maxcount) maxcount = mcounts[i];
  }
  fout << maxcount << endl; // size of largest room


  // Wall removal tests:
  maxcount = 0;
  int iwall, jwall;
  char dir;
  // Highest priority is farthest west, then south:
  for (int j = 0; j < m; j++) {
    for (int i = n-1; i >= 0; i--) {
      int label1 = mfill[i][j];
      int c1 = mcounts[label1-1];
      
      int label2, c2;
      // North
      if ((mwall[i][j] & 0x02) && (i >= 1)) {
	label2 = mfill[i-1][j];
	c2 = mcounts[label2-1];
	if ((label2 != label1) && (c1 + c2 > maxcount)) {
	  maxcount = c1 + c2;
	  iwall = i;
	  jwall = j;
	  dir = 'N';
	}
      }
      // East
      if ((mwall[i][j] & 0x04) && (j < m-1)) {
	label2 = mfill[i][j+1];
	c2 = mcounts[label2-1];
	if ((label2 != label1) && (c1 + c2 > maxcount)) {
	  maxcount = c1 + c2;
	  iwall = i;
	  jwall = j;
	  dir = 'E';
	}
      }
    }
  }
  fout << maxcount << endl; // size of largest room created by removing one wall
  fout << iwall+1 << " " << jwall+1 << " " << dir << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mfill[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
