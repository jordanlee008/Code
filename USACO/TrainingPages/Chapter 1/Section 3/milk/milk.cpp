/*
ID: jorlee
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main () {
  ifstream fin ("milk.in");
  ofstream fout ("milk.out");
  
  int nmilk, nfarmer;
  int finalprice = 0;
  fin >> nmilk >> nfarmer;
  int price[nfarmer];
  int stock[nfarmer];
  for (int i = 0; i < nfarmer; i++) {
    fin >> price[i] >> stock[i];
  }//end for
  
  for (int i = 1; i < nfarmer; i++) {
    int key = price[i];
    int stockkey = stock[i];
    int k = i - 1;
    while ((k >= 0) && (price[k] > key)) {
      price[k + 1] = price[k];
      stock[k + 1] = stock[k];
      k--;
    }//end while
    price[k + 1] = key;
    stock[k + 1] = stockkey;
  }//end for

  for (int i = 0; i < nfarmer; i++) {
    cout << price[i] << " " << stock[i] << endl;
  }//end for

  int farmercounter = 0;
  while (nmilk != 0) {
    if (stock[farmercounter] > nmilk) {
      finalprice = finalprice + price[farmercounter] * nmilk;
      nmilk = 0;
      farmercounter++;
    }//end if
    else {
      finalprice = finalprice + price[farmercounter] * stock[farmercounter];
      nmilk = nmilk - stock[farmercounter];
      farmercounter++;
    }//end else
  }//end while

  fout << finalprice << endl;
}//end main
