#include "common.hpp"

V<V<ll>> mat_mul(V<V<ll>> a, V<V<ll>> b, int m) {
  assert(a[0].size() == b.size());
  ll th = (ll)7e18;
  int r = (int)a.size();
  int c = (int)b[0].size();
  int len = (int)a[0].size();
  V<V<ll>> res(a.size(), V<ll>(b[0].size()));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      ll v = 0ll;
      for (int k = 0; k < len; ++k) {
        v += a[i][k] * b[k][j];
        if (v > th) v %= m;
      }
      res[i][j] = v >= m ? v % m : v;
    }
  }
  return res;
}

V<V<ll>> mat_pow(V<V<ll>> a, ll n, int m) {
  if (n == 1) return a;
  V<V<ll>> res = mat_pow(mat_mul(a, a, m), n / 2, m);
  if (n % 2 == 1)
    return mat_mul(res, a, m);
  else
    return res;
}