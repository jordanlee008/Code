#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct cell{
    int val;
    int reg;
    bool border[4];
};

int r, c, cnt = 0;
string s;
int n, vals[100000];
int ydir[4] = {-1, 0, 1, 0};
int xdir[4] = {0, 1, 0, -1};
cell cells[100][100];
void flood(int i, int j, int l){
    if(cells[i][j].reg != -1) return;
    cells[i][j].reg = l;
    for(int k = 0; k < 4; k++){
        if(!cells[i][j].border[k]){
            flood(i + ydir[k], j + xdir[k], l);
        }
    }
}

int main(){
  
  for(int iter = 0; iter < 2; iter++){
  //freopen("capsules.in", "r", stdin);
    cin >> r >> c >> s >> n;
    for(int i = 0; i < r; i++){
      for(int j = 0; j < c; j++){
	cells[i][j].val = -1;
	cells[i][j].reg = -1;
      }
    }
    for(int i = 0; i < s.size(); i++){  //get borders
        int x = s[i];
        if(x >= 'A'){
            x -= 'A';
            x += 10;
        }
        cells[i / c][i % c].reg = -1;
        cells[i / c][i % c].val = -1;
        for(int j = 0; j < 4; j++){
	  cells[r - (i / c) - 1][i % c].border[3 - j] = x % 2;
            x /= 2;
        }
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cells[r - a / 100][(a % 100) / 10 - 1].val = a % 10;
    }
    for(int i = 0; i < r; i++){ //get regions
        for(int j = 0; j < c; j++){
            if(cells[i][j].reg == -1){
                flood(i, j, cnt++);
            }
        }
    }
    /*for(int i = 0; i < r; i++){ //get regions
        for(int j = 0; j < c; j++){
            cout << cells[i][j].reg << " ";
        }
        cout << "\n";
    }*/
   // cout << cnt;
    bool original[cnt];
    for(int i = 0; i < cnt; i++){
        original[i] = false;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(cells[i][j].val != -1){
                original[cells[i][j].reg] = true;
            }
        }
    }
    int numoriginal = 0, numintersect = 0;
    for(int i = 0; i < cnt; i++){
        if(!original[i]) numoriginal++;
    }
    for(int i = 0; i < r - 1; i++){ //check intersections
        for(int j = 0; j < c - 1; j++){
            if(!cells[i][j].border[1] && !cells[i][j].border[2] && !cells[i + 1][j + 1].border[0] && !cells[i + 1][j + 1].border[3])
                numintersect++;
        }
    }
    cout << numintersect << "\n" << cnt << "\n" << numoriginal << "\n";
    cout << r + c << "\n" << r + c << "\n";
    }
}
