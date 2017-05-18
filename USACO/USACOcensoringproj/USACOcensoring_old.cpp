#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

/*
char S[1000000];
char T[100];
string s, t;
int nS, nT;


void censorLine() {
    freopen("Documents/C++/censor.in", "r", stdin);
    getline (cin, s);
    getline (cin, t);

    nS = s.size();
    nT = t.size();
    for (int x = 0; x < s.size(); x++) {
        S[x] = s[x];
    }
    printf("Read first string with %d characters.\n", nS);
    for (int y = 0; y < t.size(); y++) {
        T[y] = t[y];
    }
    printf("Read second string with %d characters.\n", nT);

}//end censorLine

int compare(int n) {
    if (n == 1) {
        for (int i = n; i < t.size(); i++) {
	T[i] = “”;
	}
    }
    else if (T[i] = S[n]) {
    compare(n-1);
    }//end if
    else {
        return 0;
    }
}//end censor
*/

int main() {
    //censorLine();
  std::string s, t;

    freopen("Documents/C++/censor.in", "r", stdin);
    getline (cin, s);
    getline (cin, t);

    std::string::size_type i;

    i = s.find(t);
    while (i != std::string::npos) {
        s.erase(i, t.length());
        i = s.find(t);
    }
    cout << s << endl;

/*
    char s1, t1;
    int nmatch = 0;
    for (int i = 0; i < nS; i++) {
        s1 = S[i];

//        printf("Processing char: %c: nmatch = %d\n", s1, nmatch);

        if (s1 == T[nmatch]) {
            nmatch++;
            if (nmatch == nT) nmatch = 0;
        }

        else {
            for (int j = 0; j < nmatch; j++) {
                printf("%c",T[j]);
            }
            nmatch = 0;

            if (s1 == T[0]) {
                nmatch = 1;
            }
            else {
                printf("%c", s1);
            }
        }

    }
    printf("\n");

    */

/*
    for (int n = 0; n < s.length(); n++ ) {
	compare(n);
    }//end for
*/


}//end main
