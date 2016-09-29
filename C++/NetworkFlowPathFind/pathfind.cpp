#include <vector>
#include <fstream>

using namespace std;


vector<int> findpath(vector< vector<int> > adj, int n, int m) {
  vector< vector<int> > list;
  vector<int> firstpath;
  firstpath.push_back(m);
  list.push_back(firstpath);

  while (list.size() != 0) {
    vector<int> path = list[0];
    list.erase(list.begin());
    if (path[path.size() - 1] == n) return path;
    for (int i = 0; i < adj[path.size() - 1].size(); i++) {
      bool match = false;
      for (int j = 0; j < path.size(); j++) {
	if (path[j] == adj[path.size() - 1][i])  {
	  match = true;
	}
      }
      if (!match) {
	vector<int> newpath = path;
	newpath.push_back(adj[path.size() - 1][i]);
	list.push_back(newpath);
      }
    }
  }
  vector<int> empty;
  return empty;
}

int main() {
  ifstream fin ("pathfind.in");
  ofstream fout ("pathfind.out");
  
  vector< vector<int> > adj; //adj[i] is a vector of all vertices adj to i
  int n, m;  //m is starting point, n is ending point
  int v; //number of vertices in graph
  
  fin >> v >> m >> n;
  for (int i = 0; i < v; i++) {
    int vn;
    fin >> vn;
    vector<int> vadj;
    for (int j = 0; j < vn; j++) {
      int k;
      fin >> k;
      vadj.push_back(k);
    }
    adj.push_back(vadj);
  }
  
  vector<int> path = findpath(adj, n, m);
  for (int i = 0; i < path.size(); i++)
    fout << path[i] << " ";
}
