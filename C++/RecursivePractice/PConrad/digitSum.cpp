#include <iostream>
#include <fstream>

using namespace std;

int digit(int n) {
  if (n < 0)
    n = n * (-1);
  if (n < 10)
    return n;
  int r = n % 10;
  n = n / 10;
  return r + digit(n);
}//end digit

int main () {
  int n;
  cin >> n;
  cout << digit(n) << endl;
}//end main
