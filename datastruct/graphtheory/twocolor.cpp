#include "vertex.h"

bool two_colorable(Graph& g, int ind, int col) {
  // visit vertex, then visit neighbors
  g[ind].color = col;
  vector<int> visit;
  for (int i = 0; i < g[ind].nbrs.size(); i++) {
    if (g[g[ind].nbrs[i]].color == col) return false;
    if (g[g[ind].nbrs[i]].color == -1) visit.push_back(i);
  }
  for (int i = 0; i < visit.size(); i++) two_colorable(g, visit[i], !col);
  return true;
}
