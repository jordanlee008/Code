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
  hayspace.push_back(0);
  
  vector<int> bigindex;
  for (int i = 0; i < K - 1; i++) {
    bigindex.push_back(N - 1);
  }
  
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < bigindex.size(); j++) {
      if (hayspace[i] >= hayspace[bigindex[j]]) {
	bigindex.erase(bigindex.begin() + j);
	bigindex.insert(bigindex.begin() + j, i);
	break;
      }
    }
  }
  
  bigindex.insert(bigindex.begin(), -1);
  bigindex.push_back(N - 1);

  sort(bigindex.begin(), bigindex.end());
  
  for (int i = 0; i < bigindex.size(); i++) {
    printf("bigindex[%d]: %d\n", i, bigindex[i]);
  }
  
  int radius = 0;
  for (int i = 0; i < bigindex.size() - 1; i++) {
    int len = hayloc[bigindex[i + 1]] - hayloc[bigindex[i] + 1] + 1;
    cout << "i: " << i << " len: " << len << endl;
    radius = max(radius, (len / 2));
  }

  radius = min(radius, (hayloc[N - 1] - hayloc[0]) / (2 * K));
  
  cout << "radius: " << radius << endl;
  fout << radius << endl;
  return 0;
}
