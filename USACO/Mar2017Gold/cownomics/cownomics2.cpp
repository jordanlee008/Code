#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string scow[500];
string pcow[500];
int length;

int convert(string s) {
  vector<int> v;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') v.push_back(0);
    if (s[i] == 'T') v.push_back(1);
    if (s[i] == 'C') v.push_back(2);
    if (s[i] == 'G') v.push_back(3);
  }
  int x = 1, res = 0;
  for (int i = 0; i < v.size(); i++) {
    res += x * v[i];
    x *= 4;
  }
  return res;
}

int binarysearch(vector<int> vec, int val, int lo, int hi) {
  if (lo > hi)
    return -1;
  int mid = (lo + hi) / 2;
  if (vec[mid] == val)
    return mid;
  else if (vec[mid] < val)
    return binarysearch(vec, val, mid + 1, hi);
  else
    return binarysearch(vec, val, lo, mid - 1);
}

int main() {
  ifstream fin ("cownomics.in");
  ofstream fout ("cownomics.out");
  
  fin >> N >> M;
  for (int i = 0; i < N; i++) fin >> scow[i];
  for (int i = 0; i < N; i++) fin >> pcow[i];
  //  for (int i = 0; i < N; i++) printf("%d\t%s\t%s\n", i, scow[i].c_str(), pcow[i].c_str());

  length = M;
  
  int finallength = M;

  while (length >= 0) {
    //    printf("length: %d\n", length);
    for (int start = 0; start < M - length + 1; start++) {
      bool found = true;
      vector<int> spot;
      for (int i = 0; i < N; i++) {
	spot.push_back(convert(scow[i].substr(start, length)));
      }
      
      sort(spot.begin(), spot.end());
      
      for (int i = 0; i < N; i++) {
	if (binarysearch(spot, convert(pcow[i].substr(start, length)), 0, N - 1) != -1) {
	  found = false;
	  break;
	}
      }
      if (found) {
	printf("found: %d, %d\n", length, start);
	finallength = min(length, finallength);
      }
    }
    length--;
  }
  
  fout << finallength << "\n";
  cout << finallength << "\n";

}
