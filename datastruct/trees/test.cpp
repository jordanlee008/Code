#include <iostream>
#include <vector>

using namespace std;

template <class T>
class vect {
public:
  vect(int n) : size(n) {
    ptr = new T[n];
  }
  ~vect() { delete []ptr; }
  T operator[](const int& i) {
    return ptr[i];
  }
  void set(const int& i, const T& v) {
    ptr[i] = v;
  }
private:
  int size;
  T* ptr;
};

int main() {    
  vect<int> a(10);
  a.set(0, 90);
  a.set(5, 50);
  cout << a[0] << a[5];
  return 0;
}
