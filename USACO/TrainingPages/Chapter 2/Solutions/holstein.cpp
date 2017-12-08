/*
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <bitset>

using namespace std;

const int vmax = 25;
const int gmax = 15;

int v, g;
int vreq[vmax] = { };
int feed[gmax][vmax] = { };

// Breadth-first search:
int brsearch() {
  // Use bit representation of scoops to save memory:
  bool test[1 << (gmax+1)] = {false};
  deque<int> queue;
  queue.push_back(0);
  test[0] = true;

  int nq = 0;
  while (queue.size() > 0) {
    nq++;
    int x = queue.front();
    queue.pop_front();
    //    cout << "Queue: " << nq << " " << ((bitset<16>) x) << endl;

    bool valid = true;
    for (int iv = 0; iv < v; iv++) {
      int vsum = 0;
      for (int ig = 0; ig < g; ig++) {
	if (x & (0x01 << ig)) 
	  vsum += feed[ig][iv];
      }
      if (vsum < vreq[iv]) {
	valid = false;
      }
    }
    if (valid) {
      cout << "Sol: " << (bitset<16>) x << endl;
      return x;
    }
    else {
      // Push zero indices:
      for (int i = 0; i < g; i++) {
	int x1 = x | (0x01 << i);
	if (!test[x1]) {
	  queue.push_back(x1);
	  test[x1] = true;
	}
      }
    }
  }
}


int main() {
  ofstream fout ("holstein.out");
  ifstream fin ("holstein.in");

  fin >> v;
  for (int i = 0; i < v; i++) {
    fin >> vreq[i];
  }

  fin >> g;
  for (int i = 0; i < g; i++) {
    for (int j = 0; j < v; j++) {
      fin >> feed[i][j];
    }
  }

  int sol = brsearch();
  int ntot = 0;
  for (int i = 0; i < g; i++) {
    if (sol & (0x01 << i)) ntot++;
  }
  fout << ntot;
  for (int i = 0; i < g; i++) {
    if (sol & (0x01 << i)) {
      fout << " " << (i+1);
    }
  }
  fout << endl;

  return 0;
}


/*
// Sorting is only necessary if more than one scoop of each type can be given:
typedef pair<int, int> IntPair;
bool IntPairComp(const IntPair &l, const IntPair &r) {
  return l.first < r.first;
}

vector<int> sort_index(vector<int> v) {
  int n = v.size();
  vector<IntPair> s(n);
  for (int i = 0; i < n; i++) {
    s[i].first = v[i];
    s[i].second = i;
  }
  sort(s.begin(), s.end(), IntPairComp);
  vector<int> index(n);
  for (int i = 0; i < n; i++) {
    index[i] = s[i].second;
  }
  return index;
}
*/
