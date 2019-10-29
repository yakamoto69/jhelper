#include "common.hpp"

class Comb {
public:
  int MOD;
  V<ll> F, I;

  Comb(int N, int MOD): MOD(MOD), F(N + 1), I(N + 1) {
    F[0] = 1;
    for (int i = 1; i <= N; ++i) {
      F[i] = F[i - 1] * i % MOD;
    }

    I[N] = pow_mod(F[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; --i) {
      I[i] = I[i + 1] * (i + 1) % MOD;
    }
  }

  static ll pow_mod(ll x, int k, int MOD) {
    ll res = k >= 2 ? pow_mod(x * x % MOD, k / 2, MOD) : 1ll;
    if (k&1) res = res * x % MOD;
    return res;
  };

  ll operator()(int n, int k) {
    if (k < 0 || k > n) return 0ll;
    return F[n] * I[n - k] % MOD * I[k] % MOD;
  };

  ll rev(int x) {
    return F[x - 1] * I[x] % MOD;
  }
};