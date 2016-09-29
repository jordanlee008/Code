#include <iostream>
#include <cstdio>

using namespace std;

int moves = 0;

void hanoi(int n, int s, int e) {
  if (n == 1) {
    printf("Move ring %d from %c to %c\n", n, s + 64, e + 64);
    moves++;
    return;
  }

  hanoi(n - 1, s, 6 - (s + e));
  printf("Move ring %d from %c to %c\n", n, s + 64, e + 64);
  moves++;
  hanoi(n - 1, 6 - (s + e), e);
}

int main() {
  cout << "How many rings?\n";
  int n;
  cin >> n;
  hanoi(n, 1, 2);
  cout << "Number of moves: " << moves << endl;
}
