#include "common.hpp"
#include "MInt.hpp"

template <unsigned int MOD>
V<V<MInt<MOD>>> matMul(V<V<MInt<MOD>>> const &a, V<V<MInt<MOD>>> const &b) {
  assert(a[0].size() == b.size());
  auto r = a.size();
  auto c = b[0].size();
  auto len = a[0].size();
  auto res = dim2(r, c, MInt<MOD>(0));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int k = 0; k < len; ++k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

template <unsigned int MOD>
V<V<MInt<MOD>>> I(int n) {
  auto res = dim2(n, n, MInt<MOD>(0));
  for (int i = 0; i < n; ++i) {
    res[i][i] = 1;
  }
  return res;
}

template <unsigned int MOD>
V<V<MInt<MOD>>> matPow(V<V<MInt<MOD>>> const &a, ll n) {
  if (n == 0) return I<MOD>(a.size());
  if (n == 1) return a;
  auto res = matPow(matMul(a, a), n / 2);
  if (n % 2 == 1)
    return matMul(res, a);
  else
    return res;
}