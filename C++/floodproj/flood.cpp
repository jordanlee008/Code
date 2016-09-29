#include <iostream>
#include <cstdio>

using namespace std;

int h,w;
char field[100][100];


int main() {
    freopen("Documents/C++/flood.in", "r", stdin);
    cin >> h;
    cin >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> field[i][j];
        }//end for
    }//end for
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << field[i][j];
        }//end for
        cout << "\n";
    }//end for
    cout << h << w;

}//end main
