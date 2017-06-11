#include <iostream>
#include <vector>

using namespace std;



int main() {
  int r, c;
  cin >> r >> c;
  vector< vector<int> > b (r, vector<int> (c, 0));
  vector<int> rm (r, 0);
  vector<int> cm (c, 0);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> b[i][j];
      if (b[i][j] > b[i][rm[i]]) rm[i] = j;
      if (b[i][j] > b[cm[j]][j]) cm[i] = i;
    }
  }
  
  
  return 0;
}
