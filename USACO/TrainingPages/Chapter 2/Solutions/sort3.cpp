/*
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int nkey = 3;
int mval[nkey][nkey] = { };

int trace() {
  int n = 0;
  for (int i = 0; i < nkey; i++) {
    n += mval[i][i];
  }
  return n;
}

int exchange2() {
  int nexc = 0;
  for (int i = 0; i < nkey; i++) {
    for (int j = 0; j < nkey; j++) {
      if (i == j) continue;
      while ((mval[i][j] > 0) && (mval[j][i] > 0)) {
	mval[i][j]--;
	mval[j][i]--;
	mval[i][i]++;
	mval[j][j]++;
	nexc++;
      }
    }
  }
  return nexc;
}

int exchange3() {
  int nexc = 0;
  for (int i = 0; i < nkey; i++) {
    for (int j = 0; j < nkey; j++) {
      if (i == j) continue;
      for (int k = 0; k < nkey; k++) {
	if ((k == i) || (k == j)) continue;
	while ((mval[i][j] > 0) && (mval[j][k] > 0) && mval[k][i] > 0) {
	  mval[i][j]--;
	  mval[j][k]--;
	  mval[k][i]--;
	  mval[i][i]++;
	  mval[j][j]++;
	  mval[k][k]++;
	  nexc += 2;
	}
      }
    }
  }
  return nexc;
}

int main() {
  ofstream fout ("sort3.out");
  ifstream fin ("sort3.in");

  int n;
  fin >> n;

  int x[n];
  int counts[nkey] = { };
  for (int i = 0; i < n; i++) {
    fin >> x[i];
    counts[x[i]-1]++;
  }

  // Organize keys in terms of sorted regions:
  int nn = 0;
  for (int ikey = 0; ikey < nkey; ikey++) {
    for (int j = 0; j < counts[ikey]; j++) {
      int label = x[nn++] - 1;
      mval[ikey][label]++;
    }
  }

  for (int ikey = 0; ikey < nkey; ikey++) {
    cout << mval[ikey][0] << " " << mval[ikey][1] << " " << mval[ikey][2] << endl;
  }

  int nexc = 0;
  while (trace() < n) {
    int n2 = exchange2();
    cout << "Exchange2(): " << n2 << endl;
    nexc += n2;

    int n3 = exchange3();
    cout << "Exchange3(): " << n3 << endl;
    nexc += n3;      
  }
  
  fout << nexc << endl;
  return 0;
}
