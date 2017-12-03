#include "mod.h"

using namespace std;

Mod::Mod(long t) {
  while (t < 0) t += modulus;
  x = t % modulus;
}

Mod::Mod(const Mod& m) {
  x = m.val();
}

Mod& Mod::operator=(const Mod& m) {
  x = m.val();
  return *this;
}

Mod& Mod::operator+=(const Mod& m) {
  x -= modulus;
  x += m.val();
  if (x < 0) x += modulus;
  return *this;
}

Mod& Mod::operator-=(const Mod& m) {
  x -= m.val();
  if (x < 0) x += modulus;
  return *this;
}

Mod& Mod::operator*=(const Mod& m) {
  Mod a = 0, b = x;
  long c = m.val();
  while (c > 0) {
    if (c % 2) a += b;
    b += b;
    c /= 2;
  }
  x = a.val();
  return *this;
}

Mod& Mod::operator/=(const Mod& m) {
  long mx = m.val();
  Mod minv = inv(mx);
  minv = x * minv;
  x = minv.val();
  return *this;
}

Mod Mod::operator-() const {
  Mod o(0 - x);
  return o;
}

Mod Mod::pwr(long e) const {
  Mod m(x);
  while (e > 1) {
    m *= m;
    if (e % 2)
      m = m * x;
    e /= 2;
  }
  return m;
}

long Mod::val() const {
  return x;
}

void Mod::set_modulus(long m) {
  if (m < 2)
    cerr << "invalid modulus\n";
  modulus = m;
}

long Mod::get_modulus() {
  return modulus;
}

Mod Mod::inv(long r0) {
  long m = modulus, t, q;
  long x0 = 0, x1 = 1; 

  while (r0 > 1) {
    q = r0 / m; // set q

    // update from equation r0 = q * m + r
    // to m = qnew * r + rnew
    t = m;
    m = r0 % m;
    r0 = t;
    
    // update x0 to x1 - q * x0
    // update x1 to old x0
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  Mod res(x1);
  return res;
}

Mod operator+(const Mod& a, const Mod& b) {
  Mod c(a);
  c += b;
  return c;
}

Mod operator+(long t, const Mod& m) {
  Mod n(t);
  return n + m;
}

Mod operator-(const Mod& a, const Mod& b) {
  Mod c(a);
  c -= b;
  return c;
}

Mod operator-(long t, const Mod& m) {
  Mod n(t);
  return n - m;
}

Mod operator*(const Mod& a, const Mod& b) {
  Mod c(a);
  c *= b;
  return c;
}

Mod operator*(long t, const Mod& m) {
  Mod n(t);
  n *= m;
  return n;
}

Mod operator/(const Mod& a, const Mod& b) {
  Mod c(a);
  c /= b;
  return c;
}

Mod operator/(long t, const Mod& m) {
  Mod n(t);
  n /= m;
  return n;
}

bool operator==(const Mod& a, const Mod& b) {
  return a.val() == b.val();
}

bool operator==(long t, const Mod& m) {
  Mod n(t);
  return n == m;
}

bool operator!=(const Mod& a, const Mod& b) {
  return a.val() != b.val();
}

bool operator!=(long t, const Mod& m) {
  Mod n(t);
  return n != m;
}

istream& operator>>(istream& is, Mod& m) {
  long t;
  is >> t;
  m = Mod(t);
  return is;
}

ostream& operator<<(ostream& os, const Mod& m) {
  os << m.val();
  return os;
}
