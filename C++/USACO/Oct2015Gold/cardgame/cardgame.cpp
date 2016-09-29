/*
ID: jorlee
PROG: cardgame
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N;
vector<int> e;
vector<int> b;

int main () {
  ifstream fin ("cardgame.in");
  ofstream fout("cardgame.out");

  fin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    fin >> a;
    e.push_back(a);
  }

  vector<int> esorted = e;
  sort(esorted.begin(), esorted.end());
  
  int last = 0;
  for (int i = 0; i < N; i++) {
    for (int j = last + 1; j < esorted[i]; j++) {
      b.push_back(j);
    }
    last = esorted[i];
  }
  for (int i = esorted[N-1] + 1; i <= 2*N; i++) {
    b.push_back(i);
  }

  vector<int> efirst;
  for (int i = 0; i < N / 2; i++)
    efirst.push_back(e[i]);
  sort(efirst.begin(), efirst.end());
  
  vector<int> esecond;
  for (int i = 0; i < N / 2; i++)
    esecond.push_back(e[(N / 2) + i]);
  sort(esecond.begin(), esecond.end());
  
  int out = 0;

  for (int i = 0; i < N; i++)
    printf("b[%d] = %d\n", i, b[i]);
  
  int index = (N / 2) - 1;
  int i = N - 1;
  while (i >= 0 && index >= 0) {
    if (b[i] > efirst[index]) {
      printf("e[%d] = %d\n", index, e[index]);
      b[i] = 2 * N + 1;
      i--;
      out++;
    }
    index--;
  }

  cout << out << endl;
  for (int i = 0; i < N; i++)
    printf("b[%d] = %d\n", i, b[i]);

  index = 0;
  i = 0;
  while (index < N / 2 && i < N / 2) {
    if (b[i] < esecond[index]) {
      printf("e[%d] = %d\n", index, esecond[index]);
      b[i] = 0;
      i++;
      out++;
    }
    index++;
  }

  for (int i = 0; i < N; i++)
    printf("b[%d] = %d\n", i, b[i]);

  cout << out << endl;
  fout << out << endl;
  return 0;
}
