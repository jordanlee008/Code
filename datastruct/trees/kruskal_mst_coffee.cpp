#include <vector>
#include <iostream>

using namespace std;

int dad[vertices];
int wt[vertices];

void join(int i, int j) {
  int i0 = i;
  while (i0 != dad[i0]) i0 = dad[i0];
  int j0 = j;
  while (j0 != dad[j0]) j0 = dad[j0];
  if (wt[i0] < wt[j0]) {
    dad[i0] = j0;
    wt[j0] += wt[i0];
  } else {
    dad[j] = i;
    wt[i] += wt[j];
  }
  
  while (i != i0) {
    t = dad[i];
    dad[i] = j0;
    i = t;
  }
  while (j != j0) {
    t = dad[j];
    dad[j] = i0;
    j = t;
  }
}

bool joined(int i, int j) {
  while (i != dad[i]) i = dad[i];
  while (j != dad[j]) j = dad[j];
  return i == j;
}
