#include <iostream>
#include <vector>
#include <mach/mach_time.h>

using namespace std;

vector<int> q;
int n, ct;

double time() { return 1E-9*mach_absolute_time(); }

bool safe(int r, int c) {
  for (int i = 0; i < r; i++) if (q[i] == c) return false;
  for (int i = 0; i < r; i++) if (q[i] - c == i - r) return false;
  for (int i = 0; i < r; i++) if (q[i] - c == r - i) return false;
  return true;
}

void squeens(int r) {
  //  printf("squeens(%d)\n", r);
  if (r == n) {
    ct++;
    return;
  }
  for (int c = 0; c < n; c++) {
    if (safe(r,c)) {
      q[r] = c;
      squeens(r + 1);
    }
  }
}

int main() {
  for (n = 8; n < 16; n++) {
    q.resize(n);
    ct = 0;
    double start = time();
    squeens(0);
    double end = time();
    printf("squeens(%d):%d\n", n, ct);
    printf("time: %f\n", end - start);
  }
  return 0;
}
