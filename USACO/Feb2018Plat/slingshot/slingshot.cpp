#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
  ifstream fin ("slingshot.in");
  ofstream fout ("slingshot.out");
  
  int n,m;
  fin >> n >> m;

  int max=32767;
  
  vector< vector<int> > s;
  vector< vector<int> > sf;
  vector< vector<int> > sb;
  for (int i = 0; i < n; i++) {
    int x0,y0,t0;
    fin >> x0 >> y0 >> t0;
    
    if (x0 > max) max = x0;
    if (y0 > max) max = y0;
    
    if (t0 < abs(y0-x0)) {
      s.push_back({x0,y0,t0});
      if (x0 < y0) sf.push_back({x0,y0,t0});
      else sb.push_back({x0,y0,t0});
    }
  }
  
  vector< vector<int> > p;
  for (int i = 0; i < m; i++) {
    int a0,b0;
    fin >> a0 >> b0;
    
    if (a0 > max) max = a0;
    if (b0 > max) max = b0;
    
    p.push_back({a0,b0});
  }

  
  vector< vector<int> > df(max,{});
  vector< vector<int> > db(max,{});
  
  for (int i = 0; i < sf.size(); i++) {
    for (int j = 0; j < abs(sf[i][1]-sf[i][0])-sf[i][2]; j++) {
      if (sf[i][0]+j < max) df[sf[i][0]+j].push_back(i);
      if (sf[i][0]-j > -1) df[sf[i][0]-j].push_back(i);
      if (sf[i][1]+j < max) df[sf[i][1]+j].push_back(i);
      if (sf[i][1]-j > -1) df[sf[i][1]-j].push_back(i);
    }
  }
  
  for (int i = 0; i < sb.size(); i++) {
    for (int j = 0; j < abs(sb[i][1]-sb[i][0])-sb[i][2]; j++) {
      if (sb[i][0]+j < max) db[sb[i][0]+j].push_back(i);
      if (sb[i][0]-j > -1) db[sb[i][0]-j].push_back(i);
      if (sb[i][1]+j < max) db[sb[i][1]+j].push_back(i);
      if (sb[i][1]-j > -1) db[sb[i][1]-j].push_back(i);
    }
  }
  
  for (int i = 0; i < m; i++) {
    int a0=p[i][0],b0=p[i][1];
    int t = abs(b0-a0);
    
    if (a0 < b0) {
      sort(df[a0].begin(),df[a0].end());
      for (int j = 0; j < df[a0].size(); j++) {
	int k = df[a0][j];
	int t0 = sf[k][2] + abs(sf[k][0]-a0) + abs(sf[k][1]-b0);
	if (t0 < t) t = t0;
      }
    }
    else {
      sort(db[a0].begin(),db[a0].end());
      for (int j = 0; j < db[a0].size(); j++) {
	int k = db[a0][j];
	int t0 = sb[k][2] + abs(sb[k][0]-a0) + abs(sb[k][1]-b0);
	cout << sb[k][0] << sb[k][1] << sb[k][2] << "\n";
	if (t0 < t) t = t0;
      }
    }
    fout << t << "\n";
  }
}
