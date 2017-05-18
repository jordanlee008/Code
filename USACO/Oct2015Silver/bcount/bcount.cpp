/*
ID: jorlee
PROG: bcount
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("bcount.in");
  ofstream fout ("bcount.out");
  
  int N, Q;
  fin >> N >> Q;
  printf("N: %d\nQ: %d\n", N, Q);
  vector<int> b1;
  vector<int> b2;
  vector<int> b3;
  b1.push_back(0);
  b2.push_back(0);
  b3.push_back(0);
  
  for (int i = 1; i <= N; i++) {
    int a;
    fin >> a;
    if (a == 1) {
      b1.push_back(b1[i - 1] + 1);
      b2.push_back(b2[i - 1]);
      b3.push_back(b3[i - 1]);
    } else if (a == 2) {
      b1.push_back(b1[i - 1]);
      b2.push_back(b2[i - 1] + 1);
      b3.push_back(b3[i - 1]);
    } else {
      b1.push_back(b1[i - 1]);
      b2.push_back(b2[i - 1]);
      b3.push_back(b3[i - 1] + 1);
    }
  }
  
  for (int i = 0; i < Q; i++) {
    int a, b;
    fin >> a >> b;
    fout << b1[b] - b1[a - 1] << " ";
    fout << b2[b] - b2[a - 1] << " ";
    fout << b3[b] - b3[a - 1] << "\n";
  }

  return 0;
}
