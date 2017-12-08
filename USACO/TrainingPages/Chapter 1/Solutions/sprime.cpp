/*
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("sprime.out");

bool isprime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;

  if ((n % 2) == 0) return false;
  for (int i = 3; i*i <= n; i += 2) {
    if ((n % i) == 0) return false;
  }
  return true;
}

int numdigits(int n) {
  int nd = 0;
  while (n != 0) {
    nd++;
    n = n/10;
  }
  return nd;
}

int genp(int p, int ndigits) {
  if (!isprime(p)) return 0;

  int nd = numdigits(p);
  if (nd == ndigits) {
    fout << p << endl;
    return 1;
  }
  else {
    int np = 0;
    for (int i = 1; i <= 9; i+=2) {
      int p1 = 10*p + i;
      np += genp(p1, ndigits);
    }
    return np;
  }
}

int main() {
  //  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");

  int n;
  fin >> n;

  vector<int> v(1);
  for (int i = 1; i <= 9; i++) {
    genp(i, n);
  }

  return 0;
}
