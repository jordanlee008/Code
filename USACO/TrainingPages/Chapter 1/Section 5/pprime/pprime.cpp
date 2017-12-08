/*
ID: jorlee
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> prime (1);
int lb, ub;

void primegen () {
  for (int i = 3; i*i <= ub; i+=2) {
    bool isp = true;
    for (int j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++) {
      if (i % prime[j] == 0)
	isp = false;
	}
    if (isp) {
      prime.push_back(i);
      cout << i << endl;
    }
  }
}

bool primecheck (int n) {
  for (int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++)
    if (n % prime[i] == 0)
      return false;
  return true;
}

void palgen (void) {
  ofstream fout ("pprime.out");
  //generate single digit palindrome-primes
  for (int i = 1; i < 10; i++)
    if (primecheck(i) && i >= lb && i <= ub)
      fout << i << endl;
  //generate two digit palindrome - primes
  for (int d1 = 1; d1 < 10; d1+=2) {
      int p = 10 * d1 + d1;
      if (primecheck(p) && p >= lb && p <= ub)
	fout << p << endl;
  }
  //generate three digit palindrome-primes
  for (int d1 = 1; d1 < 10; d1+=2) {
    for (int d2 = 0; d2 < 10; d2++) {
      int p = 100*d1 + 10*d2 + d1;
      if (primecheck(p) && p >= lb && p <= ub)
	fout << p << endl;
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      int p = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
      if (primecheck(p) && p >= lb && p <= ub)
	fout << p << endl;
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
	int p = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
	if (primecheck(p) && p >= lb && p <= ub)
	  fout << p << endl;
      }
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
	int p = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
	if (primecheck(p) && p >= lb && p <= ub)
	  fout << p << endl;
      }
    }
  }
  for (int d1 = 1; d1 < 10; d1 += 2) {
    for (int d2 = 0; d2 < 10; d2++) {
      for (int d3 = 0; d3 < 10; d3++) {
	for (int d4 = 0; d4 < 10; d4++) {
	  int p = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
	  if (primecheck(p) && p >= lb && p <= ub)
	    fout << p << endl;
	}
      }
    }
  }
}

int main () {
  ifstream fin ("pprime.in");
  ofstream fout ("pprime.out");
  prime[0] = 2;
  fin >> lb >> ub;
  primegen();
  palgen();
}
