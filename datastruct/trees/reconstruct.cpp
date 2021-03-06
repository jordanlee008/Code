#include <iostream>
#include <vector>
#include "Node.hpp"

using namespace std;

template <class T>
Node<T>* reconstruct(const vector<T>& in, const vector<T>& pre, int i0, int p0, int n) {
  if (n == 0) return 0;
  Node<T> n0 (pre[p0]);
  Node<T>* p = &n0;
  if (n == 1) return p;

  int lefti0 = -1;
  for (int i = 0; i < i0; i++) {
    T n1 = in[i];
    if (n1 == pre[p0 + 1])
      lefti0 = i;
  }

  int righti0 = -1;
  for (int i = i0; i < in.size(); i++) {
    T n1 = in[i];
    if (n1 == pre[p0 + i0 + 1])
      righti0 = i;
  }

  n0.l = reconstruct(in, pre, lefti0, p0 + 1, i0);
  n0.r = reconstruct(in, pre, righti0, p0 + i0 + 1, in.size() - (i0 + 1));
  return p;
}

int main() {
  Node<int> *p;
  vector<int> pre;
  pre.push_back(2);
  pre.push_back(0);
  pre.push_back(-1);
  pre.push_back(1);
  pre.push_back(4);
  pre.push_back(3);
  pre.push_back(5);
  vector<int> in;
  in.push_back(-1);
  in.push_back(0);
  in.push_back(1);
  in.push_back(2);
  in.push_back(3);
  in.push_back(4);
  in.push_back(5);
  p = reconstruct(in, pre, 0, 3, 7);
  while(p) {
    cout << p;
    p = p->r;
  }
  
  return 0;
}
