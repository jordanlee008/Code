#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int nboard = 8;

vector<int> findqueen(vector<int> qrows) {
  // Take in set of current queen row positions
  int nq = qrows.size();

  printf("findqueen called:\n");
  for (int iq = 0; iq < nq; iq++) {
    printf(" (%d,%d)", iq, qrows[iq]);
  }
  printf("\n");

  bool valid[nboard];
  for (int i = 0; i < nboard; i++) {
    valid[i] = true;
  }

  for (int iq = 0; iq < nq; iq++) {
    int row = qrows[iq];

    // Horizontal move:
    valid[row] = false;

    // Diagonal moves:
    int diag1 = row + (nq-iq);
    if ((diag1 >= 0) && (diag1 < nboard))
      valid[diag1] = false;

    int diag2 = row - (nq-iq);
    if ((diag2 >= 0) && (diag2 < nboard))
      valid[diag2] = false;    
  }
  
  // Return set of valid next queen positions
  vector<int> v;
  for (int i = 0; i < nboard; i++) {
    if (valid[i]) {
      v.push_back(i);
    }
  }
  return v;
}

void printqueens(vector<int> qrows) {
  int nq = qrows.size();
  for (int iq = 0; iq < nq; iq++) {
    for (int i = 0; i < qrows[iq]; i++) {
      printf(". ");
    }
    printf("Q ");
    for (int i = 0; i < nboard-qrows[iq]-1; i++) {
      printf(". ");
    }
    printf("\n");
  }
  for (int i = 0; i < nboard-nq; i++) {
    for (int j = 0; j < nboard; j++) printf(". ");
    printf("\n");
  }
}


int main() {
  vector< vector<int> > boards;

  vector<int> a;

  boards.push_back(a);
  while (boards.size() > 0) {
    vector<int> c0 = boards[boards.size()-1];
    boards.pop_back();
    if (c0.size() == nboard) {
      printf("Solution Found!\n");
      printqueens(c0);
    }

    vector<int> rows = findqueen(c0);
    for (int i = 0; i < rows.size(); i++) {
      vector<int> c1(c0);
      c1.push_back(rows[i]);
      boards.push_back(c1);
    }
  }

  return 0;
}
