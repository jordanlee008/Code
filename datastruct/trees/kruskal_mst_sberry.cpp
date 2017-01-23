#include <vector>
#include <iostream>

using namespace std;

int dad[vertices];
int wt[vertices];

void join(int i, int j) {
  while (i != dad[i]) i = dad[i];
  while (j != dad[j]) j = dad[j];
  if (wt[i] <= wt[j]) {
    dad[i] = j;
    wt[j] += wt[i];
  } else {
    dad[j] = i;
    wt[i] += wt[j];
  }
}

bool joined(int i, int j) {
  while (i != dad[i]) i = dad[i];
  while (j != dad[j]) j = dad[j];
  return i == j;
}
