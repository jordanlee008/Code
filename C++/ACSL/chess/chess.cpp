#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void make_board(int b[8][8]) {
  // -1 = I (queen), 0 = X (not safe), 1 = O (safe)
  cout << " ";
  for (int i = 0; i < 8; i++) cout << " " << i;
  cout << "\n";
  for (int y = 0; y < 8; y++) {
    cout << y << " ";
    for (int x = 0; x < 8; x++) {
      if (b[x][y] == 1) cout << "O";
      else if (b[x][y] == 0) cout << "X";
      else if (b[x][y] == -1) cout << "I";
      cout << " ";
    }
    cout << "\n";
  }
}

int safe(int v[2][2], int n) {
  // 0 = X, 1 = O
  // store board as matrix
  int b[8][8];
  for (int i = 0; i < 64; i++) b[i/8][i%8] = 1;

  // mark off closed spaces
  for (int i = 0; i < 2; i++) {
    int x = v[i][0], y = v[i][1];
    
    // up/down
    for (int j = -n; j <= n; j++) {
      if (-1 < y+j && y+j < 8) b[x][y+j] = 0;
    }
    
    // right/left
    for (int j = -n; j <= n; j++) {
      if (-1 < x+j && x+j < 8) b[x+j][y] = 0;
    }
    
    // diagonal up-left/right-down
    for (int j = -n; j <= n; j++) {
      if (-1 < x+j && x+j < 8 && -1 < y-j && y-j < 8) b[x+j][y-j] = 0;
    }
    
    // diagonal up-right/left-down
    for (int j = -n; j <= n; j++) {
      if (-1 < x+j && x+j < 8 && -1 < y+j && y+j < 8) b[x+j][y+j] = 0;
    }
  }
  
  // mark queens specially
  for (int i = 0; i < 2; i++) {
    b[v[i][0]][v[i][1]] = -1;
  }
  
  // print board
  make_board(b);
  cout << "\n\n\n";

  // count open spaces
  int count = 0;
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      if (b[x][y] == 1) count++;
  return count;
}

int main() { // JAVA: public static void main(String[] args) { }
  ifstream fin ("chess.in"); // BufferedReader
  ofstream fout ("chess.out"); // BufferedWriter
  
  // REPEAT ALGORITHM 5 TIMES
  for (int i = 0; i < 5; i++) {
    // get input
    int v[2][2] = {-1};
    int n;
    for (int j = 0; j < 2; j++) {
      fin >> v[j][0] >> v[j][1];
      v[j][0] -= 1;
      v[j][1] -= 1;
    }
    fin >> n;
    
    fout << safe(v, n) << "\n";
  }
}
