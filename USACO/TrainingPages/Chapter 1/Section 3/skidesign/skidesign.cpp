/*
ID: jorlee
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");

  int nHills;
  fin >> nHills;
  int hills[1000];
  for (int i = 0; i < nHills; i++)
    fin >> hills[i];
  
  sort(hills, hills + nHills);

  int mincost = nHills*100*100;
  for (int i = 0; i < nHills; i++) {
    for (int minh = hills[i] - 17; minh <= hills[i]; minh++) {
      int cost = 0;
      for (int j = 0; j < nHills; j++) {
	if ((hills[j] - minh) > 17)
	  cost += (hills[j] - minh - 17)*(hills[j] - minh - 17);
	else if ((hills[j] - minh) < 0)
	  cost += (hills[j] - minh)*(hills[j] - minh);
      }//end for difcalc
      if (cost < mincost)
	mincost = cost;
    }//end for minheight
  }//end hill for

  fout << mincost << endl;
}//end main
