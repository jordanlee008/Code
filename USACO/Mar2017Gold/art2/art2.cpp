#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N;
vector<int> p; // input the painting
vector< vector<int> > col; // start and end point
//vector<int> color; // which colors are actually used
//vector< vector<int> > kid; // what paint lies on top of you


/*int binarysearch(int c, int lo, int hi) {
  if (lo > hi) return -1;
  int mid = (lo + hi) / 2;
  if (color[mid] == c)
    return mid;
  else if (color[mid] < c)
    return binarysearch(c, mid + 1, hi);
  else
    return binarysearch(c, lo, mid - 1);
}*/

int main() {
  ifstream fin ("art2.in");
  ofstream fout ("art2.out");
  
  fin >> N;

  vector<int> e;
  e.push_back(0);
  e.push_back(0);
  
  //  vector<int> k;
  //  kid.push_back(k);
  col.push_back(e);
  
  for (int i = 0; i < N; i++) {
    int c;
    fin >> c;
    p.push_back(c);
    col.push_back(e);
    //    kid.push_back(k);
  }
  
  for (int i = 0; i < N; i++) {
    col[p[i]][1] = i;
    if (i != 0 && col[p[i]][0] == 0 && p[0] != p[i]) col[p[i]][0] = i;
    
    //    if (binarysearch(p[i], 0, color.size() - 1) == -1) color.push_back(p[i]);
    //    sort(color.begin(), color.end());
    //    cout << i << " ";
  }


  
  //  for (int i = 0; i < N; i++) printf("%d\t%d\t%d\n", i, col[i][0], col[i][1]);
  
  
  deque<int> seen;
  int l = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] == 0 && seen.size() == 0) continue;
    if (p[i] == 0 && seen.size() > 0) {
      fout << "-1" << endl;
      cout << "WHAT\n";
      exit(0);
    }
    
    int open = col[p[i]][0] == i;
    //    if (col[p[i]][0] == i) open = 1;
    int close = col[p[i]][1] == i;
    //    if (col[p[i]][1] == i) close = 1;
    
    //    if (seen.back() != p[i]) kid[seen.back()].push_back(p[i]);
    
    if (open && !close) {
      seen.push_back(p[i]);
      if (seen.size() > l) l = seen.size();
    }
    
    if (!open && close) {
      if (seen.back() != p[i]) {
	fout << "-1" << endl;
	cout << "WHAT\n";
	exit(0);
      }
      else if (seen.size() > 0) seen.pop_back();
      else if (seen.size() == 0) {
	fout << "-1" << endl;
	cout << "WHAT\n";
	exit(0);
      }
    }
    
    if (open && close) {
      if (seen.size() + 1 > l) l = seen.size() + 1;
    }

    /*cout << i << " ";
    for (int i = 0; i < seen.size(); i++) printf("%d\t", seen[i]);
    cout << "\n";*/
  }

  
  /*  for (int i : color) {
    cout << i << " ";
    for (int j : color) {
      if (kid[i][j]) cout << j << " ";
    }
    cout << "\n";
  }*/
  
  cout << "layers " << l << "\n";
  fout << l << "\n";
}
