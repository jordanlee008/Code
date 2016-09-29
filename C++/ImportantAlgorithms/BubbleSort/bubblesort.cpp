#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> bubblesort(vector<int> a) {
  int na = a.size();

  bool flip = true;
  while (flip) {
    flip = false;
    for (int i = 0; i < na-1; i++) {
      if (a[i] > a[i+1]) {
	int temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
	flip = true;
      }
    }
  }

  return a;
}


int main(int argc, char **argv) {
  vector<int> a;

  for (int i = 1; i < argc; i++) {
    a.push_back(atoi(argv[i]));
  }

  vector<int> b = bubblesort(a);
  for (int i = 0; i < b.size(); i++) {
    printf("sort[%d] = %d\n", i, b[i]);
  }

  return 0;
}
