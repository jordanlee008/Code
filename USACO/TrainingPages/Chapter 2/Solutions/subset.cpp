/*
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int nmax = 39;

/*
// Generate all possible combinations: too slow!
int sums(int val, vector<bool> a) {
  int count = 0;
  if (val == 0) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i]) {
	cout << i+1 << " ";
      }
    }
    cout << a.size()+1 << endl;
    return 1;
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i]) {
      break;
    }
    else {
      int v2 = val - (i+1);
      if (v2 >= 0) {
	vector<bool> b(a);
	b[i] = true;
	count += sums(v2, b);
      }
    }
  }
  return count;
}
*/

int main() {
  ofstream fout ("subset.out");
  ifstream fin ("subset.in");

  int n;
  fin >> n;

  int nsum = n*(n+1)/2;
  if (nsum % 2 != 0) {
    fout << 0 << endl;
    return 0;
  }

  vector<unsigned int> sums(nsum+1, 0);

  sums[0] = 1;
  for (int n1 = 1; n1 <= n; n1++) {
    int n1sum = n1*(n1+1)/2;
    vector<unsigned int> temp(sums);
    for (int i = 0; i <= n1sum; i++) {
      sums[i+n1] += temp[i];
    }
  }

  for (int i = 0; i <= nsum; i++) {
    cout << i << " " << sums[i] << endl;
  }
  
  // Subset sum counts is double number of partitions:
  fout << sums[nsum/2]/2 << endl;
  
  return 0;
}
