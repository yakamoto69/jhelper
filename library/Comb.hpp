#include "MInt.hpp"

template<unsigned int MOD>
class Comb {
  using mint = MInt<MOD>;

public:
  V<mint> F, I;

  Comb(int N) : F(N + 1), I(N + 1) {
    F[0] = 1;
    for (int i = 1; i <= N; ++i) {
      F[i] = F[i - 1] * i;
    }

    I[N] = pow_mod(F[N], MOD - 2);
    for (int i = N - 1; i >= 0; --i) {
      I[i] = I[i + 1] * (i + 1);
    }
  }

  static mint pow_mod(mint x, int k) {
    mint res = k >= 2 ? pow_mod(x * x, k / 2) : 1;
    if (k&1) res *= x;
    return res;
  };

  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return F[n] * I[n - k] * I[k];
  };

  mint rev(int x) {
    return F[x - 1] * I[x];
  }
};