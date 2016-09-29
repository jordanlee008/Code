#include <iostream>
#include <fstream>

using namespace std;

int count(int a[], int n, int l) {
  int counter = 0;
  if (n > l)
    return 0;
  if (a[n] == 0)
    counter++;
  counter += count(a, n + 1, l);
  return counter;
}

int main () {
  cout << "How many elements?" << endl;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << count(a, 0, n) << endl;
}//end main
