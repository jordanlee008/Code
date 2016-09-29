#include <iostream>
#include <fstream>

using namespace std;

int add (int n) {
  if (n == 0)
    return 0;
  int sum = 0;
  sum += n + add(n-1);
  return sum;
}//end sum

int main () {
  int n;
  cin >> n;
  cout << add(n) << endl;
}//end main
