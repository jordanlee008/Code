/*
ID: jorlee
PROG: gates
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int fence[2001][2001]; //fence[1000][1000] = (0, 0)
vector<char> path;

int main () {
  ifstream fin ("gates.in");
  ofstream fout ("gates.out");
  
  fin >> N;

  int x = 1000, y = 1000;
  int count = 0;
  fence[1000][1000] = 1;
  
  for (int i = 0; i < N; i++) {
    char a;
    fin >> a;
    path.push_back(a);
    printf("path[%d]: %c\n", i, path[i]);
    
    if (a == 'N') {
      if ((fence[x][y + 1] > 0) && (path[i - 1] != 'S') && (fence[x][y] == 1)) {
	count++;
	printf("(x, y) = (%d, %d)\n", x - 1000, y - 1000);
	fence[x][y] = 0;
      }
      fence[x][y + 1] += 1;
      y += 1;
    } else if (a == 'W') {
      if ((fence[x - 1][y] > 0) && (path[i - 1] != 'E') && (fence[x][y] == 1)) {
	count++;
	printf("(x, y) = (%d, %d)\n", x - 1000, y - 1000);
	fence[x][y] = 0;
      }
      fence[x - 1][y] += 1;
      x -= 1;
    } else if (a == 'E') {
      if ((fence[x + 1][y] > 0) && (path[i - 1] != 'W') && (fence[x][y] == 1)) {
	count++;
	printf("(x, y) = (%d, %d)\n", x - 1000, y - 1000);
	fence[x][y] = 0;
      }
      fence[x + 1][y] += 1;
      x += 1;
    } else {
      if ((fence[x][y - 1] > 0) && (path[i - 1] != 'N') && (fence[x][y] == 1)) {
	count++;
	printf("(x, y) = (%d, %d)\n", x - 1000, y - 1000);
	fence[x][y] = 0;
      }
      fence[x][y - 1] += 1;
      y -= 1;
    }
  }

  cout << "count: " << count << endl;
  fout << count << endl;
  
  return 0;
}
