/*
This program is to demonstrate mastery of DFS by outputting all possible
combinations of boards with 8 queens in which no queen is attacked by another.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<bool> nqueen(vector<int> b) {
  vector<bool> place (8, true);
  int c = b.size();
  for (int i = 0; i < c; i++) {
    int q = b[i];
    place[q] = false;
    int dif = c - i;
    if (dif + q < 8)
      place[dif + q] = false;
    if (q - dif >= 0)
      place[q - dif] = false;
  }
	return place;
}

void printqueens(vector<int> q) {
  int nq = q.size();
  for (int i = 0; i < nq; i++) {
    for (int j = 0; j < q[i]; j++)
      cout << ". ";
    cout << "Q ";
    for (int j = 0; j < 8 - q[i] - 1; j++)
      cout << ". ";
    cout << endl;
  }
  for (int i = 0; i < 8 - nq; i++) {
    for (int j = 0; j < 8; j++) {
      cout << ". ";
    }
    cout << endl;
  }
}

int main (void) {
  deque< vector<int> > boards;
  vector<int> a;
  int ncalls = 0;

  boards.push_back(a);
  while (boards.size() > 0) {
    //    vector<int> c0 = boards[boards.size() - 1];
    vector<int> c0 = boards.back();
    boards.pop_back();
    if (c0.size() == 8) {
      cout << "Solution found at " << ncalls << ": " << endl;
      printqueens(c0);
    }
    
    vector<bool> rows = nqueen(c0);
    ncalls++;
    for (int i = 0; i < 8; i++)
      if (rows[i]) {
	vector<int> c1(c0);
	c1.push_back(i);
	boards.push_back(c1);
      }
  }
  return 0;
}
