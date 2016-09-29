#include <iostream>
#include <fstream>

using namespace std;

int fac (int n) {
  if (n == 1)
    return 1;
  int answer = n * fac(n-1);
  return answer;
}

int main () {
  int n;
  cin >> n;
  cout << fac(n) << endl;
}
