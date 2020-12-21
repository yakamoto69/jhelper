#ifndef MInt_H

template <unsigned int MOD>
class MInt {
private:
  int v;

public:
  MInt() : v(0) {}

  MInt(long long x) {
    v = x % MOD;
    if (v < 0) v += MOD;
  }

  MInt& operator +=(const MInt &that) {
    v += that.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }

  MInt& operator -=(const MInt &that) {
    v -= that.v;
    if (v < 0) v += MOD;
    return *this;
  }

  MInt& operator *=(const MInt &that) {
    v = (long long)(v) * that.v % MOD;
    return *this;
  }

  MInt& operator ++(int) {
    *this += 1;
    return *this;
  }

  MInt& operator --(int) {
    *this -= 1;
    return *this;
  }

  friend MInt operator+(const MInt& a, const MInt& b) {
    return MInt(a) += b;
  }

  friend MInt operator-(const MInt& a, const MInt& b) {
    return MInt(a) -= b;
  }

  friend MInt operator*(const MInt& a, const MInt& b) {
    return MInt(a) *= b;
  }

  friend std::ostream& operator<<(std::ostream& out, const MInt<MOD> &a) {
    out << a.v;
    return out;
  }

  friend std::istream& operator>>(std::istream& in, const MInt<MOD> &a) {
    ll _v;
    in >> _v;
    a.v = 0;
    a += _v;
    return in;
  }
};

template<unsigned int MOD> void __print(MInt<MOD> x) {std::cerr << x;}

#define MInt_H

#endif //MInt_H