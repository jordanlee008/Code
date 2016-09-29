#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> mergesort(vector<int> a) {
  int na = a.size();
  if (na <= 1) {
    return a;
  }

  int n1, n2;
  n1 = na/2;
  n2 = na-n1;
  vector<int> a1(n1), a2(n2);
  for (int i = 0; i < n1; i++) {
    a1[i] = a[i];
  }
  for (int i = 0; i < n2; i++) {
    a2[i] = a[n1+i];
  }

  a1 = mergesort(a1);
  a2 = mergesort(a2);

  a.clear();
  int j1 = 0;
  int j2 = 0;
  while ((j1 < n1) || (j2 < n2)) {
    if ((j2 >= n2) ||
	((j1 < n1) && (a1[j1] < a2[j2]))) {
      a.push_back(a1[j1]);
      j1++;
    }
    else {
      a.push_back(a2[j2]);
      j2++;
    }
  }
  return a;
}


int main(int argc, char **argv) {
  vector<int> a;

  for (int i = 1; i < argc; i++) {
    a.push_back(atoi(argv[i]));
  }

  vector<int> b = mergesort(a);
  for (int i = 0; i < b.size(); i++) {
    printf("sort[%d] = %d\n", i, b[i]);
  }

  return 0;
}
