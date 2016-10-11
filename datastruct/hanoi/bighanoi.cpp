#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<long> VL;

// indices not shifted
vector<VL> n_hanoi; // n_hanoi[twr][dsks] = # of moves
vector<VI> k_hanoi; // k_hanoi[twr][dsks] = # of towers in first move

// initialize n_hanoi and k_hanoi
void hanoi_init() {
  VL n(10001, 0);
  VI k(10001, 0);
  for (int i = 0; i < 11; i++) {
    n_hanoi.push_back(n);
    k_hanoi.push_back(k);
  }
}

// fill moves so that each element is a two-integer VI describing the move
// (starttwr, endtwr)
void hanoi(vector<VI>& moves, int n_twrs, int n_dsks, VI& aux) {
  
}

int main () {
  
  return 0;
}
