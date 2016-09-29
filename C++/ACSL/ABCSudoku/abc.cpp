#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int grid[4][4], N, a;

pair<int, int> d(int x){
    x--;
    return {x / 6, x % 6};
}

void cycle(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(grid[i][j] != -1) continue;
            bool works[4] = {1, 1, 1, 1};
            for(int n = 0; n < 4; n++){
                if(grid[i][n] == -1) continue;
                works[grid[i][n]] = false;
            }
            for(int n = 0; n < 4; n++){
                if(grid[n][j] == -1) continue;
                works[grid[n][j]] = false;
            }
            int s = works[1] + works[2] + works[3];
            if(s != 1) continue;
            for(int n = 1; n < 4; n++) if(works[n]) grid[i][j] = n;
        }
    }
}

int main(){
    freopen("abc.in", "r", stdin);
    for(int k = 0; k < 5; k++){
        memset(grid, -1, sizeof grid);
        for(int i = 0; i < 4; i++){
            cin >> a;
            grid[d(a).first - 1][d(a).second - 1] = 0;
        }
        cin >> N;
        for(int i = 0; i < N; i++){
            char c;
            cin >> c >> a;
            c -= 'A' - 1;
            if(d(a).first == 0)
                if(grid[0][d(a).second - 1] != 0) grid[0][d(a).second - 1] = c;
                    else grid[1][d(a).second - 1] = c;
            if(d(a).first == 5)
                if(grid[3][d(a).second - 1] != 0) grid[3][d(a).second - 1] = c;
                    else grid[2][d(a).second - 1] = c;
            if(d(a).second == 0)
                if(grid[d(a).first - 1][0] != 0) grid[d(a).first - 1][0] = c;
                    else grid[d(a).first - 1][1] = c;
            if(d(a).second == 5)
                if(grid[d(a).first - 1][3] != 0) grid[d(a).first - 1][3] = c;
                    else grid[d(a).first - 1][2] = c;
        }
        for(int i = 0; i < 100; i++) cycle();
        cin >> N;
        cout << (char)(grid[d(N).first - 1][d(N).second - 1] + 'A' - 1) << "\n";
    }
}
