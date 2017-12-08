/*
ID: jorlee
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int arrayMod(int n, int len)
{
  int ret = (n % len);
  return ret;
}

int countBeads(int len, char a[], int n) {
// Counting beads starting index n from array a[len]

  int counter = 0;

  if (a[n] == 'r') {
    while ((a[arrayMod(n+counter,len)] != 'b') && (counter < len))
      counter++;
  }
  else if (a[n] == 'b') {
    while ((a[arrayMod(n+counter, len)] != 'r') && (counter < len))
      counter++;
  }
  else if (a[n] == 'w') {
    while ((a[arrayMod(n+counter, len)] == 'w') && (counter < len))
      counter++;
    if (counter >= len) {
      return len;
    } else {
      counter += countBeads(len, a, arrayMod(n+counter, len));
    }
/*
    if (a[arrayMod(n+counter, len)] == 'r') {
      while (a[arrayMod(n+counter, len)] != 'b')
	counter++;
    }
    else if (a[arrayMod(n+counter, len)] == 'b') {
      while (a[arrayMod(n+counter, len)] != 'r')
	counter++;
    }
    else {
      cout << "Unknown array letter" << endl;
    }
*/
  }
  else {
    cout << "Unknown array letter" << endl;
  }
  return counter;
}

int main() {
  int length;
  char necklace[350];

  ofstream fout ("beads.out");
  ifstream fin ("beads.in");

  fin >> length;
  for (int i = 0; i < length; i++) {
    fin >> necklace[i];
  }//end for

  int nmax = 0;
  for (int i = 0; i < length; i++) {
    int n1 = countBeads(length, necklace, i);
    int n2 = countBeads(length, necklace, arrayMod(i+n1, length));
    int nsum = n1+n2;
    if (nsum > nmax) {
      nmax = nsum;
    }//end if
    cout << i << " " << n1 << " " << n2 << " " << nsum << endl;
 }//end for

  if (nmax > length) {
    nmax = length;
  }
  fout << nmax << endl;

}//end main

/*
int check(int len, char necklaceArray[], int n) {
  int counter = 0;
  
  if (necklaceArray[n] == 'r') {
    counter++;
    while (necklaceArray[ (n+counter)%len ] != 'b') {
      counter++;
      if (counter >= len) return len;
    }
    return counter;
  }//end if

  else if (necklaceArray[n] == 'b') {
    while (necklaceArray[ (n+counter)%len ] != 'a') {
	counter++;
      }//end while
      return counter;
    }//end else if

  else if (necklaceArray[n] == 'w') { //if the starting bead is white
    counter++;
    while (necklaceArray[ (n+counter)%len ] == 'w') {
      counter++;
    }//end while
    counter += check(len, necklaceArray, n+counter);
    return counter;
  }//end else if
  else {
    return -2;
    }//end else
    return -1;
}//end check

int checkCall(int len, char necklaceArray[], int n) {
  int check1 = check(len, necklaceArray, n);
  int check2 = check(len, necklaceArray, n+check1);
  return check1+check2;
}//end checkCall

int largestElement(int inputArray[], int len) {
  for (int i = 0; i < len; i ++) {
    if (inputArray[i] > inputArray[i+1]) {
      inputArray[i+1] = inputArray[i];
    }//end if
    else {}
  }//end for
  return inputArray[len-1];
}//end largestElement

int main() {
  int length;
  char necklace[350];

  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  fin >> length;
  for (int i = 0; i < length; i++) {
    fin >> necklace[i];
  }//end for

  int output[length];
  for (int i = 0; i < length; i ++) {
    output[i] = checkCall(length, necklace, i);
    fout << output[i] << "\n";
  }//end for
  fout << largestElement(output, length) << "\n";
}//end main
*/
