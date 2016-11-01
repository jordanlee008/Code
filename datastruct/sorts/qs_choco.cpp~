#include <vector>
#include <iostream>

using namespace std;

const int TH = 20;

int median_of_3(int a[], int lo, int hi) {
  int mid = a[(lo + hi) / 2];
  if ((a[lo] <= a[mid] && a[mid] <= a[hi]) || (a[lo] >= a[mid] && a[mid] >= a[hi]))
    return mid;
  if ((a[mid] <= a[lo] && a[lo] <= a[hi]) || (a[mid] >= a[lo] && a[lo] >= a[hi]))
    return lo;
  return hi;
}

int qs_choco_partition(int a[], int lo, int hi) {
  int x = median_of_3(a, lo, hi); // partition element
  while (hi - lo > TH) {
    while (a[lo] < x) lo++;
    while (a[hi] > x) hi--;
    if (lo <= hi) swap(a[lo++], a[hi--]);
  }
  return lo;
}

void qs_choco(int a[], int lo, int hi) {
  while (lo < hi) {
    int m = qs_choco_partition(a, lo, hi);
    if (m - lo < hi - m + 1) {
      qs_choco(a, lo, m - 1);
      lo = m;
    } else {
      qs_choco(a, m, hi);
      hi = m - 1;
    }
  }
}

void qs_choco_final(int a[], int n) {
  qs_choco(a, 0, n - 1);
  insertion_sort(a, n);
}
