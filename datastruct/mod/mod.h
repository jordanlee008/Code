#ifndef ___Mod__
#define ___Mod__
#include <iostream>
#include <cassert>
#include <math.h>

class Mod {
 public:
  Mod(long t); // done
  Mod(const Mod& m); // done
  
  Mod& operator=(const Mod& m); // done
  Mod& operator+=(const Mod& m); // done
  Mod& operator-=(const Mod& m); // done
  Mod& operator*=(const Mod& m); // done
  Mod& operator/=(const Mod& m);

  Mod operator-() const; // done
  Mod pwr(long e) const; // done
  long val() const; // done

  static void set_modulus(long m); // done
  static long get_modulus(); // done

 private:
  long x;
  static long modulus;
  static Mod inv(long r0); // done
};

Mod operator+(const Mod& a, const Mod& b); // done
Mod operator+(long t, const Mod& m); // done
Mod operator-(const Mod& a, const Mod& b); // done
Mod operator-(long t, const Mod& m); // done
Mod operator*(const Mod& a, const Mod& b); // done
Mod operator*(long t, const Mod& m); // done
Mod operator/(const Mod& a, const Mod& b);
Mod operator/(long t, const Mod& m);
bool operator==(const Mod& a, const Mod& b); // done
bool operator==(long t, const Mod& m); // done
bool operator!=(const Mod& a, const Mod& b); // done
bool operator!=(long t, const Mod& m); // done

std::istream& operator>>(std::istream& is, Mod& m); // done
std::ostream& operator<<(std::ostream& os, const Mod& m); // done

long Mod::modulus = 17;

#endif
