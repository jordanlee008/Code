/*
ID: jorlee
PROG: highcard
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ifstream fin ("highcard.in");
  ofstream fout ("highcard.out");

  int N;
  fin >> N;

  vector<int> e;
  vector<int> b;

  for (int i = 0; i < N; i++) {
    int a;
    fin >> a;
    e.push_back(a);
  }
  
  //  for (int i = 0; i < N; i++) printf("ebefore[%d] = %d\n", i, e[i]);
  sort(e.begin(), e.end());
  //  for (int i = 0; i < N; i++) printf("eafter[%d] = %d\n", i, e[i]);

  int last = 0;
  for (int i = 0; i < N; i++) {
    for (int j = last+1; j < e[i]; j++) {
      b.push_back(j);
    }
    last = e[i];
  }
  for (int i = e[N-1]+1; i <= 2*N; i++) {
    b.push_back(i);
  }

  for (int i = 0; i < N; i++) { printf("b: %d, e: %d\n",b[i],e[i]); }
  
  int count = 0;
  int ec = 0;
  for (int i = 0; i < N; i++) {
    if (b[i] > e[ec]) {
      //      printf("b[%d] = %d\ne[%d] = %d\n", i, b[i], ec, e[ec]);
      ec++;
      count++;
    }
  }

  fout << count << endl;
  
  return 0;
}
