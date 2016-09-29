#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace std;

int c, r;
int xstart, ystart;
int xfinal, yfinal;
vector< vector<int> > cost;

void searchneighbor(int x, int y, vector< vector<bool> > search, vector< vector<int> > path) {
  //look for neighbors given the searched-already matrix
  int xt, yt;
  
  //check left
  xt = x - 1;
  yt = y;
  if (!search[xt][yt]) {
    if (xt == xfinal && yt == yfinal) {
      printf("number of moves: %d", (int)path.size() + 1);
      for (int i = 0; i < path.size(); i++)
	printf("%d, %d\n", path[i][0], path[i][1]);
      printf("%d, %d\n", xfinal, yfinal);
    } else {
      vector< vector<bool> > tempsearch = search;
      tempsearch[xt][yt] = true;
      vector< vector<int> > temppath = path;
      vector<int> a;
      a.push_back(xt);
      a.push_back(yt);
      temppath.push_back(a);
      searchneighbor(xt, yt, tempsearch, temppath);
    }
  }

  //check right
  xt = x + 1;
  yt = y;
  if (!search[xt][yt]) {
    if (xt == xfinal && yt == yfinal) {
      printf("number of moves: %d", (int)path.size() + 1);
      for (int i = 0; i < path.size(); i++)
	printf("%d, %d\n", path[i][0], path[i][1]);
      printf("%d, %d\n", xfinal, yfinal);
    } else {
      vector< vector<bool> > tempsearch = search;
      tempsearch[xt][yt] = true;
      vector< vector<int> > temppath = path;
      vector<int> a;
      a.push_back(xt);
      a.push_back(yt);
      temppath.push_back(a);
      searchneighbor(xt, yt, tempsearch, temppath);
    }
  }

  //check down
  xt = x;
  yt = y + 1;
  if (!search[xt][yt]) {
    if (xt == xfinal && yt == yfinal) {
      printf("number of moves: %d", (int)path.size() + 1);
      for (int i = 0; i < path.size(); i++)
	printf("%d, %d\n", path[i][0], path[i][1]);
      printf("%d, %d\n", xfinal, yfinal);
    } else {
      vector< vector<bool> > tempsearch = search;
      tempsearch[xt][yt] = true;
      vector< vector<int> > temppath = path;
      vector<int> a;
      a.push_back(xt);
      a.push_back(yt);
      temppath.push_back(a);
      searchneighbor(xt, yt, tempsearch, temppath);
    }
  }

  //check up
  xt = x;
  yt = y - 1;
  if (!search[xt][yt]) {
    if (xt == xfinal && yt == yfinal) {
      printf("number of moves: %d", (int)path.size() + 1);
      for (int i = 0; i < path.size(); i++)
	printf("%d, %d\n", path[i][0], path[i][1]);
      printf("%d, %d\n", xfinal, yfinal);
    } else {
      vector< vector<bool> > tempsearch = search;
      tempsearch[xt][yt] = true;
      vector< vector<int> > temppath = path;
      vector<int> a;
      a.push_back(xt);
      a.push_back(yt);
      temppath.push_back(a);
      searchneighbor(xt, yt, tempsearch, temppath);
    }
  }
}

int main () {
  ifstream fin ("pathplan.in");
  ofstream fout ("pathplan.out");
  
  //get inputs
  fin >> c >> r;
  for (int i = 0; i < c; i++) {
    vector<int> a;
    cost.push_back(a);
    for (int j = 0; j < r; j++) {
      int b;
      fin >> b;
      cost[i].push_back(b);
    }
  }
  fin >> xstart >> ystart;
  fin >> xfinal >> yfinal;
  
  //display input
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++)
      cout << cost[i][j];
    cout << endl;
  }
  
  vector< vector<bool> > searched;
  searched.resize(c, vector<bool>(r, false));
  searched[xstart][ystart] = true;

  vector< vector<int> > path;
  vector<int> startpoint;
  startpoint.push_back(xstart);
  startpoint.push_back(ystart);
  path.push_back(startpoint);
  
  searchneighbor(xstart, ystart, searched, path);
}


/*PROBLEM:
you are trying to access outside of the boolean 2d vector telling you whether
you've visted there which is illegal
