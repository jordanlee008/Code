/*
ID: jorlee
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int l, si = 0;
vector<int> indices (1);
vector<int> solution (4);

/*
int lfind (int n) {
  int count;
  while (n != 0) {
    count++;
    n = n / 10;
  }
  return count;
}
*/

/*
bool lcheck (int n, int l) {
  int count;
  while (n != 0) {
    count++;
    n = n / 10;
  }
  if (count == l)
    return true;
  return false;
}
*/

bool isp (int n) {
  if (n == 2)
    return true;
  else if (n % 2 == 0)
    return false;
  for (int i = 3; i*i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

vector<int> nextdig (int n) {
  //try all possible 10 digits added to n
  //if it is prime, add to vector
  vector<int> a;
  for (int i = 0; i < 10; i++) {
    int x = 10 * n + i;
    if (isp(x))
      a.push_back(x);
  }
  return a;
}

int main (void) {
  ifstream fin ("sprime.in");
  ofstream fout ("sprime.out");
  fin >> l;
  cout << "l: " << l << endl;

  //implementation of bfs
  solution[0] = 2;
  solution[1] = 3;
  solution[2] = 5;
  solution[3] = 7;
  indices[0] = 4;
  while (indices.size() < 8) {
    int c0 = solution[si];
    cout << "checking c0 = " << c0 << endl;
    if (indices[indices.size() - 1] == si)
      indices.push_back(solution.size());
    
    vector<int> next = nextdig(c0);
    for (int i = 0; i < next.size(); i++) {
      solution.push_back(next[i]);
      cout << "next[" << i << "] = " << next[i] << endl;
    }
    si++;
  }

  for (int i = indices[l - 2]; i < indices[l - 1]; i++)
    fout << solution[i] << endl;

  return 0; 
}
