#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

//typedef pair<int,int> pi;

int main() {
  ifstream fin ("greedy.in");
  ofstream fout ("greedy.out");

  int N;
  fin >> N;

  vector<int> c(N,0);
  for (int i = 0; i < N; i++) { fin >> c[i]; }
  
  deque<int> q;
  for (int i = 0; i < N; i++) { q.push_back(i); }
  
  vector<int> e(N,-1);
  vector<int> n(N,-1);
  vector<int> p(N,-1);
  int tot = N;
  bool loop = false;
  while (!loop) {
    int q0 = q[0];
    q.pop_front();
    q.insert(q.end()-c[q0], q0);
    if (e[q0] == -1) {
      tot--;
      n[q0] = q[0];
      e[q0] = e[
    }
    else n[q0] = make_pair(q[0],1);
    
    if (tot == 0) loop = true;
    
    int q1 = q0;
    while (n[q1].second > 1) {
      q1 = n[q1].first;
      if (q1 == q0) {
	loop = true;
	break;
      }
    }
  }
  
  fout << tot << "\n";
}
