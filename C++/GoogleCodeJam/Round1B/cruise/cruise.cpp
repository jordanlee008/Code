#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int D, N;
    cin >> D >> N;
    double time = 0;
    for (int j = 0; j < N; j++) {
      int d0, s0;
      cin >> d0 >> s0;
      double time0 = (double) (D - d0) / s0;
      //      cout << time0 << "\n";
      if (time0 > time) time = time0;
    }
    double s = D / time;
    printf("Case #%d: %.6f\n", i + 1, s);
  }
}
