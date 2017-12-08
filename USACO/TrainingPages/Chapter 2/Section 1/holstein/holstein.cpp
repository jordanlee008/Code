/*
ID: jorlee
PROG: holstein
LANG: C++
*/

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int V, G;
//V: number of vitamins
//G: number of feeds
vector<int> vit;
//requirements of each vitamin
vector< vector<int> > feed;
//vitamins in each scoop of feed

int main () {
  fin >> V;
  for (int i = 0; i < V; i++) {
    int a;
    fin >> a;
    vit.push_back(a);
  }

  fin >> G;
  feed.reserve(G);
  for (int i = 0; i < G; i++) {
    for (int j = 0; j < V; j++) {
      int a;
      fin >> a;
      feed[i].push_back(a);
    }
  }
  
  
  return 0;
}
