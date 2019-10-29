#include "common.hpp"

int msb(int i) {
  i |= (i >>  1);
  i |= (i >>  2);
  i |= (i >>  4);
  i |= (i >>  8);
  i |= (i >> 16);
  return i - (((unsigned int)i) >> 1);
}

int log2(int x) {
  int i = 0;
  while(x >>= 1) i++;
  return i;
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

VI divisors(int x) {
  VI D, back;
  int rt = (int)sqrt(x);
  for (int d = 1; d <= rt; ++d) {
    if (x % d == 0) {
      D.push_back(d);
      if (d * d != x) back.push_back(x / d);
    }
  }
  D.insert(D.end(), back.rbegin(), back.rend());
  return D;
}

ll pow_mod(ll x, int k, ll m) {
  if (k == 0) return 0;
  else if (k == 1) return x;
  else {
    ll a = pow_mod(x * x % m, k / 2, m);
    if (k % 2 == 1) a = a * x % m;
    return a;
  }
}

//inline void add(ll &a, ll b) {
//  a += b;
//  if (a >= MOD) a -= MOD;
//}
//
//inline void sub(ll &a, ll b) {
//  a += MOD - b;
//  if (a >= MOD) a -= MOD;
//}
//
//inline void mul(ll &a, ll b) {
//  a = a * b % MOD;
//}