#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
  Vertex(int color = -1);
  int pre, pos;
  int color;
  vector<int> nbrs;
};

typedef vector<Vertex> Graph;
