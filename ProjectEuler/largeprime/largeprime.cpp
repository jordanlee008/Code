#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> prime (1);

void makeprime (void) {
  for (int i = 3; i < sqrt(600851475143); i++) {
    for (int j = 0; j < prime.size(); j++) {
      if (i % prime[j] != 0)
	goto notprime;
    }
    prime.push_back(i);
  notprime:
    cout << i  << " is not prime" << endl;
  }
}

int check (void) {
  int l = prime.size();
  for (int i = l - 1; i >= 0; i--)
    if (600851475143 % prime[l] == 0) {
      cout << prime[l] << endl;
      return 0;
    }
  return 1;
}

int main (void) {
  prime[0] = 2;
  makeprime();
  cout << check() << endl;
}
