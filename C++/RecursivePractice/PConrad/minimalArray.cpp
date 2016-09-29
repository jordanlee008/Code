#include <iostream>
#include <fstream>

using namespace std;

int low (int a[], int n, int l) { //l is number of elements n is index to check
  if (n >= l)
    return 1E9;
  if (a[n] < low(a, n + 1, l))
    return a[n];
  return low(a, n + 1, l);
}

int main () {
  cout << "Number of elements?" << endl;
  int l;
  cin >> l;
  int a[l];
  for (int i = 0; i < l; i++)
    cin >> a[i];
  cout << low(a, 0, l) << endl;
}
