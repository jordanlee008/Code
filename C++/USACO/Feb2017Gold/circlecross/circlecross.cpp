#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
int c[100000];
int p[50000][2];
int open[100000];
int close[100000];
int cross = 0;

int main() {
  ifstream fin ("circlecross.in");
  ofstream fout ("circlecross.out");

  fin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    p[i][0] = p[i][1] = -1;
  }
  
  for (int i = 0; i < 2 * n; i++) {
    fin >> c[i];
    c[i]--;
    if (p[c[i]][0] == -1) {
      p[c[i]][0] = i;
      cross -= open[i - 1];
      cross += close[i - 1];
      cross -= i;
      
      open[i] = open[i - 1] + 1;
      close[i] = close[i - 1];
    }
    else {
      p[c[i]][1] = i;
      cross -= close[i - 1];
      cross += open[i - 1] - 1;
      cross += i - 1;
      
      open[i] = open[i - 1];
      close[i] = close[i - 1] + 1;
    }
  }
  
  for (int i = 0; i < 2 * n; i++) {
    cout << open[i] << " " << close[i] << "\n";
  }
  //  cout << cross << "\n";
  fout << cross << "\n";
}
