#include <iostream>
#include <vector>

using namespace std;

vector<int> fib (2) ;

void calc (void) {
  int l = fib.size();
  fib.push_back(fib[l - 1] + fib[l - 2]);
}

int main (void) {
  long  int output;
  fib[0] = 1;
  fib[1] = 1;
  for (long int i = 0; i < 4000000 - 2; i++) {
    calc();
    if (fib[i + 2] % 2 == 0)
      output += fib[i + 2];
  }
  cout << output << endl;
}
