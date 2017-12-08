/*
ID: jorlee
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int r, c;
vector< vector<int> > input;
//input[r][c]

int exp (int e, int b) {
  int a = 1;
  for (int i = 0; i < e; i++)
    a = a * b;
  return a;
}

vector<bool> walls (int n) {
  vector<bool> a (4);
  for (int i = 3; i >= 0; i--) {
    //    cout << "counting 2^" << i << endl;
    //    cout << "exp(" << i << ",2) = " << exp(i,2) << endl;
    if (n >= exp(i,2)) {
      n = n % exp(i, 2);
      cout << "n = " << n << endl;
      a[i] = true;
      cout << "a[" << i << "]: 1" << endl;;
    }
    else {
      a[i] = false;
      cout << "a[" << i << "]: 0" << endl;;
    }
  }
  return a;
}

int main (void) {
  ifstream fin ("castle.in");
  ofstream fout ("castle.out");
  fin >> c >> r;
  for (int i = 0; i < c; i++) {
    vector<int> a (r);
    input.push_back(a);
  }
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      fin >> input[i][j];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
  
  vector<bool> a(walls(11));
  for (int i = 3; i >= 0; i--) {
    cout << "outputting 2^" << i << ": ";
    if (a[i])
      cout << "1" << endl;
    else
      cout << "0" << endl;
  }
  return 0;
}
