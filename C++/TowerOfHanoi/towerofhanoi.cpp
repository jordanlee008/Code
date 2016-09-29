#include <cstdio>
#include <cstdlib>

using namespace std;

int nmoves = 0;

void movestack (int n, int istart, int iend) {
  if (n <= 0) {
    printf("No moves to make!\n");
    return;
  }
  if (n == 1) {
    printf("Move ring %d from %c to %c\n", n, istart + 64, iend + 64);
    nmoves++;   
    return;
  }

  int iother = 6 - (istart + iend);

  movestack (n - 1, istart, iother);
  printf("Move ring %d from %c to %c\n", n, istart + 64, iend + 64);
  nmoves++;
  movestack (n - 1, iother, iend);
}

int main(int argc, char **argv) {
  int n = 10;
  if (argc > 1) {
    n = atoi(argv[1]);
  }

  printf("Towers of Hanoi for %d rings:\n", n);
  movestack(n, 1, 2);
  printf("Number of moves: %d\n", nmoves);
}
