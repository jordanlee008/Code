#include <vector>
#include <iostream>

using namespace std;

const int TH = 3;

void insertion_sort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      swap(a[j], a[j - 1]);
      j--;
    }
  }
}

int median_of_3(int a[], int lo, int hi) {
  int mid = (lo + hi) / 2;
  //  printf("hi: %d, mid: %d, lo: %d\n", hi, mid, lo);
  if ((a[lo] <= a[mid] && a[mid] <= a[hi]) || (a[lo] >= a[mid] && a[mid] >= a[hi]))
    return a[mid];
  if ((a[mid] <= a[lo] && a[lo] <= a[hi]) || (a[mid] >= a[lo] && a[lo] >= a[hi]))
    return a[lo];
  return a[hi];
}

int qs_choco_partition(int a[], int lo, int hi) {
  //  printf("lo: %d, hi: %d\n", lo, hi);
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

int main() {
  int a[] = { 6, 4, 8, 7, 1, 3, 2, 5 };
  for (int i = 0; i < 8; i++) cout << a[i] << " ";
  cout << "\n";
  qs_choco_final(a, 8);
  for (int i = 0; i < 8; i++) cout << a[i] << " ";
  cout << "\n";
}
