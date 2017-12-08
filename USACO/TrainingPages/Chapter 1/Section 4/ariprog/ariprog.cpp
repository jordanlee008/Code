/*
ID: jorlee
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> IntPair;

int length = 0;
int ubound = 0;

bool IntPairComp(const IntPair &l, const IntPair &r) {
  if (l.second < r.second) return true;
  if (l.second > r.second) return false;
  if (l.first < r.first) return true;
  else return false;
}

int solve () {
  ofstream fout ("ariprog.out");

  //table of bisquares
  bool bisq[10*250*250];
  for (int p = 0; p <= ubound; p++)
    for (int q  = 0; q <= ubound; q++)
      bisq[p*p + q*q] = true;

  //make a vector of all possible bisquares
  vector<int> lbisq;
  for (int i = 0; i <= 2*ubound*ubound; i++)
    if (bisq[i]) {
      lbisq.push_back(i);
    }

  //test arithmetic sequences for bisquares
  vector<IntPair> output; 
  for (int i = 0; i < lbisq.size(); i++) {
    int a = lbisq[i];
    for (int j = i + 1; j < lbisq.size(); j++) {
      bool good = true;
      int b = lbisq[j] - a;
      for (int x = 2; x < length; x++)
	if (!bisq[a + b*x]) {
	  good = false;
	  break;
	}
      if (good)
	output.push_back(IntPair(a,b));
    }//end for a
  }//end for b

  //sort output
  sort(output.begin(), output.end(), IntPairComp);

  //output answers
  for (int i = 0; i < output.size(); i++)
    fout << output[i].first << " " << output[i].second << endl;
  if (output.size() == 0)
    fout << "NONE" << endl;
  
  return 1;
}

int main () {
  ifstream fin ("ariprog.in");
  ofstream fout ("ariprog.out");
  fin >> length >> ubound;
  solve();
}//end main
