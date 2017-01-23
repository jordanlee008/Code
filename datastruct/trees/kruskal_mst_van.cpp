#include <vector>
#include <iostream>

using namespace std;

int dad[vertices];

void join(int i, int j) {
  while (i != dad[i]) i = dad[i];
  while (j != dad[j]) j = dad[j];
  dad[i] = j;
}

bool joined(int i, int j) {
  while (i != dad[i]) i = dad[i];
  while (j != dad[j]) j = dad[j];
  return i == j;
}
