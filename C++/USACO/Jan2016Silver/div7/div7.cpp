/*
ID: jorlee
PROG: div7
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> ID;
vector<int> summod;

int main () {
  ifstream fin ("div7.in");
  ofstream fout ("div7.out");
  
  fin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    fin >> a;
    ID.push_back(a);
    printf("ID[%d]: %d\n", i, ID[i]);
  }

  vector< vector<int> > indicies;
  vector<int> a;
  for (int i = 0; i < 7; i++)
    indicies.push_back(a);
  
  summod.push_back(ID[0] % 7);
  indicies[summod[0]].push_back(0);
  for (int i = 1; i < N; i++) {
    summod.push_back((ID[i] + summod[i - 1]) % 7);
    indicies[summod[i]].push_back(i);
  }

  for (int i = 0; i < N; i++)
      printf("summod[%d]: %d\n", i, summod[i]);
  
  int size = 0;
  /*  bool found = false;
  while ((size > 0) && !found) {
    for (int i = 0; i < N - size + 1; i++) {
      if ((summod[i + size - 1] - summod[i]) % 7 == 0) {
	found = true;
	break;
      }
    }
    size --;
  } */

  for (int i = 0; i < 7; i++) {
    if (indicies[i].size() != 0) {
      int tempmax = indicies[i][indicies[i].size() - 1] - indicies[i][0];
      size = max(size, tempmax);
    }
  }

  cout << "size: " << size << endl;
  fout << size << endl;
  
  return 0;
}
