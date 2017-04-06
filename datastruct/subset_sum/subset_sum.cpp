#include <iostream>
#include <vector>

using namespace std;

// O(sum * n)
bool subset_sum(const vector<int>& s, int sum) {
  vector<int> a(sum + 1, 0);
  a[0] = true;
  for (int i = 0; i < s.size(); i++) {
    int x = s[i];
    for (int j = sum-x; j >= 0; j--)
      if (a[j]) a[j + x] = true;
    if (a[sum]) return true;
  }
  return false;
}

int main() {
  vector<int> s;
  for (int i = 1; i < 10; i++) s.push_back(i);
  cout << subset_sum(s, 45) << "\n";
}
