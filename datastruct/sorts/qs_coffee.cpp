#include <vector>
#include <iostream>

using namespace std;

int median_of_3(int a[], int lo, int hi) {
  int mid = a[(lo + hi) / 2];
  if ((a[lo] <= a[mid] && a[mid] <= a[hi]) || (a[lo] >= a[mid] && a[mid] >= a[hi]))
    return mid;
  if ((a[mid] <= a[lo] && a[lo] <= a[hi]) || (a[mid] >= a[lo] && a[lo] >= a[hi]))
    return lo;
  return hi;
}

int qs_coffee_partition(int a[], int lo, int hi) {
  int x = median_of_3(a, lo, hi); // returns the median of lo, hi, (lo+hi)/2
  while (lo <= hi) {
    while (a[lo] < x) lo++;
    while (a[hi] > x) hi--;
    if (lo <= hi) swap(a[lo++], a[hi--]);
  }
  return lo;
}

void qs_coffee(int a[], int lo, int hi) {
  while (lo < hi) {
    int m = qs_coffee_partition(a, lo, hi);
    if (m - lo < hi - m + 1) {
      qs_coffee(a, lo, m - 1);
      lo = m;
    } else {
      qs_coffee(a, m, hi);
      hi = m - 1;
    }
  }
}
