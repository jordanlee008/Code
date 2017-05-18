#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

#define VI vector<int>

int N;
vector<VI> p; // painting
int colors[1601];
vector<int> col;
int ind[1601];
int cd[1601][4]; // values about the colors
// 0 - min x
// 1 - max x
// 2 - min y
// 3 - max y

int main() {
  ifstream fin ("art.in");
  ofstream fout ("art.out");
  
  fin >> N;
  VI e;
  for (int i = 0; i < N; i++) {
    p.push_back(e);
    for (int j = 0; j < N; j++) {
      int c;
      fin >> c;
      p[i].push_back(c);
      cout << p[i][j] << " ";
      cd[N * i + j + 1][0] = N;
      cd[N * i + j + 1][2] = N;
      colors[c] = 1;
    }
    cout << "\n";
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (cd[p[i][j]][0] > j) cd[p[i][j]][0] = j;
      if (cd[p[i][j]][2] > i) cd[p[i][j]][2] = i;
      if (cd[p[i][j]][1] < j) cd[p[i][j]][1] = j;
      if (cd[p[i][j]][3] < i) cd[p[i][j]][3] = i;
      if (colors[N * i + j + 1]) {
	col.push_back(N * i + j + 1);
	ind[N * i + j + 1] = col.size() - 1;
      }
    }
  }
  
  for (int i = 0; i < col.size(); i++) cout << col[i] << " ";
  cout << "\n";

  /*  for (int i = 0; i < N * N; i++) {
    printf("%d\tminx: %d\t maxx: %d\tminy: %d\t maxy: %d\n", i, cd[i][0], cd[i][1], cd[i][2], cd[i][3]);
    }*/
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vector<int> colsq;
      for (int c : col) {
	if (i >= cd[c][2] && i <= cd[c][3] && j >= cd[c][0] && j <= cd[c][1] && c != p[i][j]) colsq.push_back(c);
      }
      
      for (int k = 0; k < colsq.size(); k++) {
	if (ind[colsq[k]] > ind[p[i][j]]) {
	  swap(ind[colsq[k]], ind[p[i][j]]);
	  swap(col[colsq[k]], col[p[i][j]]);
	}
      }
      
    }
  }
  

}
