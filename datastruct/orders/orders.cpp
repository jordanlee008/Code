#include <iostream>
#include <vector>

using namespace std;

#define VI vector<int>

vector<VI> nodes; // adjacencies
vector<VI> prepost; // pre/min pre of child for each vertex
VI cnodes; // cut points
VI cols; // color of each vertex
int col = 0;
int pre = 1;

bool findcuts(int n) {
  if (prepost[n][0] != -1) return false;
  printf("findcuts(%d), %d\n", n, pre);
  prepost[n][0] = pre;
  pre++;
  
  int descendants = 0;
  int minpre = prepost[n][0];
  for (int i = 0; i < nodes[n].size(); i++) {
    if (findcuts(nodes[n][i])) {
      descendants++;
      if (prepost[nodes[n][i]][1] < minpre) minpre = prepost[nodes[n][i]][1];
      if ((n != 0) && (prepost[nodes[n][i]][1] >= prepost[n][0])) cnodes[n] = 1;
    }
    if (prepost[nodes[n][i]][0] < minpre) minpre = prepost[nodes[n][i]][0];
  }
  
  if ((descendants > 1) && (n == 0)) {
    //    cout << "descendants: " << descendants << "\n";
    cnodes[n] = 1;
  }
  prepost[n][1] = minpre;
  return true;
}

int color(int n) {
  if (cols[n] != -1) return 0;
  cols[n] = col;
  int cut = 0;
  for (int i = 0; i < nodes[n].size(); i++) {
    if (cnodes[nodes[n][i]] && cols[nodes[n][i]] != col) {
      cut++;
      cols[nodes[n][i]] = col;
    }
    else if (!cnodes[nodes[n][i]]) cut += color(nodes[n][i]);
  }
  return cut;
}

int transporters(int n, VI& tubes) {
  // input data
  cnodes.clear();
  nodes.clear();
  cols.clear();
  prepost.clear();
  col = 0;
  pre = 1;
  VI e;
  VI pp;
  pp.push_back(-1);
  pp.push_back(-1);
  for (int i = 0; i < n; i++) {
    cnodes.push_back(0);
    nodes.push_back(e);
    cols.push_back(-1);
    prepost.push_back(pp);
  }
  for (int i = 0; i < tubes.size(); i+=2) {
    nodes[tubes[i]].push_back(tubes[i+1]);
    nodes[tubes[i+1]].push_back(tubes[i]);
  }
  
  // depth first search to find cut points
  findcuts(0);

  // depth first search to color points
  for (int i = 0; i < n; i++) {
    if ((!cnodes[i]) && (cols[i] == -1)) {
      int coli = color(i);
      printf("color(%d) = %d\n", i, coli);
      if (coli < 2) {
	printf("color(%d) < 2\n", i);
	col++;
      }
    }
  }
  if (col == 1) return 2;
  return col;
}

/*int main() {
  VI tubes;
  int v;
  int max = 0;
  cin >> v;
  for (int i = 0; i < v; i++) {
    int e1, e2;
    cin >> e1 >> e2;
    if (e1 > max) max = e1;
    if (e2 > max) max = e2;
    tubes.push_back(e1);
    tubes.push_back(e2);
  }

  int n = max + 1;
  printf("n: %d\n", n);
  cout << transporters(n, tubes) << "\n";
  for (int i = 0; i < n; i++) {
    cout << i << ": ";
    for (int j = 0; j < nodes[i].size(); j++) {
      cout << nodes[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "cut: ";
  for (int i = 0; i < n; i++)
    if (cnodes[i]) cout << i << " ";
  cout << "\n"; 
  }*/
