#include <vector>
#include <iostream>

using namespace std;

int qs_strawberry_partition(int a[], int lo, int hi) {
  int x = a[lo]; // partition element
  while (lo <= hi) {
    while (a[lo] < x) lo++;
    while (a[hi] > x) hi--;
    if (lo <= hi) swap(a[lo++], a[hi--]);
  }
  return lo;
}

void qs_strawberry(int a[], int lo, int hi) {
  while (lo < hi) {
    int m = qs_strawberry_partition(a, lo, hi);
    if (m - lo < hi - m + 1) {
      qs_strawberry(a, lo, m - 1);
      lo = m;
    } else {
      qs_strawberry(a, m, hi);
      hi = m - 1;
    }
  }
}
