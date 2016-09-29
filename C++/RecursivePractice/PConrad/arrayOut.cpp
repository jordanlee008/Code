#include <iostream>
#include <fstream>

using namespace std;

void output (int array[], int l) {
  bool run = false;
  for (int i = 0; i < l - 1; i++)
    if (array[i] != array[i + 1])
      run = true;
  
  if (run) {
    cout << array[0];
    for (int i = 0; i < l; i++)
      array[i] = array[i + 1];
    output(array, l);
  }
}

int main () {
  cout << "How many elements: ";
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)
    cin >> array[i];
  output(array, n);
}
