#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ULL unsigned long long

int N;

vector<int> fill(ULL b, int k) {
  priority_queue<ULL> q;
  q.push(b);
  for (int i = 0; i < k - 1; i++) {
    ULL t = q.top();
    q.pop();
    q.push(((t-1)/2) + ((t-1) % 2));
    q.push((t-1)/2);
  }
  ULL t = q.top();
  q.pop();
  vector<int> v;
  v.push_back(((t-1)/2) + ((t-1) % 2));
  v.push_back((t-1)/2);
  return v;
}

int main() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    ULL b;
    int k;
    cin >> b >> k;
    vector<int> v = fill(b, k);
    printf("Case #%d: ", i + 1);
    cout << v[0] << " " << v[1] << "\n";
  }
}
