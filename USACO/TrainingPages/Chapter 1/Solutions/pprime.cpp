/*
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("pprime.out");
int a, b;

bool isprime(int n) {
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

int genpal(vector<int> v, int ndigits) {
  int nv = v.size();

  if (2*nv >= ndigits) {
    // Generate palindrome number:
    int p = 0;
    for (int i = 0; 2*i < ndigits; i++) {
      p = 10*p + v[i];
    }
    for (int i = ndigits/2-1; i >= 0; i--) {
      p = 10*p + v[i];
    }
//    cout << p << endl;
    if ((p >= a) && (p <= b) && (isprime(p))) {
      fout << p << endl;
    }
    return 1;
  }
  else {
    int npal = 0;
    for (int i = 0; i <= 9; i++) {
      vector<int> v1(v);
      v1.push_back(i);
      npal += genpal(v1, ndigits);
    }
    return npal;
  }
}

int main() {
//  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");

//  int a, b;
  fin >> a >> b;

  int na = numdigits(a);
  int nb = numdigits(b);

  vector<int> v(1);
  for (int nd = na; nd <= nb; nd++) {
    for (int i = 1; i <= 9; i+=2) {
      v[0] = i;
      genpal(v, nd);
     }
  }

  return 0;
}


/*
// Filtering for palindromes is also too slow:

bool ispal(int n) {
  vector<int> v;
  while (n != 0) {
    v.push_back( n % 10 );
    n = n / 10;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != v[v.size()-1-i]) return false;
  }
  return true;
}

int main() {
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");

  int a, b;
  fin >> a >> b;

  if ((a % 2) == 0) a++;
  for (int n = a; n <= b; n+=2) {
    if (ispal(n)) {
      if (isprime(n)) {
	fout << n << endl;
      }
    }
  }

  return 0;
}
*/

/*
// Generating primes is too slow!
// Need to generate palindromes instead, and check for primeness

bool ispalindrome(int p) {
  vector<int> v;
  while (p != 0) {
    v.push_back(p % 10);
    p = p / 10;
  }
  bool pal = true;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != v[v.size()-1-i]) {
      pal = false;
      break;
    }
  }
  return pal;
}

int main() {
  ofstream fout ("pprime.out");
  ifstream fin ("pprime.in");

  int a, b;
  fin >> a >> b;

  // Initialize vector of primes:
  vector<int> primes;
  primes.push_back(2);
  primes.push_back(3);

  for (int n = 5; n <= b; n+=2) {
    bool isprime = true;
    for (int j = 0; j < primes.size(); j++) {
      // Check for divisibility with primes < sqrt(n)
      if (n < primes[j]*primes[j]) break;
      if ((n % primes[j]) == 0) {
	isprime = false;
	break;
      }
    }

    if (isprime) {
      cout << n << endl;
      primes.push_back(n);
      if (n >= a) {
	if (ispalindrome(n)) {
	  fout << n << endl;
	}
      }
    }
  }

    return 0;
}
*/
