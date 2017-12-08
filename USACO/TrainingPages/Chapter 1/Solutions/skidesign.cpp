/*
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");

  int n;
  fin >> n;
    
  int x[n];
  for (int i = 0; i < n; i++) {
    fin >> x[i];
  }

  int mincost = n*(100*100);
  for (int i = 0; i < n; i++) {
    // Need to try shifted minimum elevation relative to hill x[i]
    int hmin;
    for (hmin = x[i]-17; hmin <= x[i]; hmin++) { 
      int cost = 0;
      for (int j = 0; j < n; j++) {
	int dx = x[j]-hmin;
	if (dx > 17) {
	  cost += (dx-17)*(dx-17);
	}
	else if (dx < 0) {
	  cost += dx*dx;
	}
      }
      if (cost < mincost) mincost = cost;
    }
  }
  
  fout << mincost << endl;
  
  return 0;
}
