#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

template<class T>
Node<T>* reconstruct(const vector<T>& in, const vector<T>& pre, int i0, int p0, int n) {
  if (n == 0) return 0;
  Node<T> n0 (pre[p0]);
  Node<T>* p = &n0;
  if (n == 1) return p;

  int leftp0;
  for (int i = 0; i < in.size(); i++) {
    T n1 = in[i];
    if (n1 == pre[p0 + 1])
      leftp0 = i;
  }

  int rightp0;
  for (int i = 0; i < in.size(); i++) {
    T n1 = in[i];
    if (n1 == pre[p0 + i0 + 1])
      rightp0 = i;
  }

  n0.l = reconstruct(in, pre, leftp0, p0 + 1, i0);
  n0.r = reconstruct(in, pre, rightp0, p0 + i0 + 1, in.size() - (i0 + 1));
  return p;
}

int main() {
  Node<int> *p;
  vector<int> pre = {2,0,-1,1,4,3,5};
  vector<int> in = {-1,0,1,2,3,4,5};
  p = reconstruct(in, pre, 0, 3, 7);
  
  return 0;
}
