#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
  int pre, pos;
  int color;
  vector<int> nbrs;
};

typedef vector<Vertex> Graph;
