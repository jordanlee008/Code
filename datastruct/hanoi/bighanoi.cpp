#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VI;
typedef vector<long> VL;

// indices not shifted
vector<VL> n_hanoi; // n_hanoi[twr][dsks] = # of moves
vector<VI> k_hanoi; // k_hanoi[twr][dsks] = # of disks in first

void calc_kn(int n_twrs, int n_dsks) {
  printf("calc_kn[%d][%d]\n", n_twrs, n_dsks);
  for (int i = 1; i < n_dsks; i++) {
    if (k_hanoi[n_twrs][i] == 0) calc_kn(n_twrs, i);
    if (k_hanoi[n_twrs - 1][n_dsks - i] == 0) calc_kn(n_twrs - 1, n_dsks - i);
    long n = n_hanoi[n_twrs][i] + n_hanoi[n_twrs][i] + n_hanoi[n_twrs - 1][n_dsks - i];
    if (n < n_hanoi[n_twrs][n_dsks]) {
      n_hanoi[n_twrs][n_dsks] = n;
      k_hanoi[n_twrs][n_dsks] = i;
    }
  }
}

// initialize n_hanoi and k_hanoi
void hanoi_init() {
  VL n(10001, pow(2, 62));
  VI k(10001, 0);
  for (int i = 0; i < 11; i++) {
    n_hanoi.push_back(n);
    k_hanoi.push_back(k);
  }
  for (int i = 1; i < 10000; i++) {
    k_hanoi[3][i] = i - 1;
  }
  for (int i = 0; i < 11; i++) {
    n_hanoi[i][1] = 1;
    k_hanoi[i][1] = 1;
  }
  for (int i = 2; i < 63; i++) {
    n_hanoi[3][i] = pow(2, i) - 1;
  }
  for (int i = 2; i < 1600; i++) {
    calc_kn(4, i);
  }
}

// fill moves so that each element is a two-integer VI describing the move
// (starttwr, endtwr)
void hanoi(vector<VI>& moves, int n_twrs, int n_dsks, VI& aux) {
  if (n_dsks == 1) {
    VI move;
    move.push_back(aux[0]);
    move.push_back(aux[1]);
    moves.push_back(move);
    return;
  }
  
  if (k_hanoi[n_twrs][n_dsks] > 0) {
    swap(aux[1], aux[n_twrs - 1]);
    hanoi(moves, n_twrs, k_hanoi[n_twrs][n_dsks], aux);
    
    swap(aux[1], aux[n_twrs - 1]);
    hanoi(moves, n_twrs - 1, n_dsks - k_hanoi[n_twrs][n_dsks], aux);
    
    swap(aux[0], aux[n_twrs - 1]);
    hanoi(moves, n_twrs, k_hanoi[n_twrs][n_dsks], aux);
  return;
  }
  
  calc_kn(n_twrs, n_dsks);
  hanoi(moves, n_twrs, n_dsks, aux);
}

int main () {
  hanoi_init();
  
  for (int i = 0; i < 1600; i++) printf("n_hanoi[%d][%d] = %ld\n", 4, i, n_hanoi[4][i]);

  VI aux;
  vector<VI> moves;
  
  int n_twrs = 5, n_dsks = 1000;
  for (int i = 0; i < n_twrs; i++) aux.push_back(i);
  hanoi(moves, n_twrs, n_dsks, aux);
  for (int i = 0; i < moves.size(); i++) printf("%d to %d\n", moves[i][0], moves[i][1]);
  printf("Number of moves: %lu\n", moves.size());
  
  return 0;
  }

