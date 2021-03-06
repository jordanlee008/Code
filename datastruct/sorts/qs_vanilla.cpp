#include <vector>
#include <iostream>

using namespace std;

int qs_vanilla_partition(int a[], int lo, int hi) {
  int x = a[lo]; // partition element
  while (lo <= hi) {
    while (a[lo] < x) lo++;
    while (a[hi] > x) hi--;
    if (lo <= hi) swap(a[lo++], a[hi--]);
  }
  return lo;
}

void qs_vanilla(int a[], int lo, int hi) {
  if (lo < hi) {
    int m = qs_vanilla_partition(a, lo, hi);
    qs_vanilla(a, lo, m - 1);
    qs_vanilla(a, m, hi);
  }
}

int main() {
  int a[] = {7, 8, 7, 6, 0, 2, 3, 1, 4, 5, 3, 3, 3, 3, 3, 3, 3, 3};
  qs_vanilla(a, 0, 17);
  for (int i = 0; i < 18; i++) printf("a[%d]: %d\n", i, a[i]);
}
