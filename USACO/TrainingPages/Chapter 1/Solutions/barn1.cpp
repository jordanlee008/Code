/*
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, s, c;
    fin >> m >> s >> c;

    // Read stall indices:
    int a[c];
    for (int i = 0; i < c; i++) {
      int snum;
      fin >> snum;
      a[i] = snum;
    }
    // Make sure stall indices are in ascending order:
    sort(a, a+c);

    // Total length of a single board:
    int tot = a[c-1]-a[0]+1;

    // Compute gaps between stalls:
    int da[c-1];
    for (int i = 0; i < c-1; i++) {
      da[i] = a[i+1]-a[i]-1;
    }
    // Reverse sort gaps:
    sort(da, da+c-1, std::greater<int>());
    // Greedily cut boards at largest gaps to reduce total length:
    if (m > c) m = c;
    for (int i = 0; i < m-1; i++) {
      tot -= da[i];
    }
    fout << tot << endl;
    
    return 0;
}
