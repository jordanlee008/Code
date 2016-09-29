#include <vector>
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int reflect2 (int x) {
  return 4 - x;
}

int reflect7 (int x) {
  return 14 - x;
}

int main () {
  deque<int> deq (1, 0);
  deq.push_back(0);

  vector<int> check;
  for (int i = 0; i < 2001; i++)
    check.push_back(0);
  
  while (deq.size() != 0) {
    int a = deq[0];
    deq.pop_front();
    if (reflect2(a) <= 1000 && reflect2(a) >= -1000 && (check[reflect2(a) + 1000] == 0)) {
      deq.push_back(reflect2(a));
      check[reflect2(a) + 1000] = 1;
    }
    
    if (reflect7(a) <= 1000 && reflect7(a) >= -1000 && (check[reflect7(a) + 1000] == 0)) {
      deq.push_back(reflect7(a));
      check[reflect2(a) + 1000] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i < check.size(); i++)
    if (check[i]) {
      cout << i - 1000 << endl;
      count++;
    }
  cout << count << endl;
  
  return 0;
}
