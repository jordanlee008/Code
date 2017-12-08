/*
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int nmilk = 3;
int cap[3];
bool cfinal[21] = {false}; 
bool state[21][21][21] = {false};

int pour(vector<int> v) {
  printf("pour: %d %d %d\n", v[0], v[1], v[2]);
  if (state[v[0]][v[1]][v[2]]) {
    return 0;
  }
  state[v[0]][v[1]][v[2]] = true;

  if (v[0] == 0) {
    cfinal[v[2]] = true;
  }

  int ncall = 0;
  for (int i = 0; i < nmilk; i++) {
    for (int j = 0; j < nmilk; j++) {
      if ((i != j) && (v[i] > 0) && (v[j] < cap[j])) {
	int m = cap[j]-v[j];
	if (m > v[i]) m = v[i];
	vector<int> vp(v);
	vp[j] += m;
	vp[i] -= m;
	ncall += pour(vp);
      }
    }
  }
  return ncall;
}

int main() {
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  
  fin >> cap[0] >> cap[1] >> cap[2];
  
  vector<int> v(3);
  v[0] = 0;
  v[1] = 0;
  v[2] = cap[2];

  cout << pour(v);
  bool prev = false;
  for (int i = 0; i <= cap[2]; i++) {
    if (cfinal[i]) {
      if (prev) fout << " ";
      else prev = true;
      fout << i;
    }
  }
  fout << endl;

  return 0;
}
