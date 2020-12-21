#include "common.hpp"

template<typename T = int>
class BIT {
  const T zero = 0;

  int n;
  int N;
  V<T> bit;
  int calcN(int x) {
    int k = 1 << (31 - __builtin_clz(x));
    return k == x ? k : k << 1;
  }


public:
  BIT(int n): n(n), N(calcN(n)), bit(N + 1, zero) {}

  void add(int i, T x) {
    i++;
    while(i <= N) {
      bit[i] = bit[i] + x;
      i += i & -i;
    }
  }

  /**
   * [l, r)
   */
  T query(int l, int r) {
    return sumUntil(r) - sumUntil(l);
  }

  T get(int i) {
    return sumUntil(i + 1) - sumUntil(i);
  }

  T sumUntil(int i) {
    T ans = zero;
    while(i > 0) {
      ans += bit[i];
      i -= i & -i;
    }
    return ans;
  }

  int lower_bound(T x) {
    int k = N;
    int res = 0;
    while(k > 0) {
      if (res + k <= N && bit[res + k] < x) {
        x -= bit[res + k];
        res += k;
      }
      k /= 2;
    }
    return res;
  }
};