#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin ("ninetynine.in");
  ofstream fout ("ninetynine.out");

  char c;
  vector< vector<int> > h0 (2, vector<int>(5,0));
  vector< vector<int> > h (2, vector<int>(5,0));
  for (int i = 0; i < 10; i++) {
    fin >> c;
    if (c == 'A') h0[i/5][i%5] = 14;
    else if (c == 'K') h0[i/5][i%5] = 13;
    else if (c == 'Q') h0[i/5][i%5] = 12;
    else if (c == 'J') h0[i/5][i%5] = 11;
    else if (c == 'T') h0[i/5][i%5] = 10;
    else h0[i/5][i%5] = c - '0';
  }
  
  for (int i = 0; i < 5; i++) {
    h = h0;
    int init;
    fin >> init;
    cout << init << "\t";

    vector< vector<int> > p(2, vector<int>(5,0));
    for (int j = 0; j < 10; j++) {
      fin >> c;
      if (c == 'A') p[j%2][j/2] = 14;
      else if (c == 'K') p[j%2][j/2] = 13;
      else if (c == 'Q') p[j%2][j/2] = 12;
      else if (c == 'J') p[j%2][j/2] = 11;
      else if (c == 'T') p[j%2][j/2] = 10;
      else p[j%2][j/2] = (c - '0');
      cout << p[j%2][j/2] << " ";
    }
    cout << "\n";
    
    for (int j = 0; j < 12; j++) {
      stable_sort(h[j%2].begin(), h[j%2].end());
      int c0 = h[j%2][2];
      //      cout << "Player " << j%2 << " " << c0 << "\n";
      int val;
      if (c0 == 9) { val = 0; }
      else if (c0 == 10) { init -= 10; val = -10; }
      else if (c0 == 7) {
	if (init + 7 > 99) { init += 1; val = 1; }
	else { init += 7; val = 7; }
      } else {
	init += c0;
	val = c0;
      }
      
      if (init - val < 34 && init > 33) init += 5;
      if (init - val < 55 && init > 54) init += 5;
      if (init - val < 77 && init > 76) init += 5;

      cout << init << " " << val << "\t";
      for (int k = 0; k < 5; k++) cout << h[j%2][k] << " ";
      cout << "\n";
      
      h[j%2][2] = p[j%2][j/2];
      
      if (init > 99) {
	fout << init << " Player " << (j+1)%2 + 1 << "\n";
	break;
      }
    }
  }
  
}
