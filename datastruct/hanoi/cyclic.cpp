#include <iostream>
#include <cstdio>

using namespace std;

void F(int n, int start);
void A(int n, int start);

int moves = 0;

void F(int n, int start) {
  if (!n) return;
  F(n - 1, start);
  printf("Disk %d to %d\n", n, (start + 1) % 3);
  moves++;
  A(n - 1, (start + 2) % 3);
  printf("Disk %d to %d\n", n, (start + 2) % 3);
  moves++;
  F(n - 1, start);
}

void A(int n, int start) {
  if (!n) return;
  F(n - 1, start);
  printf("Disk %d to %d\n", n, (start + 1) % 3);
  moves++;
  F(n - 1, (start + 2) % 3);
}

int main() {
  F(3, 0);
  printf("Moves: %d\n", moves);
}
