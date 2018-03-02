#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

/*struct bn {
  int d = 0;
  bn(){};
  };*/

/*long int dist(long int s) {
  long int max = 0;
  vector<long int> seen(b.size(),0);
  deque<bn*> q;
  b[s]->d = 0;
  q.push_back(b[s]);
  while (!q.empty()) {
    bn* b0 = q.front();
    q.pop_front();
    if (seen[b0->id]) continue;
    seen[b0->id] = 1;
    if (b0->d > max) max = b0->d;
    for (long int i = 0; i < b0->con.size(); i++) {
      b0->con[i]->d = (b0->d)+1;
      q.push_back(b0->con[i]);
    }
  }
  return max;
}*/

int main() {
  ifstream fin ("newbarn.in");
  ofstream fout ("newbarn.out");
  
  int q;
  fin >> q;

  vector<int> b;
  vector< vector<int> > dis;
  vector<int> v;
  
  for (int i = 0; i < q; i++) {
    char c;
    int x;
    fin >> c >> x;
    if (c == 'B') {
      b.push_back(0);
      int e = b.size()-1;
      dis.push_back(v);
      if (x != -1) {
	  for (int j = 0; j < e; j++) {
	    if (dis[j][x-1] || j==x-1) dis[j].push_back(dis[j][x-1]+1);
	    else dis[j].push_back(0);
	    // b[j]->dis.push_back(b[j]->dis[x-1]+1);
	    b[j] = max(b[j],dis[j][e]);
	    dis[e].push_back(dis[j][e]);
	    // b[e]->dis.push_back(b[j]->dis[e]);
	    b[e] = max(b[e],dis[e][j]);
	}
	dis[e].push_back(0);
      } else {
	for (int j = 0; j < e; j++) {
	  dis[j].push_back(0);
	  dis[e].push_back(0);
	}
	dis[e].push_back(0);
      }
      
    } else if (c == 'Q') {
      fout << b[x-1] << "\n";
    } else {
      cerr << "what.\n";
    }
  }

  for (int i = 0; i < dis.size(); i++) {
    for (int j = 0; j < dis[i].size(); j++) {
      cout << dis[i][j] << " ";
    }
    cout << "\n";
  }
  
}
