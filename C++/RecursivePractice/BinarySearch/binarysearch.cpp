#include <iostream>
#include <algorithm>

using namespace std;

int search (int a[], int l, int r, int x) {
  if (l > r)
    return -1;
  int mid = (l + r) / 2;
  if (a[mid] == x)
    return mid;
  else if (a[mid] < x)
    return search(a, mid + 1, r, x);
  else
    return search(a, l, mid - 1, x);
}

int main () {
  cout << "How many elements?" << endl;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << "What number do you want to find?" << endl;
  int x;
  cin >> x;
  sort(a, a + n);
  cout << "Your number is the " << search(a, 0, n - 1, x) + 1 << " smallest number" << endl;
}
