#include "mod.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;

Mod::Mod(long t) {
  while (t >= modulus)
    t -= modulus;
  while (t < 0)
    t += modulus;
  x = t;
}

Mod::Mod(const Mod& m) {
  x = m.val();
}

Mod& Mod::operator=(const Mod& m) {
  x = m.val();
  return *this;
}

Mod& Mod::operator+=(const Mod& m) {
  x += m.val();
  if (x >= modulus)
    x -= modulus;
  return *this;
}

Mod& Mod::operator-=(const Mod& m) {
  x -= m.val();
  if (x < 0)
    x += modulus;
  return *this;
}

Mod& Mod::operator*=(const Mod& m) {
  long ml = m.val(), xl = x;
  while (ml > 1) {
    if (ml % 2)
      xl += x;
    ml /= 2;
    Mod xm(xl);
    xm += xm;
    xl = xm.val();
  }
  x = xl;
  return *this;
}

Mod& Mod::operator/=(const Mod& m) {
  
}

Mod Mod::operator-() const {
  Mod o(0 - modulus);
  return o;
}

Mod Mod::pwr(long e) const {
  
}

long Mod::val() const {
  return x;
}
  
static void Mod::set_modulus(long m) {
  if (m < 1)
    cerr << "invalid modulus\n";
  modulus = m;
}

static long Mod::get_modulus() {
  return modulus;
}

static Mod Mod::inv(long r0) {
  
}

Mod operator+(const Mod& a, const Mod& b) {
  long al = a.val(), bl = b.val();
  if (a.val() > Mod::get_modulus() / 2)
    al = a.val() - Mod::get_modulus();
  if (b.val() > Mod::get_modulus() / 2)
    bl = b.val() - Mod::get_modulus();
  Mod m(al + bl);
  return m;
}

Mod operator+(long t, const Mod& m) {
  Mod n(t);
  return n + m;
}

Mod operator-(const Mod& a, const Mod& b) {
  long al = a, bl = b;
  if (a.val() < 0 - Mod::get_modulus() / 2)
    al = a.val() + Mod::get_modulus();
  if (b.val() < 0 - Mod::get_modulus() / 2)
    bl = b.val() + Mod::get_modulus();
  Mod m(al - bl);
  return m;
}

Mod operator-(long t, const Mod& m) {
  Mod n(t);
  return n - m;
}

Mod operator*(const Mod& a, const Mod& b) {
  Mod m = 0;
  long al = a.val(), bl = b.val();
  while (b) {
    if (al > Mod::get_modulus() / 2)
      al -= Mod::get_modulus;
    if (b % 2)
      al += al;
    b /= 2;
    a *= 2;
  }
}

Mod operator*(long t, const Mod& m) {
 
}

Mod operator/(const Mod& a, const Mod& b) {
  
}

Mod operator/(long t, const Mod& m) {
  
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
  in >> t;
  m = Mod(t);
  return is;
}

ostream& operator<<(ostream& os, const Mod& m) {
  os << m.val();
  return os;
}
