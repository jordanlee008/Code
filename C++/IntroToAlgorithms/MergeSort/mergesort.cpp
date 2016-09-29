#include <iostream>
#include <math.h>

using namespace std;

void merge (int A[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = A[q + j + 1];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  int i = 0, j = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }//end for
}//end merge

int mergesort (int A[], int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    merge(A, p, q, r);
  }//end if
}//end mergesort

int main () {
  const int n = 10;
  int array[n] = {4, 3, 2, 1, 8, 9, 10, 5, 7, 6};
  mergesort(array, 0, n-1);
  for (int i = 0; i < n; i++)
    cout << array[i] << " ";
}//end main
