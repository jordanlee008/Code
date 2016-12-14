#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
typedef vector<int> VI;

ULL qm[417][417] = {};
ULL q[417] = {};

ULL part_q(int n);

ULL part_qk(int n, int m) {
  if (n == 0 || n == 1) return 1;
  if (q[n] == 0) part_q(n);
  if (m >= n) return q[n];
  ULL t = 0;
  for (int i = 1; i <= m; i++) t += qm[n][i];
  return t;
}

// return how many partitions n has
ULL part_q(int n) {
  if (n == 0 || n == 1) return 1;
  if (q[n] != 0) return q[n];
  
  ULL t = 0;
  for (int i = 1; i <= n; i++) {
    qm[n][i] = part_qk(n - i, i);
    //    printf("qm[%d][%d] = %llu\n", n, i, qm[n][i]);
    t += qm[n][i];
  }
  q[n] = t;
  return t;
}

VI part_km(int n, int m, ULL k) {
  //  printf("part_km(%d,%d,%llu)\n", n, m, k);
  VI r;
  if (n == 0) return r;
  if (n == 1) {
    r.push_back(1);
    return r;
  }
  ULL c = 0;
  int i = m;
  while (c + qm[n][i] <= k) {
    c += qm[n][i];
    i--;
  }
  //  cout << "i " << i << "\n";
  //  cout << "c " << c << "\n";
  r.push_back(i);
  VI s = part_km(n - i, i, k - c);
  for (int i = 0; i < s.size(); i++) r.push_back(s[i]);
  return r;  
}

// return kth partition of n
VI part_k(int n, ULL k) {
  return part_km(n, n, k);
}

// p - vector
// i - index
// m - max
// s - sum
// r - rest
ULL part_im(const VI& p, int i, int m, ULL s, ULL r) {
  ULL t = 0;
  int j = m;
  while (t + qm[r][
}

// return index of part p (guaranteed p is valid part)
ULL part_i(const VI& p) {
  int m = 0;
  for (int i = 0; i < p.size(); p++) m += p[i];
  return part_im(p, 0, m, 0);
}

int main() {
  for (int i = 0; i < 417; i++) printf("%d\t%llu\n", i, part_q(i));
  for (int i = 0; i < part_q(7); i++) {
    VI r = part_k(7, i);
    for (int j = 0; j < r.size(); j++) cout << r[j] << " ";
    cout << "\n";
  }
  return 0;
}
