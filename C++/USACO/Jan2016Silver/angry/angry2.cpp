/*
ID: jorlee
PROG: angry
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
vector<int> hayloc;
vector<int> hayspace;

int main () {
  ifstream fin ("angry.in");
  ofstream fout ("angry.out");
  
  fin >> N >> K;
  for (int i = 0; i < N; i++) {
    int a;
    fin >> a;
    hayloc.push_back(a);
    //    cout << hayloc[i] << endl;
  }
  
  sort(hayloc.begin(), hayloc.end());
  for (int i = 0; i < N; i++)
    printf("hayloc[%d]: %d\n", i, hayloc[i]);
  
  for (int i = 0; i < N - 1; i++) {
    int space = hayloc[i + 1] - hayloc[i] - 1;
    hayspace.push_back(space);
    printf("hayspace[%d]: %d\n", i, hayspace[i]);
  }

  bool found = false;
  int r = 1;
  int len = 0;
  while (!found) {
    len = hayloc[0] + 2 * r;
    int index = 0;
    for (int i = 1; i < K; i++) {
      while (hayloc[index] <= len)
	index++;
      len = hayloc[index] + 2 * r;
    }

    if (len >= (hayloc[N - 1] - hayloc[0] + 1))
      found = true;
    else
      r++;
  }

  cout << r << endl;
  fout << r << endl;
  return 0;
}
