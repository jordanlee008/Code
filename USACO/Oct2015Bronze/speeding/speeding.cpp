/*
ID: jorlee
PROG: speeding
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  ifstream fin ("speeding.in");
  ofstream fout ("speeding.out");

  int N, M;
  fin >> N >> M;
  
  vector< vector<int> > n (N), m (M);
  for (int i = 0; i < N; i++) {
    vector<int> a (2);
    fin >> a[0] >> a[1];
    n[i] = a;
  }
  for (int i = 0; i < M; i++) {
    vector<int> a (2);
    fin >> a[0] >> a[1];
    m[i] = a;
  }
  
  vector< vector<int> > len (100);
  for (int i = 0; i < N; i++) {
    int a = 0;
    for (int j = 0; j < i; j++) {
      a += n[j][0];
    }
    for (int k = 0; k < n[i][0]; k++)
      len[a + k].push_back(n[i][1]);
  }

  for (int i = 0; i < M; i++) {
    int a = 0;
    for (int j = 0; j < i; j++) {
      a += m[j][0];
    }
    for (int k = 0; k < m[i][0]; k++)
      len[a + k].push_back(m[i][1]);
  }

  int out = 0;
  for (int i = 0; i < 100; i++) {
    if (len[i][0] < len[i][1])
      out = max(len[i][1] - len[i][0], out);
  }
  
  fout << out << endl;
  
  return 0;
}
