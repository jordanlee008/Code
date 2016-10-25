#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef vector<int> VI;
typedef vector<long> VL;

// indices not shifted
vector<VL> n_hanoi; // n_hanoi[twr][dsks] = # of moves
vector<VI> k_hanoi; // k_hanoi[twr][dsks] = # of disks in first move

// initialize n_hanoi and k_hanoi
void hanoi_init() {
  VL n(10001, 0);
  VI k(10001, 0);
  for (int i = 0; i < 11; i++) {
    n_hanoi.push_back(n);
    k_hanoi.push_back(k);
  }
  for (int i = 0; i < 11; i++) {
    n_hanoi[i][1] = 1;
  }
  for (int i = 2; i < 10000; i++) {
    n_hanoi[3][i] = 2 * (n_hanoi[3][i - 1] + 1) - 1;
    k_hanoi[3][i] = i - 1;
  }
  for (int i = 2; i < 10000; i++) {
    long min = 2147483647;
    int mink = 1;
    for (int j = 1; j < i; j++) {
      long n = 2 * n_hanoi[4][j] + n_hanoi[3][i - j];
      if (n < min) {
	mink = j;
	min = n;
      }
    }
    k_hanoi[4][i] = mink;
    n_hanoi[4][i] = min;
  }
  for (int i = 5; i <= 10; i++) {
    for (int j = 2; j <= 10000; j++) {
    long min = 2147483647;
    int mink = 1;
    for (int k = 1; k < i; k++) {
      long n = 2 * n_hanoi[i][k] + n_hanoi[i - 1][j - k];
      if (n < min) {
	mink = j;
	min = n;
      }
    }
    k_hanoi[i][j] = mink;
    n_hanoi[i][j] = min;
    }
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
 
  VI naux = aux;
  swap(naux[1], naux[n_twrs - 1]);
  hanoi(moves, n_twrs, k_hanoi[n_twrs][n_dsks], naux);
  
  swap(naux[1], naux[n_twrs - 1]);
  hanoi(moves, n_twrs - 1, n_dsks - k_hanoi[n_twrs][n_dsks], naux);
  
  swap(naux[0], naux[n_twrs - 1]);
  hanoi(moves, n_twrs, k_hanoi[n_twrs][n_dsks], naux);
  
  /*  long min = 2147483647;
  int mink = 0;
  for (int k = 1; k < n_dsks; k++) {
    VI naux = aux;
    vector<VI> nmoves = moves;
    swap(naux[1], naux[n_twrs - 1]);
    hanoi(nmoves, n_twrs, k, naux);
    
    swap(naux[1], naux[n_twrs - 1]);
    hanoi(nmoves, n_twrs - 1, n_dsks - k, naux);
    
    swap(naux[0], naux[n_twrs - 1]);
    hanoi(nmoves, n_twrs, k, naux);
    
    if (nmoves.size() < min) {
      mink = k;
      min = nmoves.size();
    }
  }
  k_hanoi[n_twrs][n_dsks] = mink;
  n_hanoi[n_twrs][n_dsks] = min;
  hanoi(moves, n_twrs, n_dsks, aux); */
}

int main () {
  hanoi_init();
  vector<VI> moves;
  VI aux;
  for (int i = 0; i < 100; i++)
    printf("n_hanoi[%d][%d] = %d\n", 4, i, n_hanoi[4][i]);
  

  /*  int n_twrs = 6, n_dsks = 10;
  for (int i = 0; i < n_twrs; i++) aux.push_back(i);
  hanoi(moves, n_twrs, n_dsks, aux);
  for (int i = 0; i < moves.size(); i++) printf("%d to %d\n", moves[i][0], moves[i][1]);
  printf("Number of moves: %lu\n", moves.size()); */

  return 0;
  }

