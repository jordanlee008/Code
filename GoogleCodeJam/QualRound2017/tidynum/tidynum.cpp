#include <iostream>
#include <vector>

using namespace std;
#define ULL unsigned long long

int N;

vector<int> itoa(ULL k) {
  vector<int> v;
  while (k) {
    v.push_back(k % 10);
    k /= 10;
  }
  return v;
} // v[i] = coefficient of 10^i

vector<int> tidy(ULL k) {
  vector<int> kv = itoa(k);
  for (int n = 0; n < kv.size(); n++) {
    int i = kv.size() - 1;
    while (kv[i] <= kv[i - 1] && i > 0) i--;
    if (i == 0) break;
    kv[i]--;
    for (int j = i - 1; j >= 0; j--) kv[j] = 9;
  }
  return kv;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    ULL k;
    cin >> k;
    printf("Case #%d: ", i + 1);
    vector<int> t = tidy(k);
    for (int i = t.size() - 1; i >= 0; i--)
      if (t[i]) cout << t[i];
    cout << "\n";
  }
}
