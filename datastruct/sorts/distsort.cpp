#include <iostream>
#include <vector>

using namespace std;

// 0 <= a[i] < max
void dsort(vector<int>& a, int max) {
  vector<int> b(max, 0);
  for (int i = 0; i < a.size(); i++) b[a[i]]++;
  for (int i = 1; i < max; i++) b[i] += b[i - 1];
  int index = 0;
  for (int i = 0; i < a.size(); i++) {
    while (i > b[index]) index++;
    a[i] = b[index];
  }
}

int main() {
  
}
